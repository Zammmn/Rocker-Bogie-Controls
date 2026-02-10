import tkinter as tk
import serial
import time

arduino=serial.Serial(port='COM5', baudrate=115200, timeout=1)
time.sleep(2)
arduino.reset_input_buffer()

root=tk.Tk()
root.title("Rover Controls")
root.geometry("500x300")

root.columnconfigure(0, weight=1)
root.rowconfigure(0, weight=1)

bttnFrame=tk.Frame(root)
bttnFrame.grid(row=0, column=0, sticky="nsew")

for i in range(3):
    bttnFrame.columnconfigure(i, weight=1)
for i in range(2):
    bttnFrame.rowconfigure(i, weight=1)
    
def send(cmd):
    arduino.write(f"{cmd}\n".encode())
    print("Sent:", cmd)

    response = arduino.readline().decode(errors="ignore").strip()
    if response:
        print("Arduino says:", response)
    
def forward(): 
    send('forward')    

def backward():
    send('backward')

def left():      
    send('left')
    
def right():     
    send('right')

def left_turn(): 
    send('left_turn')

def right_turn():
    send('right_turn')

bttnFwrd = tk.Button(bttnFrame, text="Forward", font=("Courier New", 10, "bold"), bg="lightgreen", fg="black", activebackground="lightgreen", command=forward)
bttnFwrd.grid(row=0, column=1, sticky="nsew")

bttnBwrd = tk.Button(bttnFrame, text="Backward", font=("Courier New", 10, "bold"), bg="lightgreen", fg="black", activebackground="lightgreen", command=backward)
bttnBwrd.grid(row=1, column=1, sticky="nsew")

bttnLeft = tk.Button(bttnFrame, text="Left", font=("Courier New", 10, "bold"), bg="lightgreen", fg="black", activebackground="lightgreen", command=left)
bttnLeft.grid(row=1, column=0, sticky="nsew")

bttnRight = tk.Button(bttnFrame, text="Right", font=("Courier New", 10, "bold"), bg="lightgreen", fg="black", activebackground="lightgreen", command=right)
bttnRight.grid(row=1, column=2, sticky="nsew")

bttnLftTrn = tk.Button(bttnFrame, text="Left Pt Turn", font=("Courier New", 10, "bold"), bg="lightblue", fg="black", activebackground="lightblue", command=left_turn)
bttnLftTrn.grid(row=0, column=0, sticky="nsew")

bttnRgtTrn = tk.Button(bttnFrame, text="Right Pt Turn", font=("Courier New", 10, "bold"), bg="lightblue", fg="black", activebackground="lightblue", command=right_turn)
bttnRgtTrn.grid(row=0, column=2, sticky="nsew")

key_map={
    'w': bttnFwrd,
    's': bttnBwrd,
    'a': bttnLeft,
    'd': bttnRight,
    'q': bttnLftTrn,
    'e': bttnRgtTrn
}

keys_pressed=set()

def key_press(event):
    key=event.keysym.lower()
    if key in key_map and key not in keys_pressed:
        keys_pressed.add(key)
        btn_name=key_map[key]
        btn_name.config(relief="sunken")
        btn_name.invoke()

def key_release(event):
    key=event.keysym.lower()
    if key in key_map and key in keys_pressed:
        keys_pressed.remove(key)
        btn_name=key_map[key]
        btn_name.config(relief="raised")
        
        if key == 'w' or key == 's':
            arduino.write(b'stop\n')
            print("Sent: stop")

root.bind("<KeyPress>", key_press)
root.bind("<KeyRelease>", key_release)

root.mainloop()
