#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

// Layer Lighting
// Default qwerty layer lighting
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{0,24,  18,200,255}
    {0,24,  18,200,0}
);
// raise layer lighting
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,24,  15,230,255}
);
// lower layer lighting
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,24,  170,150,255}
);
// adjust layer lighting
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,24,HSV_GREEN}
);
// adjust layer lighting
const rgblight_segment_t PROGMEM record_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,24,HSV_RED}
);
// adjust layer lighting
const rgblight_segment_t PROGMEM leader_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,24, 210,255,255}
);

// rgb layers array
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    raise_layer,
    lower_layer,
    adjust_layer,
    record_layer,
    leader_layer
);
// Enable layer lighting
void keyboard_post_init_user(void){
    rgblight_layers = rgb_layers;
}

enum custom_keycodes {
    LEDON = SAFE_RANGE,
    LEDOFF
};

// Unicode characters setup
// TODO: change unicode mode based on OS or add to an adjust layer
enum unicode_names {
    MU,
    SIG,
    SIGU,
    THETA,
    THETAU,
    PI,
    PIU,
    TAU,
    ZETA,
    DELTA,
    DELTAU,
    NU,
    ALPHA,
    BETA,
    GAMMA,
    GAMMAU,
    EPSILON,
    ETA,
    KAPPA,
    XI,
    XIU,
    PHI,
    PHIU,
    CHI,
    PSI,
    PSIU,
    OMEGA,
    OMEGAU,
    RHO,
    LAMBDA,
    LAMBDAU
};

const uint32_t unicode_map[] PROGMEM = {
    [MU]    = 0x03BC,  // μ
    [SIG]   = 0x03C3,  // σ
    [SIGU]  = 0x03A3,  // Σ
    [THETA] = 0x03B8,  // θ
    [THETAU]= 0x0398,  // Θ
    [PI]    = 0x03C0,  // π
    [PIU]   = 0x03A0,  // Π
    [TAU]   = 0x03C4,  // τ
    [ZETA]  = 0x03B6,  // ζ
    [DELTA] = 0x03B4,  // δ
    [DELTAU]= 0x0394,  // Δ
    [NU]    = 0x03BD,  // ν
    [ALPHA] = 0x03B1,  // α
    [BETA]  = 0x03B2,  // β
    [GAMMA] = 0x03B3,  // γ
    [GAMMAU]= 0x0393,  // Γ
    [EPSILON]=0x03B5,  // ε
    [ETA]   = 0x03B7,  // η
    [KAPPA] = 0x03BA,  // κ
    [XI]    = 0x03BE,  // ξ
    [XIU]   = 0x039E,  // Ξ
    [PHI]   = 0x03C6,  // φ
    [PHIU]  = 0x03A6,  // Φ
    [CHI]   = 0x03BE,  // ξ
    [PSI]   = 0x03C8,  // ψ
    [PSIU]  = 0x03A8,  // Ψ
    [OMEGA] = 0x03C9,  // ω
    [OMEGAU]= 0x03A9,  // Ω
    [RHO]   = 0x03C1,  // ρ
    [LAMBDA]= 0x03BB,  // λ
    [LAMBDAU]=0x039B   // Λ
};

#define TG_LWR   TT(_LOWER)
#define TG_RSE   TT(_RAISE)
#define SIGMA    UP(SIG,SIGU)
#define KC_THTA  UP(THETA,THETAU)
#define KC_PI    UP(PI,PIU)
#define KC_TAU   UM(TAU)
#define KC_ZETA  UM(ZETA)
#define KC_DELTA UP(DELTA,DELTAU)
#define KC_NU    UM(NU)
#define KC_ALPHA UM(ALPHA)
#define KC_BETA  UM(BETA)
#define KC_GAMMA UP(GAMMA,GAMMAU)
#define KC_EPS   UM(EPSILON)
#define KC_ETA   UM(ETA)
#define KC_KAPPA UM(KAPPA)
#define KC_XI    UP(XI,XIU)
#define KC_PHI   UP(PHI,PHIU)
#define KC_CHI   UM(CHI)
#define KC_PSI   UP(PSI,PSIU)
#define KC_OMEGA UP(OMEGA,OMEGAU)
#define KC_RHO   UM(RHO)
#define KC_LAMB  UP(LAMBDA,LAMBDAU)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * TODO: 
   * * Update drawing 
   * * find a good spot for Del 
   * * Media Controls better?
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  ALT |  GUI | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL , KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    DM_REC1,                        DM_PLY1, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG_LWR,                         TG_RSE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MPLY,
    KC_LCTL, KC_LALT, KC_LGUI, QK_LEAD,          KC_ENT,  KC_SPC,    KC_HOME,    KC_END,  KC_SPC , KC_BSPC,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  // TODO: 
  [_RAISE] = LAYOUT(
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     _______, _______, KC_OMEGA,KC_EPS,  KC_RHO,  KC_TAU,  _______,                        _______, KC_PSI,  UM(MU),  KC_PSI,  KC_THTA, KC_PI,   _______,
     _______, KC_ALPHA,SIGMA,   KC_DELTA,KC_PHI,  KC_GAMMA,_______,                        _______, _______, _______, KC_KAPPA,KC_LAMB, _______, _______,
     _______, KC_ZETA, KC_XI,   KC_CHI,  KC_NU,   KC_BETA, _______,                        _______, KC_ETA,  UM(MU),  _______, _______, KC_UP,   _______,
     _______, _______, _______, _______,          _______, _______, _______,      _______, _______,          _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  /* LOWER
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
     _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
     _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
     _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
     _______, _______, _______, _______, _______, _______, _______,                        _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
     _______, _______, _______, _______,          _______, _______, _______,      _______, _______, KC_P0,            KC_P0,   KC_PDOT, KC_PENT, _______
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, EE_CLR,  QK_BOOT, RGB_TOG,_______,                       _______, RGB_SAD, UC_NEXT, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, _______, _______, BL_UP  , BL_DOWN,_______,                       _______, _______, _______, _______, LEDON,   _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, LEDOFF,  _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode){
        case LEDOFF:
            if(record->event.pressed){
                rgblight_set_layer_state(0, false);
            }
            return false;
        case LEDON:
            if(record->event.pressed){
                rgblight_set_layer_state(0, true);
            }
            return false;
        default:
            return true;
    }
}



#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Layer lighting run
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(1, led_state.caps_lock);
//     return true;
// }

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // all the time lighting is annoying
    rgblight_set_layer_state(0, false); //layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state=update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(0, false); //layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    // tri_layer
    return state;
}

// Red for dynamic macro recording
void dynamic_macro_record_start_user(int8_t direction) {
  rgblight_set_layer_state(4, true);
}

// TODO: Make this return you to whatever layer you were on
void dynamic_macro_record_end_user(int8_t direction) {
  rgblight_set_layer_state(4, false);
}

// Backspace +shift = delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Key overrid: make MPLY do all media controls
const key_override_t next_track_override = 
    ko_make_with_layers_negmods_and_options(
        MOD_MASK_CTRL,       // Trigger modifiers: ctrl
        KC_MPLY,             // Trigger key: play/pause
        KC_MNXT,             // Replacement key
        ~0,                  // Activate on all layers
        MOD_MASK_SA,         // Do not activate when shift or alt are pressed
        ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting ctrl
    
const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY,
                                            KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

const key_override_t vol_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_MPLY,
                                            KC_VOLU, ~0, MOD_MASK_CS, ko_option_no_reregister_trigger);

const key_override_t vol_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SA, KC_MPLY,
                                            KC_VOLD, ~0, MOD_MASK_CTRL, ko_option_no_reregister_trigger);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &next_track_override,
    &prev_track_override,
    &vol_up_override,
    &vol_down_override,
    &delete_key_override,
    NULL
};

// Leader key macros
void leader_start_user(void) {
    rgblight_set_layer_state(5, true);
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_one_key(KC_P)) {
        tap_code16(KC_MPLY);
    }
    rgblight_set_layer_state(5, false);
}

// Turn off lights on suspend
void suspend_power_down_user(void) {
    // code will run multiple times while keyboard is suspended
    rgblight_set_layer_state(0, false);
}

void suspend_wakeup_init_user(void) {
    // code will run on keyboard wakeup
    rgblight_set_layer_state(0, true);
}
