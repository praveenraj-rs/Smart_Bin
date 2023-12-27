float sensorToBin = 15;
float binHeight = 9;

#define echoPin 23
#define trigPin 22
long duration;
int distance;
float fill;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  Serial.println("Distance measurement using ESP32.");
  delay(500);
}

float binFill()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;
  fill = 100 - (((distance - sensorToBin) / binHeight) * 100);

  // Ensure fill is within the range of 0 to 100
  fill = constrain(fill, 0, 100);

  return fill;
}

void loop()
{
  if (Serial.available() > 0)
  {
    // Read the material type from serial input
    String materialType = Serial.readStringUntil('\n');

    // Send back the constrained fill percentage based on material type
    if (materialType == "cardboard" || materialType == "glass" || materialType == "metal" ||
        materialType == "paper" || materialType == "plastic" || materialType == "trash")
    {
      Serial.print(materialType);
      Serial.print(": ");
      Serial.print(binFill());
      Serial.println("%");
    }
  }

  delay(1000);
}
