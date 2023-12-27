from gpiozero import MotionSensor
from flashlight_control import turn_on_flashlight,turn_off_flashlight
from image_capture import capture_image
from image_process import process_captured_image
from serial_esp import send_data_to_esp
from fill_measure import measure_fill_percent
from lcd_display import lcd_display 

# GPIO pin for the IR sensor
IR_SENSOR_PIN = 17

# Initialize the motion sensor
motion_sensor = MotionSensor(IR_SENSOR_PIN)

def on_motion():

    print(" - Motion detected")
    
    # Turning Flashlight On
    turn_on_flashlight()

    # Call the image capture function
    capture_image()

    # Turning Flashlight Off
    turn_off_flashlight()

     # Call the image processing function
    predicted_label = process_captured_image("captured_image.jpg")

    # Sending the predicted lable to esp for stepper rotation
    send_data_to_esp(predicted_label)

    # Measuring the bin fill level and updating it in json file
    measure_fill_percent(predicted_label)

    # Displaying the fill level to LCD from json file
    lcd_display()

    # Display a final message
    print(" - Classification Completed Successfully\n\n")

# Attach the on_motion function to the motion sensor
motion_sensor.when_motion = on_motion

try:
    print("Waiting for motion...")
    # Keep the script running
    while True:
        pass

except KeyboardInterrupt:
    print("Script terminated by user.")

