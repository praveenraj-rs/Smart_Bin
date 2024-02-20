#!/usr/bin/env python3
import serial 
import time
ser = serial.Serial('/dev/ttyUSB0',9600, timeout=1) 
# Get rid of garbage/incomplete data
ser.flush()
# Infinite loop
while (1):
  # If there is data available
  if(ser.in_waiting > 0):
    # Read everything until the new line character
    # rstrip() function removes trailing characters like
    # the new line character '\n'
    line = ser.readline().decode('utf-8').rstrip()
    print(line)
