## Notes

The original design uses the XIAO ESP32C3 microcontroller model, however an alternative .ino was compiled for use in the RP2040 model (this one is cheaper and also available on RS). There are 3 available sketches, which do the following:

### Originals from the OPEN-MAC paper

**sketch_torque_commutator – Interrupt Version (A7/A8/A9 pins)** 
- Function: Uses attachInterrupt() so the motor runs immediately when a Hall sensor changes state, independent of the loop() timing.
- Use when: You need fast, precise response to Hall sensor triggers, such as in high-speed or highly accurate commutator operation.

---

### Re-written sketches 

**Sketch_torque_commutator_v8_AR - Adapted SWC version** 
- Function: Drives stepper motor based on hall sensor inputs (auto left/right commutation) while also allowing manual rotations and other debugging functions via serial commands.
- Use when: You want a commutator that runs automatically with hall sensors but can be manually controlled or overridden through serial input.

**If you want to just test that your sketches are uploading and running, you can use the blink test to check if you can activate your LEDs aka if the board received the sketch**

For this, use the following sketch: 

**Blink_test**
- Function: Turns the small red LED on and off when you type ON, OFF and BLINK in the serial monitor at 115520 baud.
- Use when: You want to check the general function of your board

## Instructions for upload
- Connect SEEED to the host PC via the USB-C port, whilst holding down the B button on the board. This will launch it in bootloader mode
- Open Arduino IDE
- Navigate to file->preferences and then paste the following URL into the additional boards managers URL:
    - https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
- Restart IDE and navigate to boards manager. Install all the packages for Raspberry Pi Pico/RP2040/RP2350
- Navigate to tools -> board -> raspberry pi pico -> seeed rp2040
- Then navigate to port, and find the COM for your board
- Open the corresponding sketch
- Click upload

**!! COMMON ISSUES: For some reason, sometimes the sketch will get stuck in compiling and won't move on. Stop the compiling, unplug the board, and plug it back in, but not in bootloader mode. It should now come up as a board, instead of a ufp board**

## Instructions for testing motor
- Take your magnet, and hold it close to the left hall sensor on the PCB. If your commutator works, the stepper driver should rotate the commutator left. Vice versa, if you hold the magnet to the right hall sensor, it should rotate right.
- If the commutator is turning the wrong way, you should flip the orientation of the magnets in your magnet holder
