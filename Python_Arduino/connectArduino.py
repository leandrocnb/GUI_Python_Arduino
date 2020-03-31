import serial

port = "/dev/ttyACM0"
seralSpeed = 9600

def ledArduino(option):
    connect = serial.Serial(port, seralSpeed)

    if (option != 2):
        connect.write(option.encode())
    
    connect.close()

