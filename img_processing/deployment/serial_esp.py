import serial

# Configure the serial port
ser = serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=1)

def send_data_to_esp(data):
    # Write data to the serial port
    ser.write(data.encode())
    print(f" - Sent data to ESP: {data}")

def read_data_from_esp():
    # Read data from the serial port
    received_data = ser.readline().decode().strip()
    return received_data

if __name__ == "__main__":
    send_data_to_esp("plastic")

    # Wait for a moment to allow the ESP to respond
    # You may need to adjust the delay based on your communication requirements
    ser.timeout = 5

    received_data = read_data_from_esp()
    print(f" - Received data from ESP: {received_data}")

    ser.close()

