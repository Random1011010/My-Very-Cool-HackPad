# myverycoolpad

*A 6-key macropad with a rotary encoder (push-button), and an OLED display, built around the Seeed Studio XIAO RP2040.*

* Keyboard Maintainer: [Adhyan Mahindru](https://github.com/Random1011010)
* Hardware Supported: Seeed Studio XIAO RP2040
* Hardware Availability: Custom PCB, designed in KiCad; case designed in Fusion 360 (files in project repo)

## Features

- **6-key matrix** (2 rows x 3 columns) with media/shortcut keycodes (previous/next track, Spotlight, Mission Control, screenshot, undo/redo)
- **Rotary encoder** with push-button switch:
  - Rotate: volume up/down (default mode)
  - Hold the encoder switch to toggle into brightness mode, then rotate for screen brightness up/down
  - Short tap of the encoder switch: play/pause
- **128x32 I2C OLED display** running an idle-animated "Luna" sprite (sit/walk/run/bark/sneak cycle), adapted from [filterpaper/qmk_oled_animations](https://github.com/filterpaper/qmk_oled_animations)

## Pinout

| Function      | Pin  |
|---------------|------|
| Matrix rows   | GP26, GP27 |
| Matrix cols   | GP29, GP0, GP3 |
| Encoder A/B   | GP2, GP1 |
| Encoder switch| GP28 |
| OLED SDA      | GP6 |
| OLED SCL      | GP7 |

## Build/Flash

    qmk compile -kb myverycoolpad -km default

Put the XIAO RP2040 into bootloader mode (double-tap reset), then drag the resulting `.uf2` file onto the `RPI-RP2` drive that appears.

## Notes

- OLED rotation is currently set to `OLED_ROTATION_270` in `oled_luna.c`. This hasn't been verified on physical hardware yet — if the animation appears rotated once assembled, try `OLED_ROTATION_0`, `90`, or `180` instead.

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix and plug in the keyboard
* **Physical reset button**: Double-tap the reset button on the XIAO RP2040
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
