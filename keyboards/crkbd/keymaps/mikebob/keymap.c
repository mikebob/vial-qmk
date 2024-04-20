/*
Copyright 2019 @foostan
Copyright 2021 @HellSingCoder
Copyright 2023 @asdfire1

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "print.h"
#include "oled/oled_global_variables.h"
#include "oled/render_oleds.c"

enum {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
  current_wpm = get_current_wpm();
  led_usb_state = host_keyboard_led_state();


  if (is_keyboard_master()) {
    render_main_oled();
  } else {
    render_peripheral_oled();
  }

  return false;
}

#endif

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_RED},       // Light 1 LED, starting with LED 6
    {13, 2, HSV_RED},       // Light 2 LEDs, starting with LED 13
    {33, 1, HSV_RED},       // Light 1 LED, starting with LED 33
    {40, 2, HSV_RED}       // Light 2 LEDs, starting with LED 40
);

// // Light LED 13 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 1, HSV_TEAL},       // Light 1 LED, starting with LED 6
//     {13, 2, HSV_TEAL}       // Light 2 LEDs, starting with LED 13
// );
//
// // Light LED 40 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {33, 1, HSV_PURPLE},       // Light 1 LED, starting with LED 33
//     {40, 2, HSV_PURPLE}       // Light 2 LEDs, starting with LED 40
// );

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    // my_layer1_layer,
    // my_layer2_layer,
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FIRST));
    rgblight_set_layer_state(1, layer_state_cmp(state, _SECOND));
    return state;
}

// static void print_status_narrow(void) {

//     /* Print current layer */
//     oled_write("LAYER", false);
//     oled_set_cursor(0, 6);

//     switch (get_highest_layer(layer_state)) {
//         case 0:
//             oled_write("Base ", false);
//             break;
//         case 1:
//             oled_write("Nav ", false);
//             break;
//         case 2:
//             oled_write("Second ", false);
//             break;
//         case 3:
//             oled_write("Third ", false);
//             break;
//         default:
//             oled_write("Undef", false);
//     }
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
            isSneaking = record->event.pressed;
            break;
        case KC_SPC:
            isJumping = record->event.pressed;
            if (isJumping) {
                showedJump = false;
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_split_3x6_3(

     KC_ESCAPE,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,        KC_BSPC,
        KC_TAB,           KC_A,           KC_S,           KC_D,           KC_F,           KC_G,            KC_H,           KC_J,           KC_K,           KC_L,        KC_SCLN,       KC_QUOTE,
       KC_LSFT,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,            KC_N,           KC_M,       KC_COMMA,         KC_DOT,       KC_SLASH,      KC_ESCAPE,
                                                       KC_LCTL,        KC_LGUI,       KC_SPACE,        KC_ENTER,        RGB_M_R,        RGB_M_B
),
[_FIRST] = LAYOUT_split_3x6_3(

        KC_TAB,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,            KC_6,           KC_7,           KC_8,           KC_9,           KC_0,      KC_DELETE,
       KC_LCTL,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         KC_LEFT,        KC_DOWN,          KC_UP,       KC_RIGHT,        KC_PGUP,          KC_NO,
       KC_LSFT,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_PGDN,          KC_NO,
                                                       KC_LGUI,        KC_TRNS,       KC_SPACE,        KC_ENTER,        KC_TRNS,        KC_RALT
),
[_SECOND] = LAYOUT_split_3x6_3(

        KC_TAB,     LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),      LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     LSFT(KC_0),        KC_BSPC,
       KC_LCTL,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,        KC_MINUS,       KC_EQUAL,        KC_LBRC,        KC_RBRC,        KC_BSLS,       KC_GRAVE,
       KC_LSFT,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,  LSFT(KC_MINUS), LSFT(KC_EQUAL),  LSFT(KC_LBRC),  LSFT(KC_RBRC),  LSFT(KC_BSLS), LSFT(KC_GRAVE),
                                                       KC_LGUI,        KC_TRNS,       KC_SPACE,        KC_ENTER,        KC_TRNS,        KC_RALT
),
[_THIRD] = LAYOUT_split_3x6_3(

        QK_RBT,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
       RGB_TOG,        RGB_HUI,        RGB_SAI,        RGB_VAI,          KC_NO,          KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
       RGB_MOD,        RGB_HUD,        RGB_SAD,        RGB_VAD,          KC_NO,          KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                       KC_LGUI,        KC_TRNS,       KC_SPACE,        KC_ENTER,        KC_TRNS,        KC_RALT
)

};