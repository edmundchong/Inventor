### Edmund Chong, Lida Pentousi
- PC with at least GeForce RTX 2060 for online SLEAP inference in bonsai
  - GeForce RTX 3050 VENTUS 2X 6G (cheaper than the RTX 2060) also works
- Neodymium magnets
  - 14 total of 5mm diameter x 3mm thickness (RS Components 2192234)
    - 6 on liquid port 3d print
    - 4 on cover
    - 4 on cheeseboard to mate with fixation
  - 24 total of 5mm diameter x 5mm thickness (RS Components 2192245)
    - 6 on W wall to mate with liquid port
    - 4 on cover mount to mate with cover
    - 10 for S wall door
    - 4 on fixation base
  - **MAGNET POLARITIES**
    - standardized (identical across boxes)
    - I keep a pair of reference magnets colored red and black, which i color all mating magnet surfaces in the box 
- T-slot nut
  - RS Components 180-9104, for 20mm strut with 5mm groove
    - there are multiple variations of this part which will fit, this one has extra ball bearing and side grooves for snap grip
  - 14 total
    - 4 for cover mount
    - 6 for LED mount
    - 2 for touchscreen mount
    - 2 for cameras
- 2 x piezo buzzers
  - RS Components 724-3150
  - RS PRO 88dB Panel Mount Square Wave External Piezo Buzzer, 41 x 30 x 5.5mm, 1V ac Min, 30V ac Max
  - drill holes for M3 screw (one side is sufficient)
    - there is barely enough room for screw cap to fit, so drill slightly off-center
    - mount with M3 t-slot nut in strut (RS 180-9102)
      - one on north-west strut facing west
      - one on north-east strut facing north
- DC plug 2.1mm pin diameter, female end, RS 771-9186
  - 9 total
  - 2 for LED strips
  - 2 for buzzer, buzzer end
  - 2 for buzzer, arduino end
  - 1 for lick board
- DC plug 2.1mm pin diameter, male (pin end), RS 810-4605
  - 8 total
  - 4 for buzzers (2 each at arduino and buzzer end)
  - 3 for LED strips
  - 1 for lick board
 

- general: useful for mounting MIMEIMIAI Self Adhesive Tape, Double Sided Tape Heavy Duty Two Sided Sticky Pads Strong Wall Adhesive Strips No Marks Reusable Clear Nano Tape for Picture Hanging Carpet Glue
- cable management: velcro cable ties, loom cable sleeve or velcro cable sleeves

### Laser Cutting Instructions 
1. Calibrate the laser cutter
- Turn on the laser cutter
- Lower the stage using up down arrows
- Load acrylic sheet (make sure its flat)
- Move laser closer to you using the xyz arrows
- Place metal calibrator on laser
- Slowly raise platform using up down arrows, until calibrator falls off

2. Loading project
- Download PDF design from the corresponding GitHub folder
- Open CorelBoard
- Open new project and import as curves
- Change size of arena to 720 x 430

3. Preparing cut design in CorelBoard
- Select any lines that are not red or black and delete them
- Select the entire drawing and change thickness to hairline
- Press print job to send to TROTEC

* If you want to cut multiple designs at the same time on one acrylic, you can select the entire design in CorelBoard, and copy/paste so a duplicate appears adjacent *

4. Prepare cut design in TROTEC
- Open TROTEC
- The job should appear from CorelBoard. Double click on it to load it
- Double click on the grey panel to see details of the design
- Open material templates and make sure that correct colours and thickness is selected (skip black, cut red, set to acrylic 3mm)

5. Press START

*If you need to go back and engrave, you can JOB RESET in TROTEC, change to acrylic 5mm deep engrave, and run again. This will engrave anything thats in in black in your design*
