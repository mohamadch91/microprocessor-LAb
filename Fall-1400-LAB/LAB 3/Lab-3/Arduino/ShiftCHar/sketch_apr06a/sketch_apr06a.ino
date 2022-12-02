#include <LiquidCrystal.h>

#define REGISTER_SELECT 13
#define ENABLE 12
#define D4 8
#define D5 9
#define D6 10
#define D7 11

LiquidCrystal lcd(REGISTER_SELECT, ENABLE, D4, D5, D6, D7);

int lastPosition = 0;
int cursorRow = 0;

//shiftChar
char shiftChar = 'S';


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  if(lastPosition >= 15){
    lcd.clear();
    lastPosition = 0;
    if(cursorRow == 0){
      cursorRow = 1;
      lcd.clear();
    }
    else{
      cursorRow = 0;
      lcd.clear();
    }
  }
  lcd.setCursor(0, cursorRow);
  lcd.print(shiftChar);
  if(lastPosition != 0){
    lcd.scrollDisplayRight();
  }
  delay(1000);
  lastPosition ++;
}
