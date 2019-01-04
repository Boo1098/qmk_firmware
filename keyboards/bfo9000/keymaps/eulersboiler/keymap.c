#include QMK_KEYBOARD_H

#define _BASE 0

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ANY		KC_ENT
#define KC_REC  DYN_REC_START1
#define KC_PLAY DYN_MACRO_PLAY1
#define KC_STOP DYN_REC_STOP
//#define KC_REC XXXXXXX
//#define KC_PLAY XXXXXXX

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    LOWER,
    RAISE,
    BACKLIT,
    EXT_PLV,
    DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
    KC_BSPC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TAB,  KC_PPLS, KC_BSPC,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_PSCR, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PSLS, KC_PAST, KC_PMNS,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_REC,  KC_MPLY, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_STOP, KC_VOLU, \
    KC_LCTL, KC_LALT, KC_LWIN, KC_PLAY, KC_ENT,  KC_SPC,  KC_P0,   KC_PDOT, KC_ENT,       KC_SPC,  KC_BSPC, KC_RALT, KC_RWIN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD \
)

};

// this is called when dynamic macro buffer is full
void backlight_toggle(void) {
    // INSERT CODE HERE: for example, call function to turn on indicator LED.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	/*if(keycode==DYN_REC_START1){
		keycode=DYN_REC_STOP;
	}else if(keycode==DYN_REC_START2){
		keycode=DYN_REC_STOP;
	}*/
	
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
	
	return true;	
}