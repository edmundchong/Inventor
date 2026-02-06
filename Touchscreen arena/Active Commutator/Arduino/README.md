## Notes

The original arduino sketch from the paper was replaced by the following adapted version. This is the one you want to upload (the others are previous iterations):

**Sketch_torque_commutator_v15_AR_latest - Adapted version** 
- Written for the RP2040 seeeduino model (the original sketch from the paper is for the XIAO ESP32C3, but the RP2040 is cheaper + available on RS)""
- Sketch drives the stepper motor based on hall sensor inputs from the left and right magnets:
  - If Hall A is active -> spins left for as long as hall A is active
  - If Hall B is active -> spins right for as long as hall B is active
- Calibration features
  - Has 3 variables that can be adapted to fine tune and calibrate the commutator:
  - **stepDelayUs** : Changes the speed of the motor
  - **HALL_DEBOUNCE_MS** : Adjusts for noise
  - **DEAD_ZONE_MS**: Ensures debounced directional signal persists for long enough before motor initialises
- Instructions on how to tweak these parameters are included in the sketch

**If you want to just test that your sketches are uploading and running, you can use the blink test to check if you can activate your LEDs aka if the board received the sketch** 

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
- Take your magnet, and hold it close to the left hall sensor on the PCB. If your commutator works and the polarity of the magnet is correct, the stepper driver should rotate the commutator left. Vice versa, if you hold the magnet to the right hall sensor, it should rotate right.
- Listen out to make sure the motor is turning smoothly and quietly. If its stuttering and getting stuck, unplug it and make sure the gears turn smoothly without bumping anything.
- Once you determine which side of the magnet activates the hall sensors, mark this side with a sharpie. Make sure both magnets on the magnet holder are mounted in the same orientation, and the side marked with sharpie is the one facing the hall sensors when mount the screw with the hook
- Once everything is assembled, plug the commutator in to your computer, and mount two spi cables. Make sure the commutator spins as expected when you turn the cables.

## Troubleshooting 
- If the commutator isn't responsive, check that the magnets are close enough to the hall sensors.
- Check that the screw is mounted tightly to the ball bearing **it should not spin freely and continiously. It should stop once it hits the two walls in the 3D print**. To make it tighter, make sure you hot glue the hook onto the screw, and use two brass inserts to tighten the screw to the ball bearing
- If the motor is stuttering, this is usually something in your sketch logic. **Its important to fix this, as the stutter can cause noise in the ephys**
- Also make sure your magnet holder isn't directly bumping the hall sensors, as this can cause the sensors to bend over time and break. The magnets should be just below the sensors. 
