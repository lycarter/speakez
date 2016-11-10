const int clk = 3;
const int led = 13;
const int data = 16;

IntervalTimer readTimer;

void setup() {
  // sanity check
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // prepare the clk pin
  pinMode(clk, OUTPUT);
  analogWriteResolution(1);
  analogWriteFrequency(clk, 3000000);  // 3mhz
  analogWrite(clk, 1); // set duty cycle to 50%, (half of 2^resolution)

  // prepare data pin
  pinMode(data, INPUT);
  Serial.begin(115200);
  readTimer.begin(readMic, 1);  // this is a dumb arbitrary limit and i hate it. 1mhz max.
}

volatile unsigned long count = 0;

void readMic(void) {
  count += digitalRead(data);
}

void loop() {
  unsigned long countCopy;

  noInterrupts();
  countCopy = count;
  interrupts();
  
  Serial.println(countCopy);
  delayMicroseconds(43);
}
