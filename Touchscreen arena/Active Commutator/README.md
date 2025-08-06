# BUILD INSTRUCTIONS (OpenMac Active Commutator)

These build instructions are simplified, based on the OpenMac Commutator paper (https://www.sciencedirect.com/science/article/pii/S2468067223000366#s0045)

## Step 1: Print and prepare all 3D printed components 
  1. Submit all files in the STL folder to fablabs for printing.
  2. Secure brass inserts into all mounting holes with a soldering iron (M3 x 4mm into the slip ring stage, M2.5 x 5.7mm everywhere else)

## Step 2: Prepare slip ring
1. Cut off 6 wires on each side of the slip ring (you only need 28 wires total, however the senring slip ring only comes with 36; these are excess so get rid)
2. Seperate the remaining 30 wires into 3 bundles:
- SPI Channel A: 12 wires
- SPI Channel B: 12 wires
- Hall sensor: 4 wires
3. Strip the ends of all the wires

## Step 3:Prepare the top and bottom PCBs
1. Roger should be able to help you with this. Most of the components can be ordered already soldered onto the PCB, with the exception of the (1) hall sensors (2) omnetics connectors (3) 6 pin connector and (3) the microcontroller.
2. You'll need Roger to solder the SMD components (ie the omnetics connector), but the rest you should be able to do yourself with the diagrams from the paper

## Step 4: Center Assembly 
1. Insert the wider ball bearing into Center Case A, and close with Centre Case B. This sandwich is secured with M2.5 x 8mm screws
2. Mount the smaller gear onto the stepper motor. The stepper motor can then be directly mounted to centre case A (the two lower podiums)
3. Mount the wider gear onto center case B (the wide bearing)
4. Align the stepper motor to the main gear, and close the whole thing with the slip ring stage (secured with M2.5 x 8mm screws)
5. You can then mount the main top case B over the entire build (this is the main casing shaft, that forms the outside of the commutator). This is secured with 3 screws M2.5 x 8mm screws

## Step 5: Prepare top PCB
1. The top PCB mount is screwed into the main casing shaft (top case B) using 4 screws (M2.5 x 8mm)
2. The slip wing wires will be coming out below the top PCB, and can be threaded through the cut out in the PCB
3. Connect all the wires from the slip ring to the PCB as follows. There should be 3 bundles of connections on your top PCB:
  - Directly solder the 12 SPI wires to the T1-T6 and B1-B6 pins. Make a note of which colour goes where, as you will need to match this on the bottom PCB)
  - Insert the stepper motor wires (x4) into the JST pins located next to the stepper driver.
  - Solder (or connect via block connecter) the 4 hall sensor wires to the MCU OUT1 bank (there are 4 pins here: HALL A, GND, HALL B, POWER. On the PCB, this is labelled D1, GND, D2, 5V)

**NOTE: There is also a 2nd MCU OUT2 bank. You don't need this, its for an optional I2C connection**

5. The square 3D printed part is then sandwiched on top and secured with
