#include <Keypad.h>

const byte ROWS = 5; //5 rows
const byte COLS = 4; //4 columns
char paswword="1379"
char* specialKeys[] ={
            "F1",  "F2", "#", "*",
            "1",  "2", "3", "UP",
            "4",  "5", "6", "DOWN",
            "7",  "8", "9", "ESC",
            "LEFT",  "0", "RIGHT", "ENTER"  
                    };

                    
char specialKeysID[] = {
        'A',  'B', '#', '*',
        '1',  '2', '3', 'C',
        '4',  '5', '6', 'D',
        '7',  '8', '9', 'E',
        'F',  '0', 'G', 'H'
      };                    

char keys[ROWS][COLS] = {
{specialKeysID[0],  specialKeysID[1], specialKeysID[2], specialKeysID[3]},
{specialKeysID[4],  specialKeysID[5], specialKeysID[6], specialKeysID[7]},
{specialKeysID[8],  specialKeysID[9], specialKeysID[10], specialKeysID[11]},
{specialKeysID[12],  specialKeysID[13], specialKeysID[14], specialKeysID[15]},
{specialKeysID[16],  specialKeysID[17], specialKeysID[18], specialKeysID[19]}
};


byte rowPins[ROWS] = {2,3,4,5,6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {10,9,8,7}; //connect to the column pinouts of the kpd

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;


void setup() {
  // Robojax 5x4 keypad test
  Serial.begin(9600);
  Serial.println("Micro Lab");
}


void loop() {
  // Robojax 5x4 keypad test
  char key = keypad.getKey();
    // just print the pressed key
    
   if (key){
    Serial.print("Key: ");
    Serial.println(getKey(key));
  } 
  if(getKey(key) =="ENTER")
  {
     Serial.println("ENTER is pressed");   
  }
  

}  // End loop


/*
 * getKey()
 * @brief gets the actual key value from single character 
 * @param k is character
 * @return returns acualt key value
 * Written by Ahmad Shamshiri for robojax.com
 * on May 06, 2020 at 19:37 in Ajax, Ontario, Canada
 */
char* getKey(char *k)
{
 
  for(int i=0; i<20; i++)
  {
    if(specialKeysID[i] ==k) return specialKeys[i];
  }
 
}//getKey
