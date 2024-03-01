const int trigPin = 12;
const int echoPin = 11;

void setup() {
  pinMode(trigPin, OUTPUT); // тригер - выходной пин
  pinMode(echoPin, INPUT); // эхо - входной пин
  digitalWrite(trigPin, LOW); // выключение trigPin
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  long distance = getDistance();
  Serial.println(distance);
  delay(100);
  if (distance <= 100) {
  	digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    tone(7, 3000, 100);
  }
  else if (distance <= 150) {
  	digitalWrite(3, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    tone(7, 1500, 100);
  }
  else {
  	digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
  }
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