# BUILD INSTRUCTIONS (OpenMac Active Commutator)

These build instructions are simplified, based on the OpenMac Commutator paper (https://www.sciencedirect.com/science/article/pii/S2468067223000366#s0045)

## Step 1: Print and prepare all 3D printed components 
  1. Submit all files in the STL folder to fablabs for printing.
  2. Secure brass inserts into all mounting holes (M3 x 4mm into the slip ring stage, M2.5 x 5.7mm everywhere else)

## Step 2: Prepare slip ring
1. Cut off 6 wires on each side of the slip ring (you only need 30 wires total, however the senring slip ring only comes with 36; these are excess so get rid)
2. Seperate the remaining 30 wires into 3 bundles:
- SPI Channel A: 12 wires
- SPI Channel B: 12 wires
- Hall sensor: 6 wires (2x VCC, 2x GND and 2x Signal)
3. Strip the ends of all the wires

## Step 3:Prepare the top and bottom PCBs
1. Roger should be able to help you with this. Most of the components can be ordered already soldered onto the PCB, with the exception of the (1) hall sensors (2) omnetics connectors (3) 6 pin connector and (3) the microcontroller.
2. You'll need Roger to solder the SMD components (ie the omnetics connector), but the rest you should be able to do yourself with the diagrams from the paper

## Step 4: Center Assembly 
1. Insert the wider ball bearing into Center Case A, and close with Centre Case B. This sandwich is secured with M2.5 x 8mm screws
2. Mount the smaller gear onto the stepper motor
3. Mount the wider gear onto center case B (the wide bearing)
4. Align the stepper motor to the main gear, and close the whole thing with the slip ring stage (secured with M2.5 x 8mm screws)
