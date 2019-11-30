#define m1 2
#define m2 3
#define m3 4
#define m4 5
#define m5 8
#define m6 9
#define m7 10
#define m8 11
int trigPin = 7;
int echoPin = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (m1, OUTPUT);
  pinMode (m2, OUTPUT);
  pinMode (m3, OUTPUT);
  pinMode (m4, OUTPUT);
  pinMode (m5, OUTPUT);
  pinMode (m6, OUTPUT);
  pinMode (m7, OUTPUT);
  pinMode (m8, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
}
void backward() {
  digitalWrite (m1, LOW);
  digitalWrite (m2, HIGH);
  digitalWrite (m3, LOW);
  digitalWrite (m4, HIGH);
  digitalWrite (m4, LOW);
  digitalWrite (m4, HIGH);
  digitalWrite (m4, LOW);
  digitalWrite (m4, HIGH);

}
void forward() {
  digitalWrite (m1, HIGH);
  digitalWrite (m2, LOW);
  digitalWrite (m3, HIGH);
  digitalWrite (m4, LOW);
  digitalWrite (m5, HIGH);
  digitalWrite (m6, LOW);
  digitalWrite (m7, HIGH);
  digitalWrite (m8, LOW);
}
void left() {
  digitalWrite (m1, HIGH);
  digitalWrite (m2, LOW);
  digitalWrite (m3, HIGH);
  digitalWrite (m4, LOW);
  digitalWrite (m5, LOW);
  digitalWrite (m6, HIGH);
  digitalWrite (m7, LOW);
  digitalWrite (m8, HIGH);

}
void right() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  digitalWrite(m5, HIGH);
  digitalWrite(m6, LOW);
  digitalWrite(m7, HIGH);
  digitalWrite(m8, LOW);

}
void still() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
  digitalWrite(m5, LOW);
  digitalWrite(m6, LOW);
  digitalWrite(m7, LOW);
  digitalWrite(m8, LOW);
}

float check_distance () {
  long duration, distance;
  digitalWrite (trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite (trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  return distance;
}


void loop() {
  // put your main code here, to run repeatedly:
  float d;
  d = check_distance();
  if ((d > 5))
  {
    forward();
  }
  else if (d <= 5)
  {
    backward();
    delay(1000);
    right();
    delay(500);
    forward();
  }

}
