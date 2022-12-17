#include <Servo.h>
#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //four columns
char keys[rows][cols] = {
  {'7','8','9','/'},
  {'4','5','6', '*'},
  {'1','2','3', '-'},
  {'c', '0', '=', '+'}
};

byte rowPins[rows] = {23, 25, 27, 29}; //connect to the row pinouts of the keypad
byte colPins[cols] = {31, 33, 35, 37}; //connect to the column pinouts of the keypad
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
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent);
  degree = 0;
  input = "";
}

void loop() {
  char key = keypad.getKey();
}




void keypadEvent(KeypadEvent key){
  if(keypad.getState() == PRESSED){
    if(key >= '0' && key <= '9'){
      Serial.print(key);
      input += key;
    }
    if(key == '='){
      degree = input.toInt();
      Serial.println();
      Serial.print("Result: ");
      Serial.println(degree - 180);
      degree = degree/2;
      myservo.write(daegree);
      Serial.println();
      input = "";
    }
  }
}
