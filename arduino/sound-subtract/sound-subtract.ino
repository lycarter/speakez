int speaker = A14;
//board speaker = B
//ambient speaker = A

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);
  analogWriteResolution(12);
}

void loop() {
  int sensorValueA = analogRead(A2);
  int sensorValueB = analogRead(A1);
  int nice = sensorValueB-sensorValueA;
  analogWrite(speaker, nice);
  
//  Serial.print("A ");
//  Serial.print(sensorValueA);
//  Serial.print("B ");
//  Serial.print(sensorValueB);
//  Serial.print("tot ");
//  Serial.println(nice);
//  delay(1);
}
