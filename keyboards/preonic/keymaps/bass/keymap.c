#include QMK_KEYBOARD_H
#include "muse.h"
//#include "print.h"   // allow debugging

enum preonic_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

/************************
enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  BACKLIT
};
************************/
enum custom_keycodes {
	LOWER = SAFE_RANGE,
	RAISE,
	MC_HOME,
	MC_END
};


// Lighting layers
const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{1, 8, HSV_PURPLE}       // Light 8 LEDs, starting with LED 0
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{1, 8, HSV_GREEN}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{1, 8, HSV_RED}
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{1, 8, HSV_CYAN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	colemak_layer,
	lower_layer,
	raise_layer,
	adjust_layer
);

// Enable lighting layers
void keyboard_post_init_user(void) {
	rgblight_layers = my_rgb_layers;
}

// Layers and custom macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		/****************
		case MC_HOME:
			if (record->event.pressed) {
				SEND_STRING( SS_DOWN( X_LGUI ) SS_DOWN( X_LEFT ) SS_UP( X_LEFT ) SS_UP( X_LGUI ) );
			} 
			break;
	
		case MC_END:
			if (record->event.pressed) {
				SEND_STRING( SS_DOWN( X_RGUI ) SS_DOWN( X_RIGHT ) SS_UP( X_RIGHT ) SS_UP( X_RGUI ) );
			}
			break;
			*****************/
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
	}
	return true;
};


#define COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_ortho_5x12(
KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, 
KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_QUOT, 
KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_DEL, 
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
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
_______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______,       KC_LCBR, KC_RCBR, KC_GRV, 
_______, _______, _______, _______, _______, _______, _______, _______, _______,       KC_LBRC, KC_RBRC, KC_BSLS, 
_______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, LGUI(KC_LEFT), KC_PGDN, KC_PGUP, RGUI(KC_RIGHT)
),

[_ADJUST] = LAYOUT_ortho_5x12(
QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______, 
_______, _______, _______, _______, _______, _______, _______, _______, RGB_RMOD, RGB_VAD, RGB_VAI, RGB_MOD
)
};

/***********************************************************

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
**************************************************/
/**************************************************

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
**************************************************/
layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
  rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
  return state;
}
