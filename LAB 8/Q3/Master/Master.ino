#include <SPI.h>

#define MESSAGE0   "mohamad 9831125\r"
#define MESSAGE1   "Hello sepehr\r"

const int SS0_PIN = 44, SS1_PIN = 45;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting master");

  pinMode(SS0_PIN, OUTPUT);
  digitalWrite(SS0_PIN, HIGH);

  pinMode(SS1_PIN, OUTPUT);
  digitalWrite(SS1_PIN, HIGH);
  
  SPI.begin();
}

void sendMessage(const char *message) {
  for (const char *p = message ; char c = *p; p++) {
    SPI.transfer(c);
    Serial.print(c);
    delay(5);
  }
  Serial.println();
}

void loop() {
  digitalWrite(SS0_PIN, LOW);
  sendMessage(MESSAGE0);
  digitalWrite(SS0_PIN, HIGH);
  delay(100);

  digitalWrite(SS1_PIN, LOW);
  sendMessage(MESSAGE1);
  digitalWrite(SS1_PIN, HIGH);
  delay(100);
}
