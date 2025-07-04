/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum layers {
    _BASE,
    _NUMBERS,
    _FUNCTIONS,
    _PREFIX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------.                    ,-----------------------------------------------------.
                  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|-------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LT(_PREFIX, KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                 KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LCTL,
  //|-------------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                       MO(1), KC_LGUI,  KC_SPC,     KC_ENT, KC_LALT,   MO(2)
                                                 //`--------------------------'  `--------------------------'

  ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------.                    ,-----------------------------------------------------.
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,
  //|---------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LT(_PREFIX, KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_4,    KC_5,    KC_6, KC_PSLS, KC_LBRC, KC_RBRC,
  //|---------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                   KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_1,    KC_2,    KC_3, KC_PDOT,  KC_GRV, KC_BSLS,
  //|---------------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                       _______, KC_LGUI,  KC_SPC,     KC_ENT, KC_LALT, KC_LCTL
                                                   //`--------------------------'  `--------------------------'
  ),

    [_FUNCTIONS] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------.                    ,-----------------------------------------------------.
                 KC_TRNS,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_VOLU,                      XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT,
  //|-------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LT(_PREFIX, KC_TAB),   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLD,                      XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END,
  //|-------------------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                 KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_MUTE,                      XXXXXXX, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,
  //|-------------------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                     XXXXXXX, KC_LGUI,  KC_SPC,     KC_ENT, KC_LALT, _______
                                                 //`--------------------------'  `--------------------------'
  ),

    [_PREFIX] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Activate the prefix layer by holding TAB
    // TAB is available on all layers
    // The prefix layer will automatically sned Ctrl-A before any pressed keycode
    if (IS_LAYER_ON(_PREFIX) && record->event.pressed) {
        tap_code16(C(KC_A));
    }

    switch (keycode) {
        // Backspace key doubles as Delete key when shift is pressed
        case KC_BSPC: {
            static uint16_t registered_key = KC_NO;
            if (record->event.pressed) {
                const uint8_t mods = get_mods();

#ifndef NO_ACTION_ONESHOT
                uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif
                if (shift_mods) {
                    registered_key = KC_DEL;
                    // if one shift is held, clear it from the mods.
                    // But if both shifts are held, leave as is to send shift + del.
                    if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
                        del_oneshot_mods(MOD_MASK_SHIFT);
#endif
                        unregister_mods(MOD_MASK_SHIFT);
                    }
                } else {
                    registered_key = KC_BSPC;
                }

                register_code(registered_key);
                set_mods(mods);

            } else {
                unregister_code(registered_key);
            }
            return false;
        }
    }

    return true;
}
