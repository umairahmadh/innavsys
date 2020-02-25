const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int alertPin = 5;
const int alertLEDPin = 3;
long getDistance(){
     long duration, inches, cm;
     pinMode(pingPin, OUTPUT);
     digitalWrite(pingPin, LOW);
     delayMicroseconds(2);
     digitalWrite(pingPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(pingPin, LOW);

       duration = pulseIn(echoPin, HIGH);
 //  inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);

   return cm;
}

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(alertPin, OUTPUT);
   pinMode(alertLEDPin, OUTPUT);
}

void loop() {
   
   pinMode(echoPin, INPUT);
   long dist = getDistance();
   while(dist<=20){
   digitalWrite(alertPin, HIGH); 
   digitalWrite(alertLEDPin, HIGH);
      Serial.print(getDistance());
   Serial.print("cm");
   Serial.println();
   dist = getDistance();
   }
   digitalWrite(alertPin, LOW); 
   digitalWrite(alertLEDPin, LOW); 
   Serial.print(getDistance());
   Serial.print("cm");
   Serial.println();
   delay(100);
}



long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
