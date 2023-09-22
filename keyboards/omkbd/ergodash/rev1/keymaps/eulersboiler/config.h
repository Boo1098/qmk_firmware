/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS


// RGB SETUP
#define RGBLIGHT_SLEEP
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGBLIGHT_DISABLE_KEYCODES
#define RGBLIGHT_DEFAULT_HUE 255
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 0
#define RGBLIGHT_LIMIT_VAL 50
#define RGBLIGHT_LAYERS

// Disable Macro loops
#define DYNAMIC_MACRO_NO_NESTING

// Unicode setup
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE, UNICODE_MODE_LINUX

// Remove animations
#undef RGBLIGHT_MODE_BREATHING
#undef RGBLIGHT_MODE_RAINBOW_MOOD
#undef RGBLIGHT_MODE_RAINBOW_SWIRL
#undef RGBLIGHT_MODE_SNAKE
#undef RGBLIGHT_MODE_KNIGHT
#undef RGBLIGHT_MODE_CHRISTMAS
#undef RGBLIGHT_MODE_STATIC_GRADIENT
#undef RGBLIGHT_MODE_RGB_TEST
#undef RGBLIGHT_MODE_ALTERNATING
#undef RGBLIGHT_MODE_TWINKLE

// Later tap toggle taps
#define TAPPING_TOGGLE 1

// Leader Key settings
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT 

