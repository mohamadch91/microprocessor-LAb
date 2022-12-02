#include "pitches.h"
#include "themes.h"
#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //four columns
char keys[rows][cols] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'o','0','=','+'}
};
byte rowPins[rows] = {23, 25, 27, 29}; //connect to the row pinouts of the keypad
byte colPins[cols] = {31, 33, 35, 37}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

#define PIEZO 9

void setup() {
  // put your setup code here, to run once:
    keypad.addEventListener(keypadEvent);
    pinMode(10,INPUT);
}

void loop() {
  char key = keypad.getKey();
}

void playMelody(int melody[], float  noteDurations[], int m_size, int num) {
  for (int thisNote = 0; thisNote < m_size; thisNote++) {
    int key=digitalRead(10);
    float scale = analogRead(A0) / 512.0;
    if(key == LOW){
      scale = 1.0;
    }
    int noteDuration = num /  noteDurations[thisNote];
    tone(PIEZO, (int)(melody[thisNote] * scale), noteDuration);
    delay((int)noteDuration * 0.8);
  }

  noTone(9);
}



void keypadEvent(KeypadEvent key){
  if(key == '1'){
    playMelody(odeToJoy, odeToJoyDurations, sizeof(odeToJoy) / sizeof(int), 800);
  }
  if(key == '2'){
    playMelody(jingleBells, jingleBellsDurations, sizeof(jingleBells) / sizeof(int), 500);
  }
  if(key == '3'){
    playMelody(PiratesOfCaribbean, PiratesOfCaribbeanDurations, sizeof(PiratesOfCaribbean) / sizeof(int), 800);
  }
  if(key == '4'){
    playMelody(mario, marioDurations, sizeof(mario) / sizeof(int), 600);
  }
  if(key == '5'){
    playMelody(iran, iranDurations, sizeof(iran) / sizeof(int), 800);
  }
}
