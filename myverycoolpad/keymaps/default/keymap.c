// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define ENC_SW_PIN GP28
#define HOLD_THRESHOLD 500

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MPRV, LGUI(KC_SPC), KC_MNXT,
        LSG(KC_4), LGUI(KC_Z), LSG(KC_Z)
    )
};

static bool     enc_sw_pressed = false;
static bool     enc_sw_held    = false;
static uint32_t enc_sw_timer   = 0;
static bool     brightness_mode = false;

void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(ENC_SW_PIN);
}

void housekeeping_task_user(void) {
    bool pin_state = !gpio_read_pin(ENC_SW_PIN); // active low

    if (pin_state && !enc_sw_pressed) {
        // Just pressed
        enc_sw_pressed = true;
        enc_sw_held = false;
        enc_sw_timer = timer_read32();
    } else if (pin_state && enc_sw_pressed) {
        // Still holding
        if (!enc_sw_held && timer_elapsed32(enc_sw_timer) > HOLD_THRESHOLD) {
            enc_sw_held = true;
            brightness_mode = !brightness_mode; // toggle mode on hold
        }
    } else if (!pin_state && enc_sw_pressed) {
        // Released
        if (!enc_sw_held) {
            // Short tap = play/pause
            tap_code(KC_MPLY);
        }
        enc_sw_pressed = false;
        enc_sw_held = false;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (brightness_mode) {
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}
