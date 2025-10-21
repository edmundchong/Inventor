import tkinter as tk
from tkinter import font
import serial
import serial.tools.list_ports
import threading
import time

# --------- SETTINGS ---------
COM_PORT = 'COM3'    # CHANGE THIS to your Seeeduino port
BAUD_RATE = 9600
# ----------------------------

# Try to open the serial port
try:
    ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
except serial.SerialException:
    ser = None
    print("Could not open serial port. Make sure Seeeduino is connected.")

# Command sending and status updates
def send_command(command, status_message):
    if ser and ser.is_open:
        ser.write(command.encode())
    update_status(status_message)

def update_status(message):
    status_var.set(f"Status: {message}")

# GUI Setup
root = tk.Tk()
root.title("Commutator Controller")
root.geometry("400x250")
root.resizable(False, False)

# Fonts
title_font = font.Font(family='Helvetica', size=16, weight='bold')
button_font = font.Font(family='Helvetica', size=12)

# Layout
title_label = tk.Label(root, text="Commutator Controller", font=title_font)
title_label.pack(pady=10)

status_var = tk.StringVar()
status_var.set("Status: Running Automatically")

status_label = tk.Label(root, textvariable=status_var, fg="blue", font=('Helvetica', 11))
status_label.pack(pady=5)

button_frame = tk.Frame(root)
button_frame.pack(pady=20)

tk.Button(button_frame, text="Spin Left", font=button_font, width=15,
          command=lambda: send_command("L", "Spinning Left (Manual)")).grid(row=0, column=0, padx=10, pady=5)

tk.Button(button_frame, text="Spin Right", font=button_font, width=15,
          command=lambda: send_command("R", "Spinning Right (Manual)")).grid(row=1, column=0, padx=10, pady=5)

tk.Button(button_frame, text="Stop (Auto)", font=button_font, width=15,
          command=lambda: send_command("S", "Running Automatically")).grid(row=2, column=0, padx=10, pady=5)

# Start GUI
root.mainloop()
