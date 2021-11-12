#include <Servo.h>

Servo myservo;

String input;
int degree;



int steps = 1; 

void setup() {
  myservo.attach(9,1000,2000);
  Serial.begin(9600);
  degree = 0;
  input = "";
}

void loop() {
  myservo.write(degree);
  delay(30);
  if(degree == 90)
    steps = -1;
  if(degree == 0)
    steps = 1;
  degree = degree + steps ;

}
