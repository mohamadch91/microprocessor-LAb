#include <Servo.h>

Servo myservo;
String input;
int degree;
String serialInput = "";
int serialDegree = 0;

int potpin = 0;
int val;

int steps = 1; 

void setup() {
  myservo.attach(9,1000,2000);
  Serial.begin(9600);
  degree = 0;
  input = "";
}

void loop() {
    Serial.print("Potentiometer: ");
    val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    Serial.println(val);
    myservo.write(val);
    delay(1000);
}
