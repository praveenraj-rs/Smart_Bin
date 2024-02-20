#!/usr/bin/python3
import serial
import time
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()
while True:
        string = input("enter string:")
        string = string +"\n"
        string = string.encode('utf_8')
        ser.write(string)
        line = ser.readline().decode('utf-8').rstrip()
        print("received: ",line)
        time.sleep(1) #delay of 1 second
