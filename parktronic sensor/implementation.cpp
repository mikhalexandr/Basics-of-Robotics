const int trigPin = 12;
const int echoPin = 11;

void setup() {
  pinMode(trigPin, OUTPUT); // тригер - выходной пин
  pinMode(echoPin, INPUT); // эхо - входной пин
  digitalWrite(trigPin, LOW); // выключение trigPin
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  long distance = getDistance();
  Serial.println(distance);
  delay(100);
  tone(7, 3000, 50);
  delay(map(distance, 10, 330, 20, 800));
}

long getDistance() {
  long dist_cm = getEchoTiming() * 1.7 * 0.01;
  return dist_cm;
}

long getEchoTiming() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration;
}
