#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

#define DEVICE_ADDRESS 0b1010000
#define MODE_MEMORY_ADDR 100

#define PRE_WASH 0
#define DETERGENT_WASH 1
#define WATER_WASH 2
#define DRYING 3
#define FINISH 4
int ledPins[4] = {5, 4, 3, 2};
uint8_t modeTimes[4] = {4, 4, 4, 4};//in seconds
String modeMessages[5]={"PRE","DETERGENT","WATER","DRYING","FINISH"};

//Setting LCD configs
const int rs = 13, en = 12, d4 = 8, d5 = 9, d6 = 10, d7 =11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Setting Keypad configs
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {23, 25, 27, 29}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {31,33, 35,37}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int currMode = PRE_WASH;
bool isWashing = false;
int remainingTime;
unsigned long startTime = millis();
void setup() {
  Serial.begin(9600);
  
  for(int i=0; i<FINISH; i++){
    pinMode(ledPins[i], OUTPUT);  
  }
  Wire.begin();

  lcd.begin(16, 2);
  lcd.clear();

  loadConfigs();
}
void loadConfigs(){
  Serial.println("############ Loading Saved Data ############");
  uint8_t savedData[5];
  eeprom_read(MODE_MEMORY_ADDR, savedData, 5);
  if((char)savedData[0] >= '0' && savedData[0] <= '4')
    currMode = uint8ToInt(savedData[0]);

  
  printLCD(currMode);
  
  for(int i=1; i<=4; i++){
      if((char)savedData[i] > '0'){
        modeTimes[i-1] = uint8ToInt(savedData[i]);
      }
  }
  turnOnLED(currMode);

  Serial.println("Current Mode is {" + modeMessages[currMode] + "}");  
  Serial.println("Mode Times:");
  for(int i=0; i<FINISH; i++){
      Serial.println(modeMessages[i]+ "{" +  modeTimes[i] + "}" );
  }

}
void printLCD(int currMode){
  if(currMode > -1){
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(modeMessages[currMode]);  
  }
}
bool isKeyNumber(char key){
  int keyAsciiCode = (int)key;
  return keyAsciiCode >= (int)'0' && keyAsciiCode <= (int)'9';
}
void turnOnLED(int currMode){
  if(currMode == FINISH){
    for(int i=PRE_WASH; i<FINISH; i++){
      digitalWrite(ledPins[i], HIGH);
    }  
  }else{
    for(int i=PRE_WASH; i<FINISH; i++){
      digitalWrite(ledPins[i], LOW);
    }  
    digitalWrite(ledPins[currMode], HIGH);
  }
}
int charToInt(char key){
  return (int)key - 48;
}
int uint8ToInt(uint8_t in){
    return in - 48;
}
void readKeypad(){
  char key = keypad.getKey();  
  static char lastKey;
  
  if(key){
    Serial.println(key);
    if(isKeyNumber(key)){
        lastKey = key;
    }
    else if(key == '='){//Save in EEPROM
        if(charToInt(lastKey)>4)
          return;
        currMode = charToInt(lastKey);
        turnOnLED(currMode);
        uint8_t tempData[1] = {(uint8_t)lastKey};//ascii code

        eeprom_write(MODE_MEMORY_ADDR, tempData, 1);
        printLCD(currMode);
        lcd.setCursor(0, 1);
        lcd.print("                ");
    }else if(key == 'C'){//Change Time
        modeTimes[currMode] = charToInt(lastKey);
        uint8_t tempData[1] = {(uint8_t)lastKey};
        eeprom_write(MODE_MEMORY_ADDR + 1 + currMode, tempData, 1);
    }else if(key == '/'){
      remainingTime -= millis() - startTime;
      if(!isWashing)
        isWashing = true;
      else
        isWashing = false;
    }else if(key == '*'){
      loadConfigs();
      isWashing = true;
    }
  }

}  
void eeprom_write(uint8_t memory_address, uint8_t* data, int _size){
  Serial.println("--- Writing ---" + String(memory_address));
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(memory_address);

  for(int i=0; i<_size; i++){
    Wire.write(data[i]);
  }

  Wire.endTransmission();
}
void eeprom_read(uint8_t memory_address, uint8_t *data, uint8_t _size){
  
  Wire.beginTransmission(DEVICE_ADDRESS);
  Wire.write(memory_address);
  Wire.endTransmission();
  
  Wire.requestFrom(DEVICE_ADDRESS, _size);
  for(int i=0; i<_size; i++){
    data[i] = Wire.read();
  }

}
void checkTime(){
  static int lastMode = -1;
  int passedTime = 0;
  
  if(!isWashing){
    startTime = millis();
    return;
  }
  
  if(lastMode != currMode){
    lastMode = currMode;
    startTime = millis();
    remainingTime = modeTimes[currMode] * 1000;
  }else if(currMode == FINISH){
    lastMode = -1;
    isWashing = false;
    loadConfigs();
    return;
  }else{
    int tempTime= (millis() - startTime) % 1000;
    if(tempTime <= 10 || tempTime >= 990){
      passedTime = ((millis() - startTime)/1000);

      //SHOW TIME  
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(String(remainingTime/1000  - passedTime)+"s");
 
    }
    if(remainingTime/1000 -((millis() - startTime)/1000) <= 0){
      currMode = (currMode + 1) % (FINISH+1);


      uint8_t tempData[1] = {currMode + 48};//ascii code
      eeprom_write(MODE_MEMORY_ADDR, tempData, 1);

      printLCD(currMode);
      turnOnLED(currMode);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      
      if(currMode == 4){
        isWashing = false;
      }
    }
      
  }
}

void loop() {
  readKeypad();
  checkTime();
}
