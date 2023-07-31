/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H


enum layer_names {
    _QW,
    _RS,
    _LW,
    _MOUSE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,          KC_W,          KC_E,        KC_R,        KC_T,                                    KC_Y,   KC_U,        KC_I,           KC_O,          KC_P,
    KC_A,          KC_S,          KC_D,        KC_F,        KC_G,                                    KC_H,   KC_J,        KC_K,           KC_L,          KC_SCLN,
    LCTL_T(KC_Z),  ALT_T(KC_X),   SFT_T(KC_C), GUI_T(KC_V), KC_B,    HYPR_T(KC_GRV), MEH_T(KC_MINS), KC_N,   GUI_T(KC_M), SFT_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_SLSH),
    CTL_T(KC_GRV), ALT_T(KC_ESC), KC_TAB,      KC_LGUI,     MO(_LW), KC_LSFT,        KC_BSPC,        KC_SPC, MO(_RS),     KC_ENT,         KC_QUOT,       KC_MINS
    ),

  [_LW] = LAYOUT( /* [> Lower <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,       KC_8,     KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_UNDS, KC_LBRC,    KC_RBRC,  KC_LPRN, KC_RPRN,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, _______, _______, KC_PLUS, KC_MINS,    KC_EQUAL, KC_LCBR, KC_RCBR,
    _______, _______, _______, _______, _______, _______, _______, _______, MO(_MOUSE), KC_TILDE, KC_GRV,  _______
    ),

  [_RS] = LAYOUT( /* [> Raise <] */
    KC_MUTE, _______, KC_KB_VOLUME_UP,   _______, _______,                   KC_HOME, KC_PGDN,       KC_PGUP,       KC_END,        KC_MPLY,
    _______, KC_MPRV, KC_KB_VOLUME_DOWN, KC_MNXT, _______,                   KC_LEFT, KC_DOWN,       KC_UP,         KC_RIGHT,      _______,
    _______, _______, _______,           _______, QK_BOOT, _______,  KC_DEL, _______, SGUI(KC_LBRC), SGUI(KC_RBRC), LCTL(KC_PGUP), LCTL(KC_PGDN),
    CW_TOGG, _______, _______,           _______, MO(_FN), _______, _______, _______, _______,       _______,       _______,       _______
    ),

  [_MOUSE] = LAYOUT( /* [> Mouse <] */
    _______, _______, _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, KC_BTN1, KC_BTN2,                   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

  [_FN] = LAYOUT( /* [> Function <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_RBT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

qk_tap_dance_action_t tap_dance_actions[] = {

};
