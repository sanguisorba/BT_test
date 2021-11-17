import serial

ser = serial.Serial('COM14', 9600, timeout=0.1)

# change COM# to match your environment
# write the code here such as


ser.write(b'1,150Z')
ser.write(b'2,40Z')
# syntax: [DEFINED SERVO NUMBER],[DEGREE]Z
# Z is a symbol used to indicate the end of communication.

# do not forget to close port!
ser.close()