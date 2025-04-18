// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#pragma once
#include "oled.h"

enum layers {
	_COLEMAK,
	_RAISE,
	_LOWER,
	_ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* COLEMAK **************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |BackSP|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  | DEL  |
 * |------+------+------+------+------+------| Lower |    | Raise |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LAlt | LGUI | /Space  /       \Enter \  | RGUI | Left |Right |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  KC_BSPC,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_DEL,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   RAISE, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL,    KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_RGUI, KC_LEFT, KC_RGHT
),

/* LOWER ****************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |                    |      |      |      |   [  |   ]  |   ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |   {  |   }  |   |  |
 * |------+------+------+------+------+------| Lower |    | Raise |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |   =  |   +  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 
[_LOWER] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_GRV,
  XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_TILD,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_PLUS, KC_BSLS,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* RAISE ****************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Mod+ | Hue+ | Sat+ | Bri+ | Spd+ |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Mod- | Hue- | Sat- | Bri- | Spd- |      |                    | PgDn |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Home | Left |      |Right | End  |      |
 * |------+------+------+------+------+------| Lower |    | Raise |------+------+------+------+------+------|
 * |MTogg |      |      |      |      |      |-------|    |-------| PgDn |      | Down |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,                     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,
  RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,                     KC_PGUP,       XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,       XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LGUI(KC_LEFT), KC_LEFT, XXXXXXX, KC_RGHT, RGUI(KC_RGHT), XXXXXXX,
  RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  KC_PGDN,       XXXXXXX, KC_DOWN, XXXXXXX, XXXXXXX,       XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,       XXXXXXX, XXXXXXX
),

/* ADJUST ***************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |RESET |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 
  [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};
/***********************************************************************************************************/
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master()) {
		return OLED_ROTATION_270;
	}
	
	return rotation;
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();
    /* KEYBOARD PET VARIABLES END */

    if (!is_keyboard_master()) {
		oled_set_cursor(0,0);
        oled_write_raw_P(logo_motet, sizeof(logo_motet));
        oled_set_cursor(0,5);
	    oled_write("motet", false);
	    oled_set_cursor(0,8);
        oled_write_raw_P(logo_macos, sizeof(logo_macos));
        render_luna(0,13);
    } else {
        render_layer_status();
    }
        
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
    }
    return true;
}
