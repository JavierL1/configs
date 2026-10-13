// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LBRC,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_MUTE,     KC_MPLY, KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LGUI, KC_LALT, KC_LCTL, MO(_LOWER), KC_SPC,      KC_ENT,  MO(_RAISE),  KC_RCTL, KC_RALT, KC_RGUI
    ),
    /*
     * +----+------+-----+------+------+------+----+----+------+------+------+------+-------+-----+
     * | f1 | f2   | f3  | f4   | f5   | f6    |    |    | f7   | f8   | f9   | f10  | f11   | f12 |
     * +----+------+-----+------+------+------+----+-----+------+------+------+------+-------+-----+
     * | __ | @    | "__⅛|  (   | )__± | =__°  |    |    | ¿¡¸  | '?→  | !    | °__¬ | __    | __  |
     * +----+------+-----+------+------+------+----+-----+------+------+------+------+-------+-----+
     * | __ | ^__   | %__⅜| {[^  | }]`  | /__⅞ |    |    | |°¬  | <>\  | #__£ | $__  | &__⅝  |´¨°  |
     * +----+------+-----+------+------+------+----+-----+------+------+------+------+-------+-----+
     * | __ | `__ | '?→ |    [ | ]    | \      | __ | __ | *    |  ~   | ,;•  | .:·  | -_ ̣   | +*~ |
     * +----+------+-----+------+------+------+----+-----+------+------+------+------+-------+-----+
     * |    |      | __  | __   | __   | __    | __ | __ | Adj  | __   | __   |   __ |       |     |
     * +----+------+-----+------+------+------+----+----+------+------+------+------+-------+-----+
     */
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,         KC_F3,   KC_F4,      KC_F5,      KC_F6,                               KC_F7,        KC_F8,      KC_F9,   KC_F10,  KC_F11,   KC_F12,
        KC_TRNS, ALGR(KC_Q),    KC_AT,   KC_ASTR,    KC_LPRN,    KC_RPRN,                             KC_EQL,       S(KC_MINS), KC_EXLM, KC_TILD, KC_TRNS,  KC_TRNS,
                      KC_TRNS, ALGR(KC_QUOT), KC_PERC, KC_QUOT,    KC_NUHS,    KC_AMPR,                             KC_GRV,       KC_NUBS,    KC_HASH, KC_DLR,  KC_CIRC,  KC_TRNS,
                      KC_TRNS, ALGR(KC_NUHS), KC_MINS, S(KC_QUOT), S(KC_NUHS), ALGR(KC_NUBS), KC_TRNS,     KC_TRNS, S(KC_RBRC),   ALGR(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS,  KC_RBRC,
                      KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     KC_TRNS, MO(_ADJUST),  KC_TRNS,    KC_TRNS, KC_TRNS
    ),
    [_RAISE] = LAYOUT(
        KC_ESC, KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,                            KC_CALC, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_BSPC,
        KC_PGUP, LCTL(KC_LEFT), KC_UP,   LCTL(KC_RGHT), LCTL(KC_BSPC), KC_BSPC,                            KC_7,    KC_8,    KC_9,    KC_PPLS, KC_PERC, KC_BSPC,
                      KC_PGDN, KC_LEFT,       KC_DOWN, KC_RGHT,       KC_DEL,        KC_BSPC,                            KC_4,    KC_5,    KC_6,    KC_PCMM, KC_MPRV, KC_MNXT,
                      KC_TRNS, KC_HOME,       KC_NO,   KC_END,        KC_NO,        KC_NO,       KC_TRNS,      KC_TRNS, KC_1,    KC_2,    KC_3,    KC_PEQL, KC_VOLD, KC_VOLU,
                      KC_TRNS, KC_TRNS,       KC_TRNS,       MO(_ADJUST), KC_TRNS,      KC_TRNS, KC_TRNS,   KC_0,    KC_PDOT, KC_PSCR
    ),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
        XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT  , XXXXXXX,XXXXXXX,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, QK_RGB_MATRIX_TOGGLE, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
