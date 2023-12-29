import RPi.GPIO as GPIO
import time
import json
import os

def measure_fill_percent_org():
    predicted_label="organic"

    def setup_ultrasonic():
        GPIO.setmode(GPIO.BCM)

        # Define GPIO pins
        TRIG_PIN = 25
        ECHO_PIN = 8

        # Set TRIG as OUTPUT
        GPIO.setup(TRIG_PIN, GPIO.OUT)

        # Set ECHO as INPUT
        GPIO.setup(ECHO_PIN, GPIO.IN)

        return TRIG_PIN, ECHO_PIN

    def get_distance(TRIG_PIN, ECHO_PIN):
        GPIO.output(TRIG_PIN, GPIO.LOW)
        time.sleep(0.1)

        GPIO.output(TRIG_PIN, GPIO.HIGH)
        time.sleep(0.00001)
        GPIO.output(TRIG_PIN, GPIO.LOW)

        while GPIO.input(ECHO_PIN) == GPIO.LOW:
            pulse_start_time = time.time()

        while GPIO.input(ECHO_PIN) == GPIO.HIGH:
            pulse_end_time = time.time()

        pulse_duration = pulse_end_time - pulse_start_time
        distance = pulse_duration * 17150
        distance = round(distance, 1)

        return distance

    def update_fill_percent_json(predicted_label, fill_percent):
        if predicted_label not in ["plastic", "paper", "other", "organic"]:
            print("Invalid predicted label. Supported labels: plastic, paper,other, organic")
            return

        fill_percent_data = {}

        # Load existing data if the file exists
        if os.path.exists("fill_percent_data.json"):
            with open("fill_percent_data.json", "r") as json_file:
                fill_percent_data = json.load(json_file)

        fill_percent_data[predicted_label] = fill_percent

        with open("fill_percent_data.json", "w") as json_file:
            json.dump(fill_percent_data, json_file)


    # Main function logic
    TRIG_PIN, ECHO_PIN = setup_ultrasonic()

    bin_height = 10  # In cm
    bin_to_us = 10  # Distance between bin to ultrasonic (n cm)
    distance = get_distance(TRIG_PIN, ECHO_PIN)
    percentage = ((bin_height - (distance - bin_to_us)) / bin_height) * 100
    percentage = max(0, min(100, round(percentage)))  # Ensure percentage is within 0 to 100

    update_fill_percent_json(predicted_label, percentage)  # Update the JSON file

    # Return the updated JSON file
    with open("fill_percent_data.json", "r") as json_file:
        updated_json_data = json.load(json_file)

    print(f" - Fill Levels: {updated_json_data}")

    return updated_json_data

if __name__=="__main__":
    measure_fill_percent_org()
    GPIO.cleanup()

