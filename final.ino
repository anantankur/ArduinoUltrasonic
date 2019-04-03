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
  pinMode(11, OUTPUT); //head led
  pinMode(13, OUTPUT); //tail led
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT); //servo 1 signal
  pinMode(6, OUTPUT); //servo 2 signal
}

void loop() {
  digitalWrite(trigPin, HIGH);
  _delay_ms(25);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
        
  if (distance < 40) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    delay(100);
    digitalWrite(3, HIGH);
    myservo1.write(n);
    myservo2.write(180-n);
    Serial.println("stop");
    delay(500);
    //go back
    digitalWrite(5, LOW);
    myservo1.write(n);
    digitalWrite(6, HIGH);
    myservo2.write(90);
    delay(1400);
    //turn around
    digitalWrite(5, HIGH);
    myservo1.write(0);
    digitalWrite(6, HIGH);
    myservo2.write(90);
    delay(1500);
  }
  else {
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(3, LOW);
    Serial.println("regular");
    digitalWrite(5, HIGH);
    myservo1.write(n);
    digitalWrite(6, LOW);
    myservo2.write(180);
  }
}
