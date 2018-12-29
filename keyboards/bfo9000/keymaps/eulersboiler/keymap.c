#include QMK_KEYBOARD_H

#define _BASE 0

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ANY		KC_ENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
    KC_ESC,  _______, KC_CALC, KC_BSPC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX, \
    KC_PSLS, KC_PAST, KC_PMNS, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
    KC_P7,   KC_P8,   KC_P9,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_MPLY, KC_VOLU, \
    KC_P1,   KC_P2,   KC_P3,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, ANY,     KC_UP,   KC_VOLD, \
    KC_P0,   XXXXXXX, KC_PDOT, KC_ENT,  KC_LCTL, KC_LALT, KC_LWIN, KC_SPC,  KC_SPC,        KC_SPC,  KC_SPC,  KC_RALT, KC_RWIN, KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT \
)
};
