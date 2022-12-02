int odeToJoy[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_E4, NOTE_D4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4,
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_C4, NOTE_C4,
  NOTE_D4, NOTE_D4, NOTE_E4, NOTE_C4,
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_C4,
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_D4, 0 , 0
};

float odeToJoyDurations[] = {
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  1.33, 4, 1,
  2, 2, 2, 2,
  2, 2, 2, 2,
  2, 2, 2, 2,
  1.33, 4, 1,
  2, 2, 2, 2,
  2, 4, 4, 2, 2,
  2, 4, 4, 2, 2,
  2, 2, 2, 2
};

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int jingleBells[] {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

float jingleBellsDurations[] = {
  4, 4, 2,
  4, 4, 2,
  4, 4, 3, 8,
  1,
  4, 4, 4, 4,
  4, 4, 4, 8, 8,
  4, 4, 4, 4,
  2, 2
};

int PiratesOfCaribbean[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4, 
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
float PiratesOfCaribbeanDurations[] = {
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18,18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

int mario[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};

float marioDurations[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

int iran[] = {
NOTE_D4,  NOTE_A4,  NOTE_A4,  NOTE_A4,  NOTE_D4,
NOTE_D4,  NOTE_A4,  NOTE_A4,  NOTE_A4,  NOTE_D4,
NOTE_A4,  NOTE_AS4, NOTE_C5,  NOTE_A4,
NOTE_D5,  NOTE_C5,  NOTE_C5,  NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_G4,
NOTE_F4,  NOTE_G4,  NOTE_C5,  NOTE_A4,
NOTE_D4,  NOTE_C4,  NOTE_D4,  NOTE_E4,  NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4,
NOTE_A4,  NOTE_C5,  NOTE_AS4, NOTE_A4,  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
NOTE_C4,  NOTE_G4,  NOTE_G4,  NOTE_G4,  NOTE_A4,
NOTE_AS4, NOTE_A4,  NOTE_G4,  NOTE_F4,  NOTE_G4,
NOTE_A4,  NOTE_G4,  NOTE_F4,  NOTE_E4,  NOTE_F4,
NOTE_G4,  NOTE_F4,  NOTE_E4,  NOTE_D4,
NOTE_AS4, NOTE_A4,  NOTE_A4,  NOTE_G4,  NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4,
NOTE_A4,  NOTE_G4,  NOTE_G4,  NOTE_F4,  NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
NOTE_F4,  NOTE_F4,  NOTE_G4,  NOTE_A4
};
float iranDurations[] = {
4, 8, 8, 4, 4,
4, 8, 8, 4, 4,
4, 8, 8, 2,
8, 8, 8, 8, 8, 8, 8, 8,
4, 8, 8, 2,
8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8,
4, 8, 8, 4, 4,
4, 8, 8, 4, 4,
4, 8, 8, 4, 4,
4, 8, 8, 2,
8, 8, 8, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 8,
4, 8, 8, 2
};
int imperialMarch[] = {
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, 0,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, 0,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5,
  
  NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4,
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5,
  NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4,
  

  
};

int imperialMarchDurations[]={
  -4,-4,16,16,16,16,8,8,
  -4,-4,16,16,16,16,8,8,
  4,4,4,-8,16,
  
  4,-8,16,2,
  4,4,4,-8,16,
  4,-8,16,2,
 
  };
