#!/usr/bin/env python3

import serial
import datetime as dt
import platform
import time

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation



pf = platform.system()
match pf:
	case "Windows":
		ser = serial.Serial('COM3')
	case "Darwin":
		# if macos use '/dev/cu.usbmodem2101'
		# ls /dev/tty* | grep usb
		ser = serial.Serial('/dev/cu.usbmodem2101')

ser.baudrate = 9600

if not ser.isOpen():
    ser.open()


while True:
	r = ser.readline().decode('utf-8')
	print(r)

plt.axis([0, 100, 0, 1023])
#tic=time.time()
time = 0

while True:
	r = int(ser.readline().decode('utf-8'))
	print(r)
	plt.xlim(time - 20,right=time)
#	y = np.random.random()
	y = r
	plt.scatter(time, y, c='k')
	plt.pause(0.05)
	time+=1

plt.show()
