import serial
import json

# Configure the serial port
ser = serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=1)

def bin_rotate(next_position):

    def current_position():
            # Read the fill_percent_data.json file
            try:
                with open("fill_percent_data.json", "r") as json_file:
                    fill_percent_data = json.load(json_file)
                return fill_percent_data["current_position"]
            except FileNotFoundError:
                print("fill_percent_data.json not found.")
                return {}

    def send_data_to_esp(data):
        # Write data to the serial port
        ser.write(data.encode())
        print(f" - Sent data to ESP: {data}")

    bins = ['plastic', 'paper', 'other']

    current_index = bins.index(current_position())
    next_index = bins.index(next_position)

    distance = (next_index - current_index) % len(bins)

    if distance == 1:
        send_data_to_esp("rotate_right")
    elif distance == 2:
        send_data_to_esp("rotate_left")
    elif distance == 0:
        send_data_to_esp("stay")
    else:
        print("Invalid positions")

if __name__=="__main__":
    next_position = 'plastic'
    bin_rotate(next_position)
