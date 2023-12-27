import RPi.GPIO as GPIO
import time

# GPIO mode to BCM
GPIO.setmode(GPIO.BCM)

# GPIO pin for the flashlight
flashlight_pin = 20

# The GPIO pin as an output
GPIO.setup(flashlight_pin, GPIO.OUT)

def turn_on_flashlight():
    GPIO.output(flashlight_pin, GPIO.HIGH)
    print(" - Flashlight Turned On")

def turn_off_flashlight():
    GPIO.output(flashlight_pin, GPIO.LOW)
    print(" - Flashlight Turned Off")

if __name__ == "__main__":
    turn_on_flashlight()
    time.sleep(5)
    turn_off_flashlight()
    GPIO.cleanup()

