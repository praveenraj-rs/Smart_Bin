
void setup()
{
  Serial.begin(9600);
  delay(500);
}

void loop()
{
  if (Serial.available() > 0)
  {
    // Read the material type from serial input
    String rotate_dir = Serial.readStringUntil('\n');

    // Send back the constrained fill percentage based on material type
    if (rotate_dir=="stay")
    {
      Serial.print("Stayed In.\n");
    }
    else if (rotate_dir=="rotate_right")
    {
      delay(2000);
      Serial.print("Rotated Right.\n");
    }

    else if (rotate_dir=="rotate_left")
    {
      delay(2000);
      Serial.print("Rotated Left.\n");
    }

  delay(1000);
}
}