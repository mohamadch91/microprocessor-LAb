#include <SPI.h>

const int SS0_PIN = 44, SS1_PIN = 45, TempPin = A8, LightPin = A9;

int analogValue;
uint8_t mapped;


void setup() {
  Serial.begin(9600);
  Serial.println("Starting master");

  pinMode(SS0_PIN, OUTPUT);
  digitalWrite(SS0_PIN, HIGH);

  pinMode(SS1_PIN, OUTPUT);
  digitalWrite(SS1_PIN, HIGH);

  pinMode(TempPin, INPUT);
  pinMode(LightPin, INPUT);

  SPI.begin();
}

void loop() {
  delay(100);

  analogValue = analogRead(LightPin);
  mapped = map(analogValue, 0, 1023, 0, 100);
  digitalWrite(SS0_PIN, LOW);
  SPI.transfer (mapped);
  Serial.print("Light: ");
  Serial.print(mapped);
  Serial.println("%");
  delay(5);
  digitalWrite(SS0_PIN, HIGH);
   delay(100);

  analogValue = analogRead(TempPin);
  mapped = map(analogValue, 0, 306, 0, 150);
  digitalWrite(SS1_PIN, LOW);
  SPI.transfer (mapped);
  Serial.print("Temp: ");
  Serial.print(mapped);
  Serial.println(" C");
  delay(5);
  digitalWrite(SS1_PIN, HIGH);
  Serial.println();
}
