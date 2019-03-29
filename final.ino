#include <Servo.h> 
#include <NewPing.h>

int n; 
int duration, distance;
int trigPin = (10);
int echoPin = (12);

String readString;

Servo myservo1; 
Servo myservo2;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  myservo1.attach(8);
  myservo2.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  _delay_ms(25);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
        
  if (distance < 30) {
    digitalWrite(3, HIGH);
    myservo1.write(n);
    myservo2.write(180-n);
    Serial.println("stop");
    delay(500);
    //myservo1.write(n);
    //myservo2.write(90-n);
    digitalWrite(5, LOW);
    myservo1.write(n);
    digitalWrite(6, HIGH);
    myservo2.write(90);
    delay(250);
  }
  else {
    digitalWrite(3, LOW);
    Serial.println("regular");
    myservo1.write(180-n);
    //myservo2.write(n);
    digitalWrite(5, HIGH);
    myservo1.write(180);
    digitalWrite(6, LOW);
    myservo2.write(180);
  }
}
