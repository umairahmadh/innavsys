/*
   Miltiple Ultrasonic Sensors
   Prints the distance read by many ultrasonic sensors in
   centimeters and inches. They are supported to four pins
   ultrasound sensors (liek HC-SC04) and three pins
   (like PING))) and Seeed Studio sensors).

   The circuit:
 * * In this circuit there is an ultrasonic module HC-SC04,
     PING))) and a Seeed Studio (4 pins, 3 pins, 3 pins,
     respectively), attached to digital pins as follows:
   ---------------------     ---------------------     -------------------
   | HC-SC04 | Arduino |     | PING))) | Arduino |     | Seeed | Arduino |
   ---------------------     ---------------------     -------------------
   |   Vcc   |   5V    |     |   Vcc   |   5V    |     |  Vcc  |   5V    |
   |   Trig  |   12    | AND |   SIG   |   10    | AND |  SIG  |    8    |
   |   Echo  |   13    |     |   Gnd   |   GND   |     |  Gnd  |   GND   |
   |   Gnd   |   GND   |     ---------------------     -------------------
   ---------------------
   Note: You do not obligatorily need to use the pins defined above

   By default, the distance returned by the read()
   method is in centimeters. To get the distance in inches,
   pass INC as a parameter.
   Example: ultrasonic.read(INC)

   created 3 Mar 2017
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
   modified 11 Jun 2018
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)

   This example code is released into the MIT License.
*/


const int alertPin = 5;
const int limitDistance = 60;


#include <Ultrasonic.h>


Ultrasonic ultrasonic1(6, 7);	// An ultrasonic sensor HC-04
Ultrasonic ultrasonic2(8, 9);  // An ultrasonic sensor HC-04



void setup() {
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(alertPin, OUTPUT);
}

void loop() {


  long dist1 = ultrasonic1.read();
  long dist2 = ultrasonic2.read();
  //  while (dist1 <= limitDistance || dist2 <= limitDistance ) {
  while (ultrasonic1.read() <= limitDistance || ultrasonic2.read() <= limitDistance ) {

    digitalWrite(alertPin, HIGH);
    Serial.print(ultrasonic1.read());
    Serial.print("cm");
    Serial.println();
    Serial.print(ultrasonic2.read());
    Serial.print("cm");
    Serial.println();
    dist1 = ultrasonic1.read();
    dist2 = ultrasonic2.read();
  }

  digitalWrite(alertPin, LOW);
  Serial.print(ultrasonic1.read());
  Serial.print("cm");
  Serial.println();
  Serial.print(ultrasonic2.read());
  Serial.print("cm");
  Serial.println();
  delay(10);
}
