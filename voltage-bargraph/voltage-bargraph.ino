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
  if (digitalRead(8) == LOW) {
    Serial.println("Button pressed.");
    int value = analogRead(5);
    Serial.println(value);
    delay(100);
  }
}
