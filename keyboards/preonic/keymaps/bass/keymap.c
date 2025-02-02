#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
	#include "muse.h"
#endif

enum preonic_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  BACKLIT
};

/************************
enum custom_keycodes {
	LOWER = SAFE_RANGE,
	RAISE,
	MC_HOME,
	MC_END
};
************************/

#define COLEMAK PDF(_COLEMAK)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_ortho_5x12(
KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, 
KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_QUOT, 
KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_DEL, 
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_ortho_5x12(
_______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, _______, 
_______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______, _______, 
_______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, _______, 
_______, _______, KC_0,    KC_DOT,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

[_RAISE] = LAYOUT_ortho_5x12(
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,         KC_F9,   KC_F10,  KC_EQL, 
_______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______,       KC_LBRC, KC_RBRC, KC_GRV, 
_______, _______, _______, _______, _______, _______, _______, _______, _______,       KC_LCBR, KC_RCBR, KC_BSLS, 
_______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_LEFT), KC_PGDN, KC_PGUP, RGUI(KC_RIGHT)
),

[_ADJUST] = LAYOUT_ortho_5x12(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
_______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, 
_______, _______, MU_NEXT, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______, 
_______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            gpio_write_pin_low(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            gpio_write_pin_high(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}