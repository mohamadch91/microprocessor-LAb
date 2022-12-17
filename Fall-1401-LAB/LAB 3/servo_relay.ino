#include <Servo.h>
#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //four columns
const byte outPin = 0;

char keys[rows][cols] = {
  {'7','8','9','/'},
  {'4','5','6', '*'},
  {'1','2','3', '-'},
  {'c', '0', '=', '+'}
};

byte rowPins[rows] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[cols] = {A3, A2, A1, A0}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

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
  keypad.addEventListener(keypadEvent);
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);    
  degree = 0;
  input = "";
}

void loop() {
  char key = keypad.getKey();

}




void keypadEvent(KeypadEvent key){
  if(keypad.getState() == PRESSED){
    if(key >= '0' && key <= '9'){
      input += key;
      Serial.println(input);
    }
    if(key == '='){
      degree = input.toInt();
      Serial.println(degree);
      degree = degree/2;
      Serial.println(degree);
      myservo.write(degree);
      if( degree >=90){
        digitalWrite(outPin, 1);
      }
      else{
        digitalWrite(outPin, 0);
      }
      input = "";
    }
  }
}
