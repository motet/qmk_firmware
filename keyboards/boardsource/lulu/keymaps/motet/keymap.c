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

/* KEYBOARD PET START */
///* settings */
//#    define MIN_WALK_SPEED      10
//#    define MIN_RUN_SPEED       40
//
///* advanced settings */
//#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
//#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024
//
///* timers */
//uint32_t anim_timer = 0;
//
///* current frame */
//uint8_t current_frame = 0;
//
///* status variables */
//int   current_wpm = 0;
//led_t led_usb_state;
//
//bool isSneaking = false;
//bool isJumping  = false;
//bool showedJump = true;
//
///* logic */
//static void render_luna(int LUNA_X, int LUNA_Y) {
//    /* Sit */
//    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
//                                                   {
//                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                   },
//
//                                                   /* 'sit2', 32x22px */
//                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
//
//    /* Walk */
//    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
//                                                    {
//                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                    },
//
//                                                    /* 'walk2', 32x22px */
//                                                    {
//                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                    }};
//
//    /* Run */
//    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
//                                                   {
//                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                   },
//
//                                                   /* 'run2', 32x22px */
//                                                   {
//                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                   }};
//
//    /* Bark */
//    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
//                                                    {
//                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                    },
//
//                                                    /* 'bark2', 32x22px */
//                                                    {
//                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                    }};
//
//    /* Sneak */
//    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
//                                                     {
//                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
//                                                     },
//
//                                                     /* 'sneak2', 32x22px */
//                                                     {
//                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
//                                                     }};
//
///* animation */
//void animate_luna(void) {
//	/* jump */
//	if (isJumping || !showedJump) {
//		/* clear */
//		oled_set_cursor(LUNA_X, LUNA_Y + 2);
//		oled_write("     ", false);
//
//		oled_set_cursor(LUNA_X, LUNA_Y - 1);
//
//		showedJump = true;
//	} else {
//		/* clear */
//		oled_set_cursor(LUNA_X, LUNA_Y - 1);
//		oled_write("     ", false);
//
//		oled_set_cursor(LUNA_X, LUNA_Y);
//	}
//
//	/* switch frame */
//	current_frame = (current_frame + 1) % 2;
//
//	/* current status */
//	if (led_usb_state.caps_lock) {
//		oled_write_raw_P(bark[current_frame], ANIM_SIZE);
//
//	} else if (isSneaking) {
//		oled_write_raw_P(sneak[current_frame], ANIM_SIZE);
//
//	} else if (current_wpm <= MIN_WALK_SPEED) {
//		oled_write_raw_P(sit[current_frame], ANIM_SIZE);
//
//	} else if (current_wpm <= MIN_RUN_SPEED) {
//		oled_write_raw_P(walk[current_frame], ANIM_SIZE);
//
//	} else {
//		oled_write_raw_P(run[current_frame], ANIM_SIZE);
//	}
//}
//
//# if OLED_TIMEOUT > 0
//	/* the animation prevents the normal timeout from occuring */
//	if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
//		oled_off();
//		return;
//	} else {
//		oled_on();
//	}
//# endif
//
//	/* animation timer */
//	if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
//		anim_timer = timer_read32();
//		animate_luna();
//	}
//}
///* KEYBOARD PET END */
//
//static void print_luna(void) {
//	/* KEYBOARD PET RENDER START */
//	render_luna(0, 13);
//	/* KEYBOARD PET RENDER END */
//}

//bool oled_task_user(void) {
//	/* KEYBOARD PET VARIABLES START */
//	current_wpm   = get_current_wpm();
//	led_usb_state = host_keyboard_led_state();
//	/* KEYBOARD PET VARIABLES END */
//	
//	if (!is_keyboard_master()) {
//		if ( 1 == 0 ) {
//			print_luna();
//		}
//	}
//	
//	return false;
//}
//
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master()) {
		return OLED_ROTATION_270;
	}
	
	return rotation;
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */
    //current_wpm   = get_current_wpm();
    //led_usb_state = host_keyboard_led_state();
    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        render_layer_status();
    } else {
		oled_set_cursor(0,0);
        oled_write_raw_P(logo_motet, sizeof(logo_motet));
        oled_set_cursor(0,5);
	    oled_write("motet", false);
	    oled_set_cursor(0,8);
        oled_write_raw_P(logo_macos, sizeof(logo_macos));
	    oled_set_cursor(0,12);
        oled_write_raw_P(img_luna_sit_2, sizeof(img_luna_sit_2));
    }
    
    return false;
}

void oled_render_boot(bool bootloader) {
    oled_clear();
    
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        
        if (bootloader) {
            oled_write_P(PSTR("Updating firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}
