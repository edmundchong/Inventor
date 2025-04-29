# Pump Mount Step by Step Assembly 

## Materials 
1. **3D printed holder**
    - Link:
    - Print settings:
2. **Pump**
    - Item: Kamoer 1.2-90ml/min KPP Peristaltic Pump 12V 24V 6V DC Motor Self-priming Pump with Silicone Tubing Lab Dosing Pump for Lab
    - Supplier: AliExpress
    - Link: https://www.aliexpress.com/i/1852036314.html
    - Quantity per rig: 1
3. **Toggle Switch**
    - Item:RS PRO Toggle Switch, Panel Mount, On-Off, SPST, Solder Terminal, 28V dc (RS 734-7154)
    - Supplier: RS
    - Link: https://uk.rs-online.com/web/p/toggle-switches/7347154?searchId=40e3badb-6315-4550-8cfd-91f607878b3e&gb=s
    - Quantity per rig: 1
4. **Screws (M5 x 10mm; length excludes height of cap (5mm))**
    - Item: RS PRO M5 x 10mm Hex Socket Cap Screw Plain Stainless Steel
    - Supplier: RS
    - Link: https://uk.rs-online.com/web/p/socket-screws/0281063?gb=a
    - Quantity per rig: 1
5. **T-slot Nut** 
    - Item: RS PRO M5 T-Slot Nut, Connecting Component, Strut Profile 20 mm, Groove Size 5mm (RS 180-9104)
    - Supplier: RS
    - Link: https://uk.rs-online.com/web/p/connecting-components/1809104?searchId=761d0ca9-372a-4596-b0c9-1cd5329688ca&gb=s
    - Quantity per rig: 1

## Assembly Steps (holder)

1. Print the holder and check that the pump fits snugly (don't push all the way in, as its difficult to get back out!)
2. Solder all the electronics (detailed instructions below; remember to insert the switch into the holder before soldering it to the pump)
3. With the pump half mounted in the holder, screw in the holder to the strut via the T slot nut
4. Once screwed in, you can push the pump in the rest of the way into the holder. 

## Assembly Steps (electronics)

## Materials
    - Breadboard with shield
    - Arduino Uno
    - Wires
    - Soldering iron
    - Wire cutter
    - Shrink wrap
    - Pins
    - Pump
    - Switch
    - 12V power supply

**Wiring Key**
! The colours don't matter for the wiring - Below describes the wiring key you can see in the example photo !

Yellow wires: Pump (connects to +ve and -ve terminals)
Grey wires: Physical switch
Pink wires: Arduino relay (connects to "closed" and "normally open" ports)
Pink/white wires: Power supply
! +ve connections are marked with green sharpie on the wire and -ve connections are marked with blue. On the power cable, pink is +ve and white is -ve !

    **Instructions**
        1. Make a power supply wire
    2. Cut a pink and white wire (approx 1 meter) and strip the ends
    3. Solder single pin to one end of each wire. This end will connect to the breadboard, the other can be naked wire that connects to shutters on female barrel jack
    4. The pink wire is +ve and the white is -ve
    5. Connect the +ve and -ve pins on seperate terminal strips on the breadboard (ie rows 20 and 21)
    6. Make a bank of 3 pins
    7. Cut 3 wires (approx 0.5 meter); two yellow (for pump) and one grey for switch). Strip the ends
    8. Solder the 3 wires onto a bank of 3 pins, as instructed in the diagram (yellow wires should be next to eachother)
    9. Connect the bank of 3 parallel to the power supply pins on the breadboard (ie so the bank of 3 spans 3 rows on the breadboard)
    Make a bank of 2 pins
    Cut 2 pink wires (approx 10cm) and strip the ends
    Solder the two wires to a bank of 2 pins. The other sides can be naked, they will connect to the arduino
    Connect the bank of 2 parallel to the bank of 3 on the breadboard, with the wire connecting to the closed port on the arduino in the middle port (in relation to the bank of 3)
    Make a grey switch wire
    Cut a grey wire (approx 0.5 meter) and strip the ends. This wire is the second one you need to connect the switch (the first is already in the bank of 3)
    Solder a single pin to one end of the wire
    Connect this pin on the middle row (in relation to the bank of 3), so that it's next to the wire connecting to the closed port on the arduino
    Connect the hardware
    Connect and solder the grey wire on the bank of 3 to one terminal on the physical switch. Connect the other single grey wire to the other terminal on the switch
    Connect and solder the two yellow wires on the bank of 3 to the pump. The +ve terminal on the pump should connect to the middle yellow wire in the bank of 3, and the -ve terminal should connect to the outermost yellow wire in the bank of 3.
    Connect the bank of 2 pink wires to the relay on the arduino shield. The middle wire (in relation to the bank of 3) connects to the "closed" port and the outermost wire connects to the "normally open" port
    Connect the power
    Plug in the power supply to the female barrel jack, and turn on at the wall
    Test the pump comes on and off via the physical switch connected by grey wires
    Plug the arduino into your PC, and upload the valve.ido file
    Test that the pump can be activated via the arduino code




