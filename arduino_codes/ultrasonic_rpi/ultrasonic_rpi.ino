float sensorToBin=15;
float binHeight=9;

#define echoPin 23
#define trigPin	22
long duration;
int distance;
float fill;

void setup()
{
	pinMode(trigPin,OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);

	Serial.println("Distance measurement using ESP32.");
	delay(500);
}

float binFill(){

  digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
	digitalWrite(trigPin,LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2;
  // fill = (100-((distance-sensorToBin)/binHeight)*100);
  fill = 100-(((distance-sensorToBin)/binHeight)*100);
  return fill;
}

void loop()
{
if (Serial.available() > 0) { //checking data availability
    String data = Serial.readStringUntil('\n'); //reading line
    if(data=="dist"){
      Serial.print(binFill());
      Serial.println("%");
    }
}
}
