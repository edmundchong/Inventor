# Important notes for electronics build 

## Soldering of slip ring wires to PCB
- The quality of the soldering from the 12 slip ring wires to the OE1 / 0E2 banks on the PCBs is **really important**.
- Any poor solder joint (cold joint, partial contact or excess solder bridging) can add extra resistance and variable impedance. This can introduce microphonic noise, pick up RF interference, or create unstable connections that show up as false spikes or drift in your recordings.
- **What to check:** After soldering, you want to verify that each wire has a low, stable resistance to its corresponding pin on the other side, and that there are no shorts between adjacent channels.

## Quality checking slip ring connections 
**After soldering each joint**
1. Visual inspection
- Look for shiny, smooth solder (dull/grainy = cold joint).
- Ensure no stray solder bridges between pads.
- Tug gently on each wire with tweezers — it should not move.

**Electrical continuity & resistance**
1. Path check (per channel)
- Set multimeter to resistance mode.
- Probe from bottom PCB pin → slip ring → top PCB pin.
- Expect a small, consistent resistance (often < 5–10 Ω, depending on slip ring spec).
- All 12 channels should be in the same ballpark; one that’s higher = bad joint.

2. Short check (between neighbors)
- Measure resistance between adjacent solder pads/pins.
- Should read “open circuit” (infinite / >1 MΩ).
- If you see continuity = solder bridge or wire strand touching.

**Optional impedance test (if your headstage/software supports it)**
1. System impedance measurement
- Connect the slip ring assembly as if it were a probe.
- Run the headstage impedance test at 1 kHz.
- Channels should all cluster in a similar low range (tens of kΩ is normal for wiring).
- A channel with very high impedance (>>100 kΩ) = bad or open joint.
- A channel with near-zero impedance = shorted channel.

**Stress test**
1. Mechanical wiggle test
- While measuring resistance or continuity, gently flex the slip ring and tug the wires.
- Watch for resistance fluctuations or intermittent opens.
- If it changes, the joint is mechanically unstable → reflow solder.

## Troubleshooting Guide

| Symptom                                | Likely Cause                              | Fix                                                                 |
|----------------------------------------|-------------------------------------------|---------------------------------------------------------------------|
| Channel has no signal / infinite resistance | Cold joint or broken wire                  | Reflow solder, ensure wire is fully wetted, trim & resolder if needed |
| Channel has much higher resistance than others | Partial contact, too little solder, or cracked joint | Add flux and reflow, or desolder and redo joint                      |
| Channel reads near zero Ω to neighbor  | Solder bridge or stray wire strand        | Wick away excess solder, clean pad, resolder carefully              |
| Resistance changes when wire is moved  | Mechanically unstable joint               | Reflow solder, ensure strain relief on wires                        |
| Excess noise on specific channel during recording | High impedance or intermittent joint       | Check with impedance test, reflow or replace joint                  |

