#include QMK_KEYBOARD_H

#define _BASE 0
#define _ONE_HAND 1
#define _ALT 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ANY		KC_ENT
#define KC_REC  DYN_REC_START1
#define KC_PLAY DYN_MACRO_PLAY1
#define KC_STOP DYN_REC_STOP
//#define KC_REC XXXXXXX
//#define KC_PLAY XXXXXXX
#define LEFT OSL(_ONE_HAND)

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
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TAB,  KC_PPLS, KC_BSPC,      OSL(_ALT),KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  LGUI(KC_L),KC_DEL,KC_PSCR, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PSLS, KC_PAST, KC_PMNS,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    LEFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_REC,  KC_MPLY, \
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_UP,   KC_STOP, KC_VOLU, \
    KC_LCTL, KC_LALT, KC_LWIN, KC_PLAY, KC_ENT,  KC_SPC,  KC_P0,   KC_PDOT, KC_ENT,       KC_SPC,  KC_BSPC, KC_RALT, KC_RWIN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD \
),

[_ONE_HAND] = LAYOUT( \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,KC_P,	KC_O,	KC_I,	KC_U,	KC_Y,	_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,KC_SCLN,KC_L,	KC_K,	KC_J,	KC_H,	_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,KC_SLSH,KC_DOT,	KC_COMM,KC_M,	KC_N,	_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,_______,_______,_______,KC_BSPC,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______  \
),

[_ALT] = LAYOUT( \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,	KC_F6, KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,  _______,_______, \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______, \
	_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______,_______,_______,_______,_______  \
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