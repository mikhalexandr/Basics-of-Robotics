void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(200);

  // changing temperature 20 - 358
  if (analogRead(A0) <= 132) {
  	digitalWrite(13, 1);
    digitalWrite(12, 0);
    digitalWrite(11, 0);
  }
  else if (analogRead(A0) <= 244) {
  	digitalWrite(13, 0);
    digitalWrite(12, 1);
    digitalWrite(11, 0);
  }
  else {
  	digitalWrite(13, 0);
    digitalWrite(12, 0);
    digitalWrite(11, 1);
  }
}