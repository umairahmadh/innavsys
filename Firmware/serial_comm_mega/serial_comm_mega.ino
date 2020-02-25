#include <AccelStepper.h>
#include <MultiStepper.h>
#include <ArduinoJson.h>


//Stepper motor configuration and object creation
//pul, dir
//3,2
//6,5
AccelStepper stepper1(AccelStepper::FULL2WIRE, 6, 5);
AccelStepper stepper2(AccelStepper::FULL2WIRE, 8, 7);
MultiStepper steppers;

int attempt = 1;  //attempt of obsacle scanning.
int stepCount = 0;
int stepRight = 0;
int stepLeft = 0;
const int obstacleAlertPin = 4;
bool alreadyWaited = 0;



void generateReplyMessage(int cmd, float x, float y, int angle) {
  delay(10);
  DynamicJsonDocument  doc(200);
  //cmd=1 : Regeneration request
  //cmd=0 : Navigation completed
  doc["cmd"] = cmd;
  doc["x"] = x;
  doc["y"] = y;
  doc["deg"] = angle;
  Serial.println(serializeJson(doc, Serial2));
  // Serial2.println(serializeJson(doc, Serial));
  //return serializeJson(doc, Serial);
}





//LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int num_of_data;





void receiveCommand() {
  // Serial.println("Going to read");
  String buff;
  if (Serial2.available()) {
    buff = Serial2.readString();
    //Serial2.println("Hi How are you?");
    //Serial.println("got something here");
    Serial.println(buff);

    data2arrays(buff);
  }
  //  Serial2.println("I received the following from you");
  // Serial2.println(buff);
}

void pathRegenerateRequest(float x, float y, int deg) {
  generateReplyMessage(1, x, y, deg);
  receiveCommand();
}

int stepperPosition(int rightStep, int leftStep) {
  long positions[2];
  positions[0] = -rightStep;  //negate the movement direction
  positions[1] = -leftStep; //negate the movement direction
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
}

int stepCountCalc(int type, int value) {
  if (type == 0) { //Straight Movement to centimeters
    stepCount = round((value + 0.1 * value) * 360 * 8 / (1.8 * 1.8 * 6));

  }
  else if (type == 1) { //Rotation to Angle

    stepCount = round((12975 / 180) * value);
  }

  return stepCount;
}





void data2arrays(String pld4mnivi) {
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, pld4mnivi);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  num_of_data = doc["num"];
  int angle_data[num_of_data];
  int dis_data[num_of_data];

  for (int i = 0; i < num_of_data; i++) {

    angle_data[i] = doc["angle"][i];
    dis_data[i] = doc["distance"][i];
  }


  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);


  Navigate(angle_data, dis_data);

}




void Navigate(int angle_ar[], int dis_ar[]) {
  float Xdistance = 0;  //mur
  float Ydistance = 0;  //mur
  int FAngle = 0;  //mur
  for (int j = 0; j < num_of_data; j++) {
    int type, value;
    type = 0;
    value = 0;

    //rotating angle has no issue
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    type = 1;
    stepRight = stepCountCalc(type, angle_ar[j]);
    stepLeft = -stepRight;
    stepperPosition(stepRight, stepLeft);
    delay(1000);


    //go straight only if there is no obstacle

    //going straight need t be sliced
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    type = 0;    //straight mode is on

    int slice_length = 15; // dliving to this distance
    int numberOfSlices = dis_ar[j] / slice_length; //going straight in slices this number of time
    int remainingSliceLength = dis_ar[j] % slice_length; //going straight for the remaining


    if (dis_ar[j] > slice_length) {
      for (int slice_loop = 0; slice_loop < numberOfSlices; slice_loop++) { //going straight in slices this number of time
        alreadyWaited = 0;
        while ( digitalRead(obstacleAlertPin) == HIGH && alreadyWaited == 0 ) {
          delay(3000);
          alreadyWaited = 1;
        }

        if (digitalRead(obstacleAlertPin) == HIGH) {
          for (int angle_index = j; angle_index >= 0; angle_index--) {  //mur
            FAngle += angle_ar[angle_index];
          }
          //pathRegenerateRequest();
          pathRegenerateRequest(round(Xdistance), round(Ydistance), FAngle % 360);
        }

        else {

          stepper1.setCurrentPosition(0);
          stepper2.setCurrentPosition(0);
          stepRight = stepCountCalc(type, slice_length);
          stepLeft = stepRight;
          stepperPosition(-stepRight, -stepLeft);

          Xdistance += slice_length * sin(angle_ar[j] * PI / 180); //mur
          Ydistance += slice_length * cos(angle_ar[j] * PI / 180); //mur
          // delay(100);   //for debugging
        }

      }
      //going straight for the remaining
      if (remainingSliceLength != 0) {
        alreadyWaited = 0;

        while ( digitalRead(obstacleAlertPin) && alreadyWaited == 0 ) {

          delay(3000);
          alreadyWaited = 1;
        }

        if (digitalRead(obstacleAlertPin)) {
          for (int angle_index = j; angle_index >= 0; angle_index--) {  //mur
            FAngle += angle_ar[angle_index];
          }
          pathRegenerateRequest(round(Xdistance), round(Ydistance), FAngle % 360);  //mur
        }

        else {

          stepper1.setCurrentPosition(0);
          stepper2.setCurrentPosition(0);
          stepRight = stepCountCalc(type, remainingSliceLength);
          stepLeft = stepRight;
          stepperPosition(-stepRight, -stepLeft);
          Xdistance += remainingSliceLength * sin(angle_ar[j] * PI / 180); //mur
          Ydistance += remainingSliceLength * cos(angle_ar[j] * PI / 180); //mur
          // delay(100);   //for debugging

        }
      }
    }

    else {

      alreadyWaited = 0;
      while ( digitalRead(obstacleAlertPin) == HIGH && alreadyWaited == 0 ) {
        delay(3000);
        alreadyWaited = 1;
      }

      if (digitalRead(obstacleAlertPin) == HIGH) {
        for (int angle_index = j; angle_index >= 0; angle_index--) {  //mur
          FAngle += angle_ar[angle_index];
        }
        pathRegenerateRequest(round(Xdistance), round(Ydistance), FAngle % 360);  //mur

      }

      else {
        stepper1.setCurrentPosition(0);
        stepper2.setCurrentPosition(0);
        stepRight = stepCountCalc(type, dis_ar[j]);
        stepLeft = stepRight;
        stepperPosition(-stepRight, -stepLeft);

        Xdistance += dis_ar[j] * sin(angle_ar[j] * PI / 180); //mur
        Ydistance += dis_ar[j] * cos(angle_ar[j] * PI / 180); //mur
      }
    }
  }
  generateReplyMessage(0, 0, 0, 0);
  receiveCommand();
}






void setup()
{
  //  lcd.init();                      // initialize the lcd
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(obstacleAlertPin, INPUT);
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
}


void loop()
{
  // read from port 1, send to port 0:
  /*if (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
    }*/

  // read from port 0, send to port 1:
  receiveCommand();
}
