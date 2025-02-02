#include QMK_KEYBOARD_H
#include "muse.h"
#include "print.h"   // allow debugging

enum preonic_layers {
  _COLEMAK,
  _LOWER,
  _RAISE
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  BACKLIT
};


// Lighting layers
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{1, 8, HSV_PURPLE}       // Light 8 LEDs, starting with LED 0
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{1, 8, HSV_GREEN}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{1, 8, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    lower_layer,
    raise_layer
);


#define COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_ortho_5x12(
KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC, KC_MINS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TAB, KC_CAPS, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_A, KC_R, KC_S, KC_T, KC_D, KC_BSPC, KC_DEL, KC_H, KC_N, KC_E, KC_I, KC_O, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_EQL, KC_QUOT, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(1), MO(2), KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

[_LOWER] = LAYOUT_ortho_5x12(
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, QK_BOOT, DB_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_NO, KC_NO, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

[_RAISE] = LAYOUT_ortho_5x12(
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_LCBR, KC_RCBR, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END
)

};


/*********************************************************************************
// Lighting layers
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{1, 8, HSV_PURPLE}       // Light 8 LEDs, starting with LED 0
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{1, 8, HSV_GREEN}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{1, 8, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    lower_layer,
    raise_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// Enable and disabling lighting layers
layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    return state;
}


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
*********************************************************************************/
