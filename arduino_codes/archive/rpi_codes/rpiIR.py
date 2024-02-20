import RPi.GPIO as GPIO
import time

# Set up GPIO
GPIO.setmode(GPIO.BCM)
IR_PIN = 4  # Change this to the GPIO pin you've connected the IR sensor to

GPIO.setup(IR_PIN, GPIO.IN)

try:
    print("Motion detection program starting...")

    while True:
        if GPIO.input(IR_PIN) == GPIO.HIGH:
            print("Motion detected!")
        else:
            print("No motion detected.")

        time.sleep(1)  # Adjust the sleep duration as needed

except KeyboardInterrupt:
    print("Program terminated by user.")
finally:
    GPIO.cleanup()

