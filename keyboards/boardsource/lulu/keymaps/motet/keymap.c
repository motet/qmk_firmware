/*
 * Copyright 2025 Jo Yoshida <jo@motet.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#pragma once
#include "oled.h"
#include "luna.h"
#include "ocean_dream.h"
//#include "transactions.h"

enum layers {
	_COLEMAK,
	_LOWER,
	_RAISE,
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
 * | Del  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |BackSP|
 * |------+------+------+------+------+------| Lower |    | Raise |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LCTRL | LAlt | LGUI | /Space  /       \Enter \  |CapsLk| Left |Right |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
  KC_DEL,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_BSPC,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   RAISE, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL,    KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_CAPS, KC_LEFT, KC_RGHT
),

/* LOWER ****************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |   ~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |                    |      |      |      |   [  |   ]  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |   {  |   }  |   +  |
 * |------+------+------+------+------+------| Lower |    | Raise |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |   |  |   \  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 
[_LOWER] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TILD,
  XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_GRV,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PPLS,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, KC_BSLS, KC_PEQL,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* RAISE ****************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PgUp |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Home | Left | Down |Right | End  |      |
 * |------+------+------+------+------+------| Lower |    | Raise |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| PgDn |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_PGUP,       XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,       XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     LGUI(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, RGUI(KC_RGHT), XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  KC_PGDN,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,       XXXXXXX, XXXXXXX
),

/* ADJUST ***************************************************************************************************
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |BOOTL |RBOOT | DBG  |      |      |      |                    |      |      |      | DBG  |RBOOT |BOOTL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Spd+ | Bri+ | Sat+ | Hue+ | Mod+ |-------.    ,-------| Mod+ | Hue+ | Sat+ | Bri+ | Spd+ |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |MTogg | Spd- | Bri- | Sat- | Hue- | Mod- |-------|    |-------| Mod- | Hue- | Sat- | Bri- | Spd- |MTogg |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 
  [_ADJUST] = LAYOUT(
  QK_BOOT, QK_RBT,  DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, QK_RBT,  QK_BOOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                   RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,
  RM_TOGG, RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV, XXXXXXX, XXXXXXX, RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, RM_TOGG,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};
/***********************************************************************************************************/
layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;		// both OLEDS portrait orientation
}

bool oled_task_user(void) {
	// Update global variables then OLEDs
	
	current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

	#ifdef OLED_ENABLE
    if (is_keyboard_master()) {
	    render_oled_master();
    } else {
        render_oled_slave();
    }
	#endif
	   
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// Update global variables if necessary
	
	#ifdef OLED_ENABLE	
	switch (keycode) {
		case KC_LCTL:
        case KC_RCTL:
        	#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            #endif
            
            #ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
			#endif
            break;
        case KC_SPC:
           	#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            #endif
            break;
    }
    #endif
    
    return true;
}