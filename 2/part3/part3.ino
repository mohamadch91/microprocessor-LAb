

const byte ledPins[9] = {A0, A1, A2, A3, A4, A5, A6, A7, A8};// connected pins to led
byte incomingByte = 0; // for incoming serial data

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

  for (byte i = 0; i < 9; i++)
    pinMode(ledPins[i], OUTPUT);// connect leds
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.println(incomingByte-'0');
    if(incomingByte>'9'){
      Serial.println('invalid number');
      }
      
    // turn on corresponding led
    else{
      for (char i = 0; i < (incomingByte - '0'); i++)
        digitalWrite(ledPins[i], HIGH);

    }
  }
}
