#include <AFMotor.h>

//Pins for HC-SR04
#define trigPin 51
#define echoPin 53

//Motors init
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//Base commands
void forward(int time) {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  delay(time);
}

void backward(int time) {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  delay(time);
}

void right(int time) {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  
  delay(time);
}

void left(int time) {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  
  delay(time);
}

long read_len() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  return distance;
}

void setup() {
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  
  motor4.setSpeed(255);
  motor4.run(RELEASE);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {  
  long distance = read_len();
  if (distance > 15) {
    forward(10);
  }
  else {
    backward(200);
    right(1000);
  }
}
