int clk = 3;
int led = 13;
int data = 16;

void setup() {
  // sanity check
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // prepare the clk pin
  pinMode(clk, OUTPUT);
  analogWriteResolution(1);
  analogWriteFrequency(clk, 3000000);
  analogWrite(clk, 1); // set duty cycle to 50%, (half of 2^resolution)

  // prepare data pin
  pinMode(data, INPUT);
  Serial.begin(9600);
}

void loop() {
  int dataValue = digitalRead(data);
  Serial.println(dataValue);
  delayMicroseconds(1);
}
