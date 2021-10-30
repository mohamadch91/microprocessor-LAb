#include <LiquidCrystal.h>
#include <Keypad.h>

#define REGISTER_SELECT 13
#define ENABLE 12
#define D4 8
#define D5 9
#define D6 10
#define D7 11

LiquidCrystal lcd(REGISTER_SELECT, ENABLE, D4, D5, D6, D7);


//Keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'O','0','=','+'}
};
byte rowPins[ROWS] = {23, 25, 27, 29}; 
byte colPins[COLS] = {31,33, 35,37}; 

//make a new keypad object
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char correctPassword[] = "9831111";
char enteredPassword[16];


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  lcd.setCursor(0, 0);
  if(strcmp(enteredPassword, NULL) == 0)
    enteredPassword[0] = key;
  else if(key != '*'){
    strncat(enteredPassword, &key, 1);
    lcd.print(enteredPassword);
  }
  else{
    lcd.setCursor(0, 1);
    if(strcmp(enteredPassword, correctPassword) == 0)
      lcd.print("correct password");
    else
      lcd.print("wrong password");
  }
}
