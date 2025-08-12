## Notes

The original design uses the XIAO ESP32C3 microcontroller model, however an alternative .ino was compiled for use in the RP2040 model (this one is cheaper and also available on RS). There are 3 available sketches, which do the following (interrupt version is better):

---
### For final version commutator

**sketch_torque_commutator – Interrupt Version (A7/A8/A9 pins)** 
- Function: Uses attachInterrupt() so the motor runs immediately when a Hall sensor changes state, independent of the loop() timing.
- Use when: You need fast, precise response to Hall sensor triggers, such as in high-speed or highly accurate commutator operation.

**RP2040 Adapted Sketch – Interrupt Version (D7/D8/D9 for motor, A1/A2 for Hall sensors)**
- Function:  Identical logic to Interrupt Version above, but pin numbers updated because the RP2040 does not have A7/A8/A9; now uses D7/D8/D9 for stepper control while keeping Hall sensors on A1/A2.
- Use when: Running on a Seeed XIAO RP2040 and need low-latency, reliable commutator control that matches the ESP32C3’s interrupt-driven behavior.

---
### For testing

**sketch_torque_commutator_XIAOESP32C3_LM – Polling Version (D7/D8/D9 pins)**
- Function: Continuously checks Hall sensors in the loop() using digitalRead() and runs the stepper if a sensor is active.
- Use when: You want simpler code for testing or slow-moving systems where missing quick Hall events is unlikely.

## Instructions for upload and testing
- Connect SEEED to the host PC via the USB-C port
- Open Arduino IDE
- Open the corresponding sketch
- Click upload
- Take your magnet, and hold it close to the left hall sensor on the PCB. If your commutator works, the stepper driver should rotate the commutator left. Vice versa, if you hold the magnet to the right hall sensor, it should rotate right.
- If the commutator is turning the wrong way, you should flip the orientation of the magnets in your magnet holder
