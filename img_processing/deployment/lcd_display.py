from RPi_GPIO_i2c_LCD import lcd
import json
from time import sleep

# Connect the VCC pin of the LCD to 5V on the Raspberry Pi.
# Connect the GND pin of the LCD to GND on the Raspberry Pi.
# Connect the SDA pin of the LCD to the SDA pin on the Raspberry Pi (GPIO2).
# Connect the SCL pin of the LCD to the SCL pin on the Raspberry Pi (GPIO3).

i2c_address = 0x27
lcdDisplay = lcd.HD44780(i2c_address)

def lcd_display():
    def read_fill_percent_data():
        # Read the fill_percent_data.json file
        try:
            with open("fill_percent_data.json", "r") as json_file:
                fill_percent_data = json.load(json_file)
            return fill_percent_data
        except FileNotFoundError:
            print("fill_percent_data.json not found.")
            return {}

    fill_percent_data = read_fill_percent_data()
    lcdDisplay.set(f"PC:{fill_percent_data['plastic']}%,PR:{fill_percent_data['paper']}%",1)
    lcdDisplay.set(f"OR:{fill_percent_data['other']}%,OC:{fill_percent_data['organic']}%",2)
    sleep(1)

    print(" - Displaying Fill Level Successful")
if __name__ == "__main__":
    lcd_display()

