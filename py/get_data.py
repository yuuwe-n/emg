#!/usr/bin/env python3

import serial
import csv
import datetime as dt
import platform

date = (dt.datetime.now().strftime("%Y%m%d%H%M%S"))

file = "data/" + date + ".csv"
print(file)

pf = platform.system()
match pf:
	case "Windows":
		ser = serial.Serial('COM3')
	case "Darwin":
		ser = serial.Serial('/dev/cu.usbmodem2101')

# if macos use '/dev/cu.usbmodem2101'
# ls /dev/tty* | grep usb

#ser = serial.Serial('/dev/cu.usbmodem2101') # macos
#ser = serial.Serial('COM3') # windows

ser.baudrate = 9600

if not ser.isOpen():
    ser.open()

with open(file, 'w', newline='') as f:
	w = csv.writer(f)
	while True:
		res = ser.readline()
		w.writerow([res.decode('utf-8')])
		print(res.decode('utf-8'))
		
