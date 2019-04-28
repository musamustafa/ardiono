    /*
    * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
    *
    * by Dejan Nedelkovski,
    * www.HowToMechatronics.com
    *
    */
    // defines pins numbers
    const int trigPin = 9;
    const int echoPin = 10;
    const int led1 = 11;
    const int led2 = 7;
    const int led3 = 13;
    const int led4 = 8;
    // defines variables
    long duration;
    int distance;
    void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(led1, OUTPUT); // Sets the trigPin as an Output
    pinMode(led2, OUTPUT); // Sets the trigPin as an Output
    pinMode(led3, OUTPUT); // Sets the trigPin as an Output
    pinMode(led4, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
    }
    void loop() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    if (distance <= 10){
      if (distance <= 9){
        if (distance <= 8){
          if (distance <= 7){
            digitalWrite(led4, HIGH);
          }
          digitalWrite(led3, HIGH);
        }
        digitalWrite(led2, HIGH);
      }
      digitalWrite(led1, HIGH);
      delayMicroseconds(1000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    }
