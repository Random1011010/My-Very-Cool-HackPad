# My Very Cool HackPad

A 6-key macropad with a rotary encoder (push-button) and a 128x32 OLED display, built around the Seeed Studio XIAO RP2040. The OLED runs an idle-animated "Luna" sprite that cycles through sit, walk, run, sleep, and work.

<img width="849" height="610" alt="Screenshot 2026-07-14 at 11 34 16 PM" src="https://github.com/user-attachments/assets/cbddc0a4-035f-4f72-b9ea-f4e8117912f8" />

## About me

I'm a Grade 10 (going into Grade 11) student, I am interested in aerospace, but I wanted to get real hands-on experience with hardware and PCB design before jumping into anything bigger. This was my first full custom PCB build, so a lot of this project was just learning by doing.

## Inspiration & Challenges

I wanted something I'd actually use, not just a demo board but rather, media controls, screen brightness, and a few shortcuts I use constantly (Spotlight, screenshot, undo/redo). The OLED also mattered to me too, I didn't want it just showing static text, so it runs a small animated character instead.

Most of the challenges were on the PCB and case side, since this was my first time doing either seriously. In KiCad, I had to fix a missing net label on one of the matrix columns, and ran into alignment issues while placing components that took a while to track down. Getting the rotary encoder's footprint right was its own thing.

The case went through a full rebuild. I first modeled it with not a clue how to I would get the keys to line up with the PCB, then rebuilt it in Fusion 360, sketch by sketch, to match Hack Club's submission format, while keeping the board dimensions (84x59.5mm), switch spacing, and heatset insert placement consistent with the original.

On the firmware side, I wrote the QMK code for the matrix, the encoder (volume normally, brightness when you hold the encoder's button), and the OLED animation, I adapted an open-source Luna sprite animation to loop continuously instead of reacting to typing, since I wanted it to feel more like a little idle character than a status display.
(Hopefully it works)

## Features

- 6-key matrix (2 rows x 3 columns)
- Rotary encoder with push-button:
  - Rotate: volume up/down (default)
  - Hold + rotate: screen brightness up/down
  - Short tap: play/pause
- 128x32 I2C OLED with an idle-animated Luna sprite
- QMK firmware, fully open source

## Bill of Materials (BOM)

| Part | Qty | Unit Cost | Total | Notes |
|---|---|---|---|---|
| Seeed Studio XIAO RP2040 | 1 | $5.00 | $5.00 | Main MCU |
| Cherry MX-style switches | 6 | $0.35 | $2.10 | |
| Keycaps | 6 | $0.30 | $1.80 | |
| Rotary encoder (EC11) with push-button | 1 | $0.90 | $0.90 | |
| 128x32 I2C OLED display (SSD1306) | 1 | $5.90 | $5.90 | |
| Custom PCB | 1 | ~$5.00 | $5.00 | 2-layer, JLCPCB/similar, price for small qty |
| 3D printed case | 1 | ~$3.00 | $3.00 | Filament cost estimate |
| M3 heatset inserts | 6 | $0.10 | $0.60 | |
| Diodes | 6 | $0.05 | $0.30 | 1N4148, one per switch |
| **Total** | | | **~$24.60** | |

## Pinout

| Function | Pin |
|---|---|
| Matrix rows | GP26, GP27 |
| Matrix cols | GP29, GP0, GP3 |
| Encoder A/B | GP2, GP1 |
| Encoder switch | GP28 |
| OLED SDA | GP6 |
| OLED SCL | GP7 |


## Photos

**Exploded View**
<img width="373" height="677" alt="Screenshot 2026-07-15 at 12 25 32 AM" src="https://github.com/user-attachments/assets/7a6177b6-1b59-43d4-8abd-2e0198ff7755" />

**Schematic:**

<img width="879" height="568" alt="Screenshot 2026-07-14 at 11 25 23 PM" src="https://github.com/user-attachments/assets/d2ba12f0-fa16-4f10-bf3f-f8df11843a6f" />


**PCB:**


<img width="561" height="411" alt="Screenshot 2026-07-14 at 11 26 05 PM" src="https://github.com/user-attachments/assets/362bf8d2-ab86-4b97-a7f0-7e22dd333056" />

**Case:**


<img width="702" height="512" alt="image" src="https://github.com/user-attachments/assets/96ba576f-3c5b-4ca6-879c-00fb683244d2" />


**Firmware**
Written in QMK. Full source is in the `firmware/` folder — see [`firmware/myverycoolpad/readme.md`](firmware/myverycoolpad/readme.md) for build/flash instructions.

**Status**
Parts haven't arrived yet, so the physical build and OLED orientation are untested. Firmware compiles cleanly with `qmk compile -kb myverycoolpad -km default`.
