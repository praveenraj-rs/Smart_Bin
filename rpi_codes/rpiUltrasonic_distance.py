import RPi.GPIO as GPIO
import time

# Define GPIO pins
TRIG_PIN = 11 
ECHO_PIN = 12

def setup():
    # Set GPIO mode to BCM
    GPIO.setmode(GPIO.BCM)
    
    # Set TRIG as OUTPUT
    GPIO.setup(TRIG_PIN, GPIO.OUT)
    
    # Set ECHO as INPUT
    GPIO.setup(ECHO_PIN, GPIO.IN)

def get_distance():
    # Ensure TRIG is low
    GPIO.output(TRIG_PIN, GPIO.LOW)
    time.sleep(0.1)

    # Send a 10us pulse to trigger
    GPIO.output(TRIG_PIN, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(TRIG_PIN, GPIO.LOW)

    # Measure the pulse duration on ECHO
    while GPIO.input(ECHO_PIN) == GPIO.LOW:
        pulse_start_time = time.time()

    while GPIO.input(ECHO_PIN) == GPIO.HIGH:
        pulse_end_time = time.time()

    # Calculate distance in centimeters
    pulse_duration = pulse_end_time - pulse_start_time
    distance = pulse_duration * 17150
    distance = round(distance, 2)

    return distance

def cleanup():
    GPIO.cleanup()

if __name__ == "__main__":
    try:
        setup()
        while True:
            distance = get_distance()
            print(f"Distance: {distance} cm")
            time.sleep(1)

    except KeyboardInterrupt:
        print("Measurement stopped by user")
        cleanup()


