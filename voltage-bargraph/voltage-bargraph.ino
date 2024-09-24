int red = 3;
int green = 6;
int blue = 5;

// max = 5V = 1023; min = 0V = 0
// to determine the step size we calculate max divided by 5
// step = 5V/5 = 1V; step= 1023/5 = 204,6

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);

  if (digitalRead(8) == 0) {
    int value = analogRead(5);
    double voltage = value/204.6;
    Serial.println(voltage);
    delay(10);
    if (voltage > 1 && voltage < 2) {
        analogWrite(blue, 255);
        Serial.println("blue");
    } else if (voltage >= 2 && voltage < 4) {
        analogWrite(green, 255);
      Serial.println("green");
    } else if (voltage >= 4) {
        analogWrite(red, 255);
        Serial.println("red");
    } else {
      analogWrite(red, 0);
      analogWrite(green, 0);
      analogWrite(blue, 0);
    }
  }
}
