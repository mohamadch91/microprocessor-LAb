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
if(Serial.available() > 0){
    serialInput = Serial.readString();
    Serial.println(serialInput.toInt());
    serialDegree = (180 - serialInput.toInt())/2;
    Serial.println(serialInput.toInt()* (-1));
  }
  myservo.write(serialDegree);
}
