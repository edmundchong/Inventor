# Lick Spout Wiring

## Notes 
- Full details can be found at https://github.com/clamlab/bonsai/tree/main/Lick/cap1188

## Materials 
1. Breadboard
2. CAP118
3. Arduino UNO
4. Jumpwire kit

## Intructions
- Prepare 2 banks of 13 pins
- Position the banks on the CAP118 (spanning from MOSI to AD / SDA TO IRQ) on both sides
- Solder the banks on the CAP118
- Insert the CAP118 onto a breadboard (specific position doesn't matter, but for guidance, you can position the SDA pin on i11 and the MOSI pin on f11)
- Use jump wires to connect the following pin assignments for I2C communication between the microcontroller and the CAP1188 sensor:

  `CAP1188_RESET`: Pin 9 (used to reset the sensor - optional)
  
  `CAP1188_GND` : Any ground pin
  
  `CAP1188_VIN` : 5V power pin
  
  `CAP1188_SDA` : Pin A4
  
  `CAP1188_SCK / SCL` : Pin A5

- Once connected, you need to connect your lick spout to the CAP118 sensor on the breadboard. This will be via a male jack that connects to the lick spout on one end, and a pin on the other end that connects to **CAP118_C8** on the breadboard.

*For the lick spout connection, there is no negative wire. Just a positive wire wrapped around the lick spout, connected to a female jack -> positive wire connected to male jack -> pin on C8 breadboard*

## Setup and Usage

1. **Upload the Sketch**: Once you've connected the CAP118 sensor to your arduino, use the Arduino IDE to upload the provided sketch to your board.
2. **Serial Monitor**: Open the Serial Monitor at a baud rate of 9600. You can then enter the following commands:
   - **0-7**: Adjust sensitivity.
   - **-1**: Reset the sensor and reapply configurations.
3. **Touch Detection**: As you touch the sensor inputs, the Serial Monitor will display the touched channels, and the corresponding LEDs on the sensor will light up.
