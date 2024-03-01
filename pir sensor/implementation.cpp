void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(5));
  if (digitalRead(5) == 1) {
  	digitalWrite(13, 1);
    digitalWrite(12, 0);
  }
  else {
  	digitalWrite(12, 1);
    digitalWrite(13, 0);
  }
}
