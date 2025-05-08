# Buzzer Electronics

## Components
- 3 buzzers with positive and negative pin wires
- Arduino Uno
- USB power supply (arduino -> computer)

## Notes 
- Connections are made directly to the arduino (no breadboard)
- White goes to ground on arduino
- Make sure the arduino is disconnected when making changes to wiring

## Instructions 
1. Make sure your buzzer wires are labelled (left buzzer, middle buzzer, right buzzer)
2. Connect pins of buzzer wires to the following arduino ports:

`Middle_buzzer_white_wire` -> `any GND on arduino`

`Middle_buzzer_pink_wire` -> `pin 3`

--

`Left_buzzer_white_wire` -> `any GND on arduino`

`Left_buzzer_pink_wire` -> `pin 6`

--

`Right_buzzer_white_wire` -> `any GND on arduino` 

`Right_buzzer_pink_wire` -> `pin 9`

3. Upload 3 buzzer ido to arduino via USB
4. Test buzzers using bonsai hardware tester

## Hardware testing using Bonsai 
1. Once you've uploaded your sketch, open C:Drive -> clamlab -> bonsai -> Touchscreen_pSWM_v02 -> hardware testers
2. Check that bonsai is looking for the correct COM port (should match the arduino COM port - you can check this in arduino IDO -> tools -> port)
  - If port in bonsai doesn't match port in arduino IDO, navigate to rig params on the bonsai computer, and edit the COM number.
4. In the bonsai hardware tester, navigate to component testers (press once). On the right hand side you'll see the keyboard short cuts to test your buzzers
5. Run the bonsai work flow and press each of the keys to sound the buzzers
6. If any buzzers fail, try the following troubleshooting:
   - Make sure all the pins are secure in the breadboard (sometimes they come out)
   - Unplug the arduino and plug back in; re-upload the sketch and test again
   - Check the connection at the female jack end
   - Switch out the buzzer for another, to see if the buzzer itself is faulty
   - If all else fails, cry to edmund

