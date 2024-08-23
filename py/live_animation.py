#!/usr/bin/env python3

# THIS DOES NOT WORK RN, WILL WORK LATER

import serial
import csv
import datetime as dt
import platform
import time

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = ax.plot([], [], 'ro')

def init():
    ax.set_xlim(0, 100)
    ax.set_ylim(0, 1023)
    return ln,

def update(frame):
    xdata.append(frame)
    ydata.append(1023*np.sin(frame))
    ln.set_data(xdata, ydata)
    return ln,

ani = FuncAnimation(fig, update, frames=np.linspace(0, 100, 128),
                    init_func=init, blit=True)
plt.show()

#plt.axis([0, 1, 0, 1])
#
##tic=time.time()
#time = 0
#
#while True:
#    time+=1
#    plt.xlim(0,right=time)
#    y = np.random.random()
#    plt.scatter(time, y)
#    plt.pause(0.05)
#
#plt.show()



# if macos use '/dev/cu.usbmodem2101'
# ls /dev/tty* | grep usb

#ser = serial.Serial('/dev/cu.usbmodem2101') # macos
#ser = serial.Serial('COM3') # windows




### if not ser.isOpen():
###     ser.open()
### 
### with open(file, 'w', newline='') as f:
### 	w = csv.writer(f)
### 	while True:
### 		res = ser.readline()
### 		w.writerow([res.decode('utf-8')])
### 		print(res.decode('utf-8'))
		
