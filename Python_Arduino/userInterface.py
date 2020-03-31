import PySimpleGUI as sg
import connectArduino as arduino

sg.theme('DarkAmber')
layout = [
    [sg.Text('Led Power On/Off')],
    [sg.Button('ON', key='on'), sg.Button('OFF', key='off')],
    [sg.Button('Exit', key='exit')]
]
# Windows
windows = sg.Window('Arduino GUI Python', layout, size=(400,100))

while True:
    event, values = windows.read()
    if(event == 'on'):
        print('on')
        arduino.ledArduino('1')
    elif(event == 'off'):
        print('off')
        arduino.ledArduino('0')
    elif(event == 'exit'):
        break

windows.close()
