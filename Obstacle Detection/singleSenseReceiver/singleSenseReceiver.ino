const int alertPin = 5;


void setup() {
 Serial.begin(9600); // Starting Serial Terminal
   pinMode(alertPin, INPUT);

}

void loop() {
  while( digitalRead(alertPin)){
    Serial.println("Obstacle present");
  }
  Serial.println("No obstacles");

}
