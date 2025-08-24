#include QMK_KEYBOARD_H
#include "keymap_french.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
//                                                                                         |
        KC_ESC, FR_COLN,      FR_PERC,      FR_LPRN,      FR_RPRN,      FR_AT,                       FR_EQL,  FR_SLSH,      FR_MINS,      FR_PLUS,      FR_ASTR,      FR_PERC,
//                                                                                         |
        KC_TAB, FR_B,         FR_EACU,      FR_P,         FR_O,         FR_EGRV,                     FR_CIRC, FR_V,         FR_D,         FR_L,         FR_J,         FR_Z,
//                                                                                         |
        KC_ENT, LSFT_T(FR_A), LCTL_T(FR_U), LALT_T(FR_I), LGUI_T(FR_E), FR_COMM,                     FR_C,    RGUI_T(FR_T), RALT_T(FR_S), RCTL_T(FR_R), RSFT_T(FR_N), FR_M,
//                                                                                         |
        KC_SPC, FR_AGRV,      FR_Y,         FR_X,         FR_DOT,       FR_K,    LCTL(FR_V), KC_DEL, FR_QUOT, FR_Q,         FR_G,         FR_H,         FR_F,         FR_W,
//                                                                                         |
                                                          LCTL(FR_C),   MO(1),   KC_BSPC,    KC_SPC, MO(1),   LCTL(FR_Z)
        ),

    [1] = LAYOUT(
//                                                                                         |
        KC_F1,  KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,                       KC_F7,   KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
//                                                                                         |
        KC_TRNS, KC_TRNS,     KC_HOME,      KC_UP,        KC_END,       KC_PGUP,                     FR_PERC, KC_P7,        KC_P8,        KC_P9,        KC_TRNS,      KC_TRNS,
//                                                                                         |
        KC_PENT, LSFT_T(KC_TRNS), LCTL_T(KC_LEFT), LALT_T(KC_DOWN), LGUI_T(KC_RIGHT), KC_PGDN,       KC_PDOT, RGUI_T(KC_P4), RALT_T(KC_P5), RCTL_T(KC_P6), RSFT_T(KC_TRNS), KC_TRNS,
//                                                                                         |
        KC_NUM, KC_PSCR,      FR_SUP2,      FR_DEG,       FR_DLR,      FR_HASH, KC_TRNS,    KC_TRNS, KC_P0, KC_P1,      KC_P2,        KC_P3,        KC_TRNS,      KC_APP,
//                                                                                         |
                                                          KC_TRNS,      MO(1),   KC_TRNS,    KC_TRNS, MO(1),  KC_TRNS
        )
};

const key_override_t quote_to_dquote_override     = ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO);
const key_override_t c_to_cced_override         = ko_make_basic(MOD_BIT(KC_RALT), FR_C, FR_CCED);
const key_override_t p_to_paragraph_override     = ko_make_basic(MOD_MASK_ALT, FR_P, LSFT(FR_EXLM));
const key_override_t comma_to_semicolon_override = ko_make_basic(MOD_MASK_ALT, FR_COMM, FR_SCLN);
const key_override_t circ_to_perc_override       = ko_make_basic(MOD_MASK_ALT, FR_CIRC, FR_PERC);
const key_override_t bckspc_to_del_override       = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &quote_to_dquote_override,
    &c_to_cced_override,
    &p_to_paragraph_override,
    &comma_to_semicolon_override,
    &circ_to_perc_override,
    &bckspc_to_del_override,
    NULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t current_mods = get_mods();
    switch (keycode) {
        // é
        case FR_EACU:
            if (record->event.pressed) {
                if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P0) SS_TAP(X_P1) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // è
        case FR_EGRV:
            if (record->event.pressed) {
                if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P0) SS_TAP(X_P0) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_TAP(X_DOT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // à
        case FR_AGRV:
            if (record->event.pressed) {
                if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P9) SS_TAP(X_P2) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // Ç
        case FR_C:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P9) SS_TAP(X_P9) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // æ
        case LSFT_T(FR_A):
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P6) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P5) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // Œ
        case FR_O:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P0) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P6) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // Ù
        case LCTL_T(FR_U):
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P1) SS_TAP(X_P7) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_TAP(X_QUOT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        case FR_QUOT:
            if (record->event.pressed) {
                if (current_mods & MOD_MASK_SHIFT && current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_7) SS_TAP(X_7) SS_TAP(X_7) SS_UP(X_RALT) SS_TAP(X_SPC));
                    set_mods(current_mods);
                    return false;
                } else
                if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_7) SS_UP(X_RALT) SS_TAP(X_SPC));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // ×
        case FR_ASTR:
            if (record->event.pressed) {
                if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P1) SS_TAP(X_P5) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        //
        case KC_SPC:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P6) SS_TAP(X_P0) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_TAP(X_8));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P8) SS_TAP(X_P2) SS_TAP(X_P3) SS_TAP(X_P9) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // ( { < [
        case FR_LPRN:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_4) SS_UP(X_RALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_TAP(X_NUBS));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_5) SS_UP(X_RALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // ) > ]
        case FR_RPRN:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_EQL) SS_UP(X_RALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_NUBS) SS_UP(X_LSFT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_MINS) SS_UP(X_RALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // . · …
        case FR_DOT:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P8) SS_TAP(X_P3) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else
                if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P3) SS_TAP(X_P3) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                } else
                if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_TAP(X_SLSH));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // @ ~ & |
        case FR_AT:
            if (record->event.pressed) {
                if ((current_mods & MOD_MASK_SHIFT) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_2) SS_UP(X_RALT) SS_TAP(X_SPC));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_TAP(X_1));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_6) SS_UP(X_RALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // / \ ÷
        case FR_SLSH:
            if (record->event.pressed) {
                if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_8) SS_UP(X_RALT));
                    set_mods(current_mods);
                    return false;
                } else if (current_mods & MOD_BIT(KC_RALT)) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P4) SS_TAP(X_P7) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        // - —
        case FR_MINS:
            if (record->event.pressed) {
                if (current_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P1) SS_UP(X_LALT));
                    set_mods(current_mods);
                    return false;
                }
            }
            break;
        case KC_UP:
            if (record->event.pressed) {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RCTL)) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_W));
                    set_mods(current_mods);
                    return false;
                } else if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT)))
                {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_Z));
                    set_mods(current_mods);
                    return false;
                }
            }
            else {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RCTL)) && (current_mods & MOD_BIT(KC_RALT))) {
                    SEND_STRING(SS_UP(X_W));
                    return false;
                } else if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT)))
                {
                    SEND_STRING(SS_UP(X_Z));
                    return false;
                }
            }
            break;
        case LCTL_T(KC_LEFT):
            if (record->event.pressed) {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RCTL)) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_A));
                    set_mods(current_mods);
                    return false;
                } else if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT)))
                {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_Q));
                    set_mods(current_mods);
                    return false;
                }
            } else {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RCTL)) && (current_mods & MOD_BIT(KC_RALT))) {
                    SEND_STRING(SS_UP(X_A));
                    return false;
                } else if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT)))
                {
                    SEND_STRING(SS_UP(X_Q));
                    return false;
                }
            }
            break;
        case LALT_T(KC_DOWN):
            if (record->event.pressed) {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_S));
                    set_mods(current_mods);
                    return false;
                }
            } else {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT))) {
                    SEND_STRING(SS_UP(X_S));
                    return false;
                }
            }
            break;
        case LGUI_T(KC_RIGHT):
            if (record->event.pressed) {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT))) {
                    clear_mods();
                    SEND_STRING(SS_DOWN(X_D));
                    set_mods(current_mods);
                    return false;
                }
            } else {
                if ((current_mods & MOD_BIT(KC_RSFT)) && (current_mods & MOD_BIT(KC_RALT))) {
                    SEND_STRING(SS_UP(X_D));
                    return false;
                }
            }
            break;
    }
    return true;
}
