import tkinter as tk
from tkinter import font, ttk, messagebox
import serial
import serial.tools.list_ports

# ---------------- SETTINGS ----------------
BAUD_RATE = 115200
ser = None
# ------------------------------------------


def auto_select_arduino():
    """
    Look for Arduino/Seeeduino automatically.
    Returns COM port name (e.g. 'COM4') if found, otherwise None.
    """
    ports = serial.tools.list_ports.comports()
    for port in ports:
        desc = port.description.lower()
        if "arduino" in desc or "seeeduino" in desc or "ch340" in desc or "usb serial" in desc:
            return port.device
    return None


def refresh_ports():
    """Scan available COM ports and update dropdown."""
    ports = serial.tools.list_ports.comports()
    port_list = [port.device for port in ports]
    port_dropdown['values'] = port_list

    if not port_list:
        port_var.set("")
        update_status("No serial devices found.")
        return

    auto = auto_select_arduino()
    if auto and auto in port_list:
        port_var.set(auto)
        update_status(f"Auto-detected {auto}")
    else:
        port_var.set(port_list[0])
        update_status("Select COM port to connect.")


def connect_port():
    """Connect to the selected COM port."""
    global ser
    selected_port = port_var.get()
    if not selected_port:
        messagebox.showerror("Error", "No COM port selected!")
        return

    try:
        ser = serial.Serial(selected_port, BAUD_RATE, timeout=1)
        update_status(f"Connected to {selected_port}")
        connect_button.config(state="disabled")
        refresh_button.config(state="disabled")
        port_dropdown.config(state="disabled")
    except serial.SerialException:
        messagebox.showerror("Error", f"Could not open {selected_port}")
        update_status("Connection failed.")


def send_command(command, status_message):
    """Send a single-character command to Arduino."""
    if ser and ser.is_open:
        try:
            ser.write(command.encode())
            update_status(status_message)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to send command: {e}")
    else:
        messagebox.showwarning("Not Connected", "Please connect to a COM port first.")


def update_status(message):
    status_var.set(f"Status: {message}")


# ---------------- GUI SETUP ----------------
root = tk.Tk()
root.title("Commutator Controller")
root.geometry("420x340")
root.resizable(False, False)

# Fonts
title_font = font.Font(family='Helvetica', size=16, weight='bold')
button_font = font.Font(family='Helvetica', size=12)

# Title
tk.Label(root, text="Commutator Controller", font=title_font).pack(pady=10)

# COM Port Frame
port_frame = tk.Frame(root)
port_frame.pack(pady=5)
tk.Label(port_frame, text="Select COM Port:", font=('Helvetica', 11)).grid(row=0, column=0, padx=5)

port_var = tk.StringVar()
port_dropdown = ttk.Combobox(port_frame, textvariable=port_var, state="readonly", width=15)
port_dropdown.grid(row=0, column=1)

connect_button = tk.Button(port_frame, text="Connect", font=('Helvetica', 10), command=connect_port)
connect_button.grid(row=0, column=2, padx=5)

refresh_button = tk.Button(port_frame, text="↻", font=('Helvetica', 10), command=refresh_ports)
refresh_button.grid(row=0, column=3, padx=3)

# Status
status_var = tk.StringVar(value="Status: Not Connected")
tk.Label(root, textvariable=status_var, fg="blue", font=('Helvetica', 11)).pack(pady=10)

# Button Frame
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

tk.Button(button_frame, text="Spin Left", font=button_font, width=15,
          command=lambda: send_command("L", "Spinning Left (Manual)")).grid(row=0, column=0, padx=10, pady=5)

tk.Button(button_frame, text="Spin Right", font=button_font, width=15,
          command=lambda: send_command("R", "Spinning Right (Manual)")).grid(row=1, column=0, padx=10, pady=5)

tk.Button(button_frame, text="Stop (Auto)", font=button_font, width=15,
          command=lambda: send_command("S", "Running Automatically")).grid(row=2, column=0, padx=10, pady=5)

# Initialize ports
refresh_ports()

root.mainloop()

