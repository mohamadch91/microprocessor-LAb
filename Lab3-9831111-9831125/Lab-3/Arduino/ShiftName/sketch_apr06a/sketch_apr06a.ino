#include <LiquidCrystal.h>
#include <Keypad.h>

#define REGISTER_SELECT 13
#define ENABLE 12
#define D4 8
#define D5 9
#define D6 10
#define D7 11

LiquidCrystal lcd(REGISTER_SELECT, ENABLE, D4, D5, D6, D7);

//Shift Name
const String name = "Sepehr";
int nameLen = name.length();
int cursorRow=0;
int lastPosition=0;


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
   if(lastPosition + nameLen <= 16){
    lcd.setCursor(lastPosition, cursorRow);
    lcd.print(name);
    delay(1000);
    lcd.clear();
    lastPosition ++;
  }
  else if(cursorRow == 0){
    cursorRow = 1;
    lastPosition = 0;
  }
  else if(cursorRow == 1){
    cursorRow = 0;
    lastPosition = 0;
  }
}
