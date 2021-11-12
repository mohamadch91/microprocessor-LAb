
#include <Keypad.h>//add library

const byte ROWS = 4; //four rows //my keypad rows
const byte COLS = 4; //four columns // my keypad columns
char keys[ROWS][COLS] = { // all my key pad charecters
  {'7','8','9', '/'},
  {'4','5','6', '*'},
  {'1','2','3', '-'},
  {'o','0','=', '+'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28, 29}; //connect to the column pinouts of the keypad

const byte ledPins[9] = {A0, A1, A2, A3, A4, A5, A6, A7, A8}; // connected len pins port 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // define new key pad 
void setup() {
  // put your setup code here, to run once:
  for (byte i = 0; i < 9; i++) // output pins led connected we use arra here
    pinMode(ledPins[i], OUTPUT);
}
  
void loop() {
  // put your main code here, to run repeatedly:
 char key = keypad.getKey();
  if (key){//read charecter and make it high
    for (char i = 0; i < (key-'0'); i++)
      digitalWrite(ledPins[i], HIGH);
  }
}
