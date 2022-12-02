#include <SPI.h>

const int MISO_PIN = 50, MOSI_PIN = 51, SCK_PIN = 52, SS_PIN = 53;
int value;
volatile boolean finished = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting slave (Temperature)");

  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, INPUT);
  pinMode(SS_PIN, INPUT_PULLUP);

  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

void loop() {
  if (finished) {
    Serial.print("Temprature : ");
    Serial.print(value);
    Serial.println(" C");
    finished = false;
  }
}

ISR (SPI_STC_vect)
{
  byte number = SPDR;
  value = (uint8_t)number;
  finished = true;
}
