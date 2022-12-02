const byte outPin = 0, switchPin = 8;
void setup() {
  pinMode(outPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  bool state = digitalRead(switchPin);
  digitalWrite(outPin, state);
}
