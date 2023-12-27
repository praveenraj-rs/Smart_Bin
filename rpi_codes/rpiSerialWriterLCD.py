#!/usr/bin/python3
# Writing and Reading the Serial Communication in rpi and displaying it in LCD 
from RPi_GPIO_i2c_LCD import lcd
import serial
import time
from time import sleep

i2c_address = 0x27
lcdDisplay = lcd.HD44780(i2c_address)
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()
while True:
        string = input("enter string:")
        string = string +"\n"
        string = string.encode('utf_8')
        ser.write(string)
        line = ser.readline().decode('utf-8').rstrip()
        lcdDisplay.set(line,1)
        print("received: ",line)
        time.sleep(1) #delay of 1 second
