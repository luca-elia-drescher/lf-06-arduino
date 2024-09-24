void setup() {
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(8) == LOW) {
    Serial.println("Button pressed.");
    int value = analogRead(5);
    Serial.println("Value: " + value);
    delay(100);
  }

}
