const int clk = 3;
const int led = 13;
const int data = 16;

IntervalTimer readTimer;

void setup() {
  // sanity check with led
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // prepare the clk pin
  pinMode(clk, OUTPUT);
  analogWriteResolution(1);
  analogWriteFrequency(clk, 3000000);  // 3mhz
  analogWrite(clk, 1); // set duty cycle to 50%, (half of 2^resolution)

  // prepare data pin
  pinMode(data, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(data), readMic, RISING);
}

volatile unsigned long count = 0;
volatile unsigned long total = 0;

void readMic() {
  count += digitalRead(data);
  total += 1;
}

void loop() {
  unsigned long countCopy;
  unsigned long totalCopy;

  noInterrupts();
  countCopy = count;
  totalCopy = total;
  interrupts();
  
  Serial.printf("%lu, %lu", countCopy, totalCopy);
  delayMicroseconds(43);
}
