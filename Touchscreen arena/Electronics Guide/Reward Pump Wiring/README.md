# Reward Pump Electronics

## peristaltic pump
- KPP-DC-S04W

## Wiring Key
---
**! The colours don't matter for the wiring - Below describes the wiring key you can see in the example photo !**

- **Yellow wires:** Pump (connects to +ve and -ve terminals)
- **Grey wires:** Physical switch
- **Pink wires:** Arduino relay (connects to "closed" and "normally open" ports)
- **Pink/white wires:** Power supply

**! On the pump / switch wires, +ve connections are marked with green sharpie on the wire and -ve connections are marked with blue (this is because both wires on the pump are yellow, and both wires on the switch are grey). On the power cable, pink is +ve and white is -ve !**

## Instructions 
 **! More detailed instructions can be found at https://github.com/clamlab/bonsai/blob/main/Valve/wiring/README.md !**

1. Solder two yellow wires to the pump (label the positive one green and negative blue)
2. Solder two grey wires to the switch (label positive and negative again)
3. Twist together the 2 yellow wires + the negative grey wire (-> creates a bank of 3 pins)
4. Connect pump wires, power supply and arduino to the breadboard according to the diagram in the folder
5. Connect power supply via the female jack 
6. Upload arduino sketch for the valve
7. Connect arduino to computer running bonsai, and use hardware tester to check the buzzers are working 
