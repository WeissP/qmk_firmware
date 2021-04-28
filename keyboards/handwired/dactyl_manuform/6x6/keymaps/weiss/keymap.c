#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "personal.h"

enum combos_events {
    /* ARROW,                      /\* -> *\/ */
    ARROW_WITH_SPACE            /* -> */
};

/* const uint16_t PROGMEM arrow_combo[] = {DE_COMM, DE_DOT, COMBO_END}; */
const uint16_t PROGMEM arrow_with_space_combo[] = {DE_COMM, DE_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    /* [ARROW] = COMBO_ACTION(arrow_combo), */
    [ARROW_WITH_SPACE] = COMBO_ACTION(arrow_with_space_combo),    
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        /* case ARROW: */
        /*   if (pressed) { */
        /*       SEND_STRING(SS_TAP(X_SLSH) SS_DOWN(X_LSFT) SS_TAP(X_NUBS) SS_UP(X_LSFT)); /\* -> *\/ */
        /*   } */
        /*   break; */
    case ARROW_WITH_SPACE:
        if (pressed) {
            SEND_STRING(" " SS_TAP(X_SLSH) SS_DOWN(X_LSFT) SS_TAP(X_NUBS) SS_UP(X_LSFT) " ");
        }
        break;
    }
}


enum {
    TD_LEFT_BRACE,
    TD_RIGHT_BRACE
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LEFT_BRACE] = ACTION_TAP_DANCE_DOUBLE(DE_LPRN, DE_LCBR),
    [TD_RIGHT_BRACE] = ACTION_TAP_DANCE_DOUBLE(DE_RPRN, DE_RCBR),
};

enum custom_keycodes {
    WEISS_PW = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
    case WEISS_PW:
        if (record->event.pressed){
            SEND_STRING(main_password);
        }else {
            
        }
        break;
    }

    return true;
};

// Thumb clusters, match to the comments in the keymaps
//
//         +----+
// +----+  |    |                                          +-----+
// |    |  | 2  | +----+                                   |     | +----+
// | 1  |  |    | |    |                           +-----+ | 7   | |    |
// |    |  +----+ | 3  |                           |     | |     | | 8  |
// +----+         |    | +----+             +----+ | 10  | +-----+ |    |
//                +----+ |    |             |    | |     |         +----+
//            +----+     | 4  |             | 9  | +-----+
//            |    |     |    |             |    |        +----+
//            | 5  |     +----+             +----+        | 12 |
//            +----++-----+                        +----+ |    |
//                  |     |                        |    | +----+
//                  | 6   |                        |11  |
//                  +-----+                        +----+
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASIC_LAYER] = LAYOUT_6x6(
        KC_F5,DE_GRV,KC_F15,KC_F16,KC_F11,KC_F12,G(KC_1),G(KC_2),G(KC_3),G(KC_4),DE_DLR,KC_F6,
C(KC_TAB),DE_EQL,DE_EXLM,DE_AT,DE_SLSH,KC_F14,KC_F17,DE_QUES,DE_MINS,DE_AMPR,KC_BSPC,TD(TD_LEFT_BRACE),
S(C(KC_TAB)),KC_Q,KC_W,KC_E,KC_R,KC_T,DE_Y,KC_U,KC_I,KC_O,KC_P,TD(TD_RIGHT_BRACE),
KC_COPY,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_TAB,KC_PGUP,
KC_PASTE,DE_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,DE_COMM,DE_DOT,A(KC_SPC),KC_PGDOWN,
KC_LEFT,KC_RIGHT,KC_DOWN,KC_UP,
LT(_SHIFTED_LAYER,KC_END),LT(_NUMBER_LAYER,KC_ENT),KC_SPC,LT(1,KC_ESC),
KC_LCTRL,KC_HOME,KC_END,KC_BSPC,
KC_LALT,KC_LGUI,KC_GRV,KC_BSPC),

    [_CUSTOM_LAYER] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,DE_UNDS,_______,_______,DE_BSLS,C(G(KC_A)),LGUI(KC_9),LGUI(KC_8),LGUI(KC_7),LGUI(KC_6),LGUI(KC_5),_______,
_______,C(KC_Q),LCTL(KC_W),_______,LCTL(KC_R),LCTL(KC_T),_______,DE_UDIA,HYPR(KC_I),DE_ODIA,G(S(KC_A)),_______,
KC_LCTL,DE_ADIA,DE_SS,_______,LCTL(KC_F),_______,LCTL(KC_H),HYPR(KC_J),HYPR(KC_K),HYPR(KC_L),KC_TAB,_______,
KC_LGUI,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B),_______,_______,DE_LABK,DE_RABK,_______,_______,
A(KC_LEFT),A(KC_RIGHT),G(KC_LEFT),G(KC_RIGHT),
KC_LSFT,LCTL(KC_G),_______,_______,
_______,_______,_______,_______,
_______,_______,_______,_______),

    [_NUMBER_LAYER] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,DE_HASH,_______,
_______,_______,G(KC_ESC),_______,_______,_______,_______,DE_SLSH,DE_TILD,DE_ASTR,KC_BSPC,_______,
_______,_______,_______,_______,_______,_______,_______,KC_7,KC_8,KC_9,WEISS_PW,_______,
_______,_______,_______,_______,_______,_______,_______,KC_4,KC_5,KC_6,_______,_______,
_______,_______,_______,_______,_______,_______,_______,KC_1,KC_2,KC_3,_______,_______,
_______,_______,KC_0,KC_DOT,
MO(_SHIFTED_NUMBER_LAYER),_______,_______,_______,
_______,_______,_______,_______,
_______,_______,_______,_______),

    [_SHIFTED_LAYER] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,DE_CIRC,_______,
_______,DE_QUOT,DE_EURO,DE_DEG,_______,_______,_______,DE_PERC,DE_PLUS,DE_PIPE,KC_BSPC,DE_LBRC,
S(KC_TAB),S(KC_Q),S(KC_W),S(KC_E),S(KC_R),S(KC_T),S(DE_Y),S(KC_U),S(KC_I),S(KC_O),S(KC_P),DE_RBRC,
S(KC_LCTL),S(KC_A),S(KC_S),S(KC_D),S(KC_F),S(KC_G),S(KC_H),S(KC_J),S(KC_K),S(KC_L),S(KC_TAB),S(KC_PGDOWN),
S(KC_LGUI),S(DE_Z),S(KC_X),S(KC_C),S(KC_V),S(KC_B),S(KC_N),S(KC_M),DE_SCLN,DE_COLN,_______,S(KC_PGDOWN),
S(KC_LEFT),S(KC_RIGHT),S(KC_DOWN),S(KC_UP),
MT(MOD_LSFT,KC_END),MO(_SHIFTED_NUMBER_LAYER),S(KC_SPC),KC_LSFT,
_______,_______,_______,_______,
_______,_______,_______,_______),
    [_SHIFTED_NUMBER_LAYER] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,KC_F7,KC_F8,KC_F9,_______,_______,
_______,_______,_______,_______,_______,_______,_______,KC_F4,KC_F5,KC_F6,_______,_______,
_______,_______,_______,_______,_______,_______,_______,KC_F1,KC_F2,KC_F3,_______,_______,
_______,_______,KC_F10,_______,
_______,_______,_______,_______,
_______,_______,_______,_______,
_______,_______,_______,_______)
};


