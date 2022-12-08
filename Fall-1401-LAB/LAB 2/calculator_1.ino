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

//calculator
int num1;
int num2;
int res;

char str[16];
char str1[16];
char str2[16];

char operand;


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  lcd.setCursor(0, 0);
  
  if(strcmp(str, NULL) == 0)
    str[0] = key;
    else if(key != '='){
    strncat(str, &key, 1);
    lcd.print(str);
    if(key == '+' || key == '-' || key == '/' || key == '*'){
      if(operand == NULL){
        operand = key;
        num1 = atoi(str1); 
      }
    }
    else{
      if(operand == NULL){
        if(strcmp(str1, NULL) == 0)
          str1[0] = key;
        else
          strncat(str1, &key, 1);
      }
      else{
        if(strcmp(str2, NULL) == 0)
          str2[0] = key;
        else
          strncat(str2, &key, 1);
      }
    }
  }
  else if(key == '='){
    num2 = atoi(str2);

    switch(operand){
      case '+':
        res = num1 + num2;
        break;
      case '-':
        res = num1 - num2;
        break;
      case '*':
        res = num1 * num2;
        break;
      case '/':
        res = num1 / num2;
        break;
    }
    
    lcd.setCursor(0, 1);
    lcd.print(res);
    
}
   }
