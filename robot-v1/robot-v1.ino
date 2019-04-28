  /* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

// define pin numbers



#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int in1 = 5;
const int in2 = 4;
const int in3 = 3;
const int in4 = 2;
const int spd = 6;
const int spd1 = 11;
const int trigPin = 12;
const int echoPin = 10;
long duration;
int distance;
int left;
int right;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);    
  pinMode(in4, OUTPUT);
  pinMode(spd, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  analogWrite(spd, 135);
  analogWrite(spd1, 120);
  myservo.write(85);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;

  if (distance > 40 ){
    digitalWrite(in3, HIGH);
    digitalWrite(in1, HIGH);

  }
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
    delay(1000);
    digitalWrite(in4, HIGH);
    digitalWrite(in2, HIGH);
    delay(400);
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);
    delay(1000);
    
    myservo.write(0);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20); 

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    right = duration*0.034/2;

    delay(1000);

    myservo.write(180);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20); 

    digitalWrite(trigPin, HIGH);
     delayMicroseconds(100);
     digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    left = duration*0.034/2;
    delay(1000);
    
    myservo.write(85);

    delay(500);
    if (left >= right) {
    digitalWrite(in4, HIGH);
    digitalWrite(in1, HIGH);
    delay(400);
    digitalWrite(in4, LOW);
    digitalWrite(in1, LOW);
    delay(1000);
    }
    else {
    digitalWrite(in3, HIGH);
    digitalWrite(in2, HIGH);
    delay(400);
    digitalWrite(in3, LOW);
    digitalWrite(in2, LOW);
    delay(1000);
    }
  }
}
