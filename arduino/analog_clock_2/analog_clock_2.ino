const int clk = 3;
const int led = 13;

void setup() {
  // sanity check
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // prepare the clk pin
  pinMode(clk, OUTPUT);
  analogWriteResolution(1);
  analogWriteFrequency(clk, 3000000); // 3mhz
  analogWrite(clk, 1); // set duty cycle to 50%, (half of 2^resolution)
}

void loop() {
}
