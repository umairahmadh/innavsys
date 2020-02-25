const int pingPin1 = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin1 = 7; // Echo Pin of Ultrasonic Sensor
const int pingPin2 = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 10; // Echo Pin of Ultrasonic Sensor
const int alertPin = 5;
const int alertLEDPin = 3;

const int limitDistance = 40;
long getDistance1() {
  long duration, inches, cm1;
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);
  //  inches = microsecondsToInches(duration);
  cm1 = microsecondsToCentimeters(duration);

  return cm1;
}


long getDistance2() {
  long duration, inches, cm2;
  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin2, LOW);

  duration = pulseIn(echoPin2, HIGH);
  //  inches = microsecondsToInches(duration);
  cm2 = microsecondsToCentimeters(duration);

  return cm2;
}

void setup() {
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(alertPin, OUTPUT);
  pinMode(alertLEDPin, OUTPUT);
}

void loop() {

  pinMode(echoPin1, INPUT);
    pinMode(echoPin2, INPUT);
  long dist1 = getDistance1();
  long dist2 = getDistance2();
//  while (dist1 <= limitDistance || dist2 <= limitDistance ) {
  while (dist1 <= limitDistance) {

    digitalWrite(alertPin, HIGH);
    digitalWrite(alertLEDPin, HIGH);
    Serial.print(getDistance1());
    Serial.print("cm");
    Serial.println();
    Serial.print(getDistance2());
    Serial.print("cm");
    Serial.println();
    dist1 = getDistance1();
    dist2 = getDistance2();
  }
  
  digitalWrite(alertPin, LOW);
  digitalWrite(alertLEDPin, LOW);
  Serial.print(getDistance1());  
  Serial.print("cm");
  Serial.println();
  Serial.print(getDistance2());
  Serial.print("cm");
  Serial.println();
  delay(10);
}



long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
