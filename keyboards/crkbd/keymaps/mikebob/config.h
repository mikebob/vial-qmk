/*
Copyright 2021 @HellSingCoder
Copyright 2024 Mike Bobiney

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    // #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    // #define RGBLIGHT_EFFECT_SNAKE
    // #define RGBLIGHT_EFFECT_KNIGHT
    // #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    // #define RGBLIGHT_EFFECT_RGB_TEST
    // #define RGBLIGHT_EFFECT_ALTERNATING
    // #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define LEADER_TIMEOUT 300
#define RGBLIGHT_LAYERS

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// #ifdef RGB_MATRIX_ENABLE
// //#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// // #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
// #   define RGB_MATRIX_SLEEP // turn off effects when suspended
// //#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// // #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// // #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
// #    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
// #    define RGB_MATRIX_HUE_STEP 8
// #    define RGB_MATRIX_SAT_STEP 8
// #    define RGB_MATRIX_VAL_STEP 8
// #    define RGB_MATRIX_SPD_STEP 10

// #    define ENABLE_RGB_MATRIX_ALPHAS_MODS

// #endif

// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_WPM_ENABLE //Enable WPM across split keyboards (+268).
// #define NO_ACTION_ONESHOT
//#define SPLIT_OLED_ENABLE