#include <Servo.h>

#define TRIG_PIN_1  2  // Arduino digital pin 2 connected to Ultrasonic Sensor 1's TRIG pin
#define ECHO_PIN_1  3  // Arduino digital pin 3 connected to Ultrasonic Sensor 1's ECHO pin
#define SERVO_PIN_1 8  // Arduino digital pin 8 connected to Servo 1's pin

#define TRIG_PIN_2  5  // Arduino digital pin 4 connected to Ultrasonic Sensor 2's TRIG pin
#define ECHO_PIN_2  4  // Arduino digital pin 5 connected to Ultrasonic Sensor 2's ECHO pin
#define SERVO_PIN_2 10  // Arduino digital pin 9 connected to Servo 2's pin

#define DISTANCE_THRESHOLD 30 // centimeters
#define SERVO_SPEED 2 // Speed of Servo Movement

Servo servo1; // create servo object for Servo 1
Servo servo2; // create servo object for Servo 2



void setup() {
  Serial.begin(9600);        // initialize serial port

  // Ultrasonic Sensor 1 setup
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  // Servo 1 setup
  servo1.attach(SERVO_PIN_1);

  // Ultrasonic Sensor 2 setup
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  // Servo 2 setup
  servo2.attach(SERVO_PIN_2);
}

void loop() {
  // Ultrasonic Sensor 1
  unsigned long duration_us_1 = getUltrasonicDistance(TRIG_PIN_1, ECHO_PIN_1);
  float distance_cm_1 = duration_us_1 * 0.034 / 2;

  Serial.print("Distance 1: ");
  Serial.print(distance_cm_1);
  Serial.println(" cm");

  // Servo 1 control
  if (distance_cm_1 < DISTANCE_THRESHOLD) {
    for (int angle = 0; angle <= 90; angle += SERVO_SPEED) 
    {
      servo.write(angle);
      delay(15); // Adjust delay for smoother movement
    } 
    delay(1000);      // Delay for stability, adjust as needed
  } 
  else 
  {
    for (int angle = 90; angle >= 0; angle -= SERVO_SPEED) 
    {
      servo.write(angle);
      delay(15);
    }
  }

  // Ultrasonic Sensor 2
  unsigned long duration_us_2 = getUltrasonicDistance(TRIG_PIN_2, ECHO_PIN_2);
  float distance_cm_2 = duration_us_2 * 0.034 / 2;

  Serial.print("Distance 2: ");
  Serial.print(distance_cm_2);
  Serial.println(" cm");

  // Servo 2 control
  if (distance_cm_2 < DISTANCE_THRESHOLD) {
    for (int angle = 0; angle <= 90; angle += SERVO_SPEED) 
    {
      servo.write(angle);
      delay(15); // Adjust delay for smoother movement
    } 
    delay(1000);      // Delay for stability, adjust as needed
  }
  else 
  {
    for (int angle = 90; angle >= 0; angle -= SERVO_SPEED)
    {
      servo.write(angle);
      delay(15);
    }
  }

  delay(500); // Adjust delay as needed for stability and to avoid rapid changes
}

// Function to get ultrasonic distance
unsigned long getUltrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}
