#include <Stepper.h>

// For Slider
const int n = 3;
const int stepsPerRevolution = 3000;
Stepper sliderStepper(stepsPerRevolution, D4, D5);

// For Rotation
const int stepsForRotation = 3000;
Stepper rotateStepper(stepsPerRevolution, D6, D7);
// Stepper rotateStepper(stepsPerRevolution, directionPin, stepPin);

void setup() {
  Serial.begin(9600);
  sliderStepper.setSpeed(45);  // You can adjust the speed as needed(for Slider)
  rotateStepper.setSpeed(45);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the serial message until newline

    if (input == "rotate_right") {
      rotateStepper.step(stepsForRotation);
      SliderOpenClose();
    } else if (input == "rotate_left") {
    	rotateStepper.step(-stepsForRotation);
	    SliderOpenClose();
    } else if (input == "stay") {
      // Eat FiveStar, Do nothing (>‿◠)
    } else {
      Serial.println("Invalid command. Please enter 'rotate_right', 'rotate_left', or 'stay'.");
    }
  }
}

void SliderOpenClose()
{
  for (int i = 0; i < n; i++) {
	sliderStepper.step(stepsPerRevolution);
	delay(100);
  }

  // Rotate three times backward
  for (int i = 0; i < n; i++) {
	sliderStepper.step(-stepsPerRevolution);
	delay(100);
  }

  Serial.println("Waste Moved into Bin");

  // Stop the motor
  sliderStepper.step(0);
}

