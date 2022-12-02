#include <SPI.h>

#define MESSAGE   "mohamad 9831125!\r"

const int SS_PIN = 45;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting master");

  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);

  
  SPI.begin();
}

void loop() {
  digitalWrite(SS_PIN, LOW);
  delay(10);

  for (const char *p = MESSAGE ; char c = *p; p++) {
    SPI.transfer(c);
    Serial.print(c);
    delay(5);
  }
  Serial.println();

  digitalWrite(SS_PIN, HIGH);

  delay(1000);
}
