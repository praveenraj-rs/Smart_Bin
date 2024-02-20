#include <Stepper.h>

void setup()
{
 Serial.begin(9600);
 Serial.println("Esp32 Connection Establised");
 delay(500) ;
}

float binFill(){

  #define trigPin	22
  #define echoPin 23

  pinMode(trigPin,OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
	Serial.println("Measuring the dustbin fill level.");
	delay(500);

  float sensorToBin = 15; // In cm
  float binHeight = 9; // In cm

  long duration;
  int distance;
  float fill;

  digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
	digitalWrite(trigPin,LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2;
  fill = 100-(((distance-sensorToBin)/binHeight)*100);
  return fill;
}

void stepperControl(){

const int stepsPerRevolution = 2048;
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 12, 14, 13, 27);

myStepper.setSpeed(10);
myStepper.step(stepsPerRevolution);
delay(10);
}

void loop()
{
if (Serial.available() > 0) { //checking data availability
    String data = Serial.readStringUntil('\n'); //reading line
    if(data=="dist"){
      Serial.print(binFill());
      Serial.println("%");
    }
    else if(data=="step"){
      int  n = 2; // for number of revolution
      for (int i=1;i<=n;i++){
      stepperControl();
      }
    }
}
}