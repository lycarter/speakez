int clk = 3;
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(clk, OUTPUT);
  digitalWrite(led, HIGH);
}

void loop() {
  digitalWriteFast(clk, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(10);
  digitalWriteFast(clk, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(10);
}
