# Setting up top cam for ephys 

## Notes
- Camera is connected via a BNC cable, which outputs 3 pins (green = GPIO IN, blue = GPIO OUT and brown = GND)
- The oscilloscope isn't necessarily in or out, it can be connected to both to measure voltage during input AND output
- Everything that is connected should have a common ground on the breadboard
- General circuitry is:
  - Input for camera (GPIO IN), oscilloscope (channel 1) and arduino
  - Output for camera (GPIO OUT), oscilloscope (channel 2) and open-ephys box

## Materials 
- 3 BNC cables with + and - wires (1 x oscilloscope channel 1, 1 x oscilloscope channel 2, 1 x open ephys box)
- Breadboard
- Arduino
- Braided cable with + and - wires (for connecting breadboard to arduino)

## Breadboard layout 
- Row 1 (INPUT): GPIO IN (camera green wire) -> BNC + (goes to oscilloscope channel 1) -> Arduino + (goes to digital pin on arduino)
- Row 2 (OUTPUT): GPIO OUT (camera blue wire) -> BNC + (goes to oscilloscope channel 2) -> BNC + (goes to open ephys)
- GND RAIL: GPIO GND (camera brown wire) -> Arduino - (goes to GND pin on arduino) -> All the black BNC - wires (oscilloscope 1/2 and open ephys)

- 
