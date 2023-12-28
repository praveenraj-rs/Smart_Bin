#include <Servo.h>

#define TRIG_PIN  23  // ESP32 pin GPIO23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN  22  // ESP32 pin GPIO22 connected to Ultrasonic Sensor's ECHO pin
#define SERVO_PIN 26  // ESP32 pin GPIO26 connected to Servo Motor's pin
#define TOUCH_PIN 4   // ESP32 pin GPIO4 connected to Touch Sensor's SIG/IO pin
#define DISTANCE_THRESHOLD  20 // centimeters
#define SERVO_SPEED 2 // Speed of servo movement, adjust as needed

Servo servo; // create servo object to control a servo

// variables will change:
float duration_us, distance_cm;
int servoAngle=180;
int currentAngle = 0; // current position of the servo
int McurrentAngle = 0; // current position of the servo
bool manualControl = false;

void setup() {
  Serial.begin(9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set ESP32 pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set ESP32 pin to input mode
  pinMode(TOUCH_PIN, INPUT); // set ESP32 pin to input mode for touch sensor
  servo.attach(SERVO_PIN);   // attaches the servo on pin 26 to the servo object
  servo.write(0);
}

void loop() {
  // Check if touch sensor is pressed
  if (digitalRead(TOUCH_PIN) == HIGH) {
    delay(50); // Debounce delay

    // Toggle manual control mode
    manualControl = !manualControl;

    if (manualControl) {
      for (int angle = McurrentAngle; angle != servoAngle; angle += SERVO_SPEED) {
      servo.write(angle);
      delay(15); // Adjust delay for smoother movement
      McurrentAngle=servoAngle;
    }
    }
    else {
    for (int angle = McurrentAngle; angle != 0; angle -= SERVO_SPEED) {
      servo.write(angle);
      delay(15);
      McurrentAngle=0;
    }
    }
    delay(500);
    }

 if (!manualControl) {
    // Automatic mode
    // generate 10-microsecond pulse to TRIG pin
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // measure duration of pulse from ECHO pin
    duration_us = pulseIn(ECHO_PIN, HIGH);
    // calculate the distance
    distance_cm = 0.017 * duration_us;

    int targetAngle = (distance_cm < DISTANCE_THRESHOLD) ? servoAngle : 0;

    // Smoothly move the servo towards the target angle
    for (int angle = currentAngle; angle != targetAngle; angle += (targetAngle > currentAngle) ? SERVO_SPEED : -SERVO_SPEED) {
      servo.write(angle);
      delay(15); // Adjust delay for smoother movement
    }

    currentAngle = targetAngle; // Update current angle

    // print the value to Serial Monitor
    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
  }

  delay(200);
}
