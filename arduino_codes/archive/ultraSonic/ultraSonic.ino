#define echoPin 23
#define trigPin	22
long duration;
int distance;

void setup()
{
	pinMode(trigPin,OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);

	Serial.println("Distance measurement using ESP32.");
	delay(500);
}

void loop()
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
	digitalWrite(trigPin,LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2;

	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}
