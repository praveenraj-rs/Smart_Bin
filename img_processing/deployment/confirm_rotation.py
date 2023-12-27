import serial
import time

def confirm_rotation(serial_port="/dev/ttyUSB0", baud_rate=9600):
    # Open the serial connection
    ser = serial.Serial(serial_port, baud_rate, timeout=1)

    try:
        while True:
            # Read a line from the serial port
            serial_data = ser.readline().decode('utf-8').strip()

            # Print the received data
            print("Waiting for Bin Rotation Confirmation:")

            # Check if the received data indicates rotation completion
            # if serial_data == "rotation_completed":
            if serial_data:
                print(" - Rotation completed. Received: ",serial_data)
                break

            # Add your processing logic here

            # Optional: Add a delay to avoid high CPU usage
            time.sleep(0.1)

    except KeyboardInterrupt:
        print("Script interrupted.")
    finally:
        # Close the serial connection when the script is terminated
        ser.close()
        print(" - Serial connection closed.")

# Call the function to start reading serial data
if __name__ == "__main__":
    confirm_rotation()

