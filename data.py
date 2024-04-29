import matplotlib.pyplot as plt
import serial

# if macos use '/dev/cu.usbmodem2101'
# ls /dev/tty* | grep usb

ser = serial.Serial('/dev/cu.usbmodem2101') # macos
#ser = serial.Serial('COM3') # windows

ser.baudrate = 9600

if not ser.isOpen():
    ser.open()

while True:
    res = ser.readline()
    print(res.decode('utf-8'))
