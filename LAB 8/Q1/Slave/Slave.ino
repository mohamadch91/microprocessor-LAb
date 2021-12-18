#include <SPI.h>

const int MISO_PIN = 50, MOSI_PIN = 51, SCK_PIN = 52, SS_PIN = 53;
volatile int ind = 0;
volatile boolean finished = false;
char message[20];

void setup() {
  Serial.begin(9600);
  Serial.println("Starting slave");

  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, INPUT);
  pinMode(SS_PIN, INPUT_PULLUP);

  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

void loop() {
  if (finished) {
    Serial.println(message);
    ind = 0;
    finished = false;
  }
}

ISR (SPI_STC_vect)
{
  byte c = SPDR;
  if (ind < sizeof message) {
    message[ind++] = c;

    if (c == '\r') {
      finished = true;
    }
  }
}
