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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,         KC_W,        KC_E,        KC_R,        KC_T,                                   KC_Y,            KC_U,        KC_I,           KC_O,          KC_P,
    KC_A,         KC_S,        KC_D,        KC_F,        KC_G,                                   KC_H,            KC_J,        KC_K,           KC_L,          KC_SCLN,
    LCTL_T(KC_Z), ALT_T(KC_X), SFT_T(KC_C), GUI_T(KC_V), KC_B,    KC_ESC,         KC_ENT,        KC_N,            GUI_T(KC_M), SFT_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_SLSH),
    KC_GRV,       KC_LCTL,     KC_LALT,     KC_LGUI,     MO(_LW), SFT_T(KC_BSPC), SFT_T(KC_SPC), LT(_RS, KC_TAB), KC_QUOT,     KC_MINS,        KC_EQUAL,      KC_BSLS
    ),

  [_LW] = LAYOUT( /* [> Lower <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS,
    KC_QUOT, KC_DQUO, KC_LCBR, KC_LPRN, KC_LBRC,                   KC_UNDS, KC_4,    KC_5,    KC_6,    KC_MINS,
    KC_CIRC, KC_AMPR, KC_RCBR, KC_RPRN, KC_RBRC, KC_TRNS, KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_EQUAL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,  KC_TILD, KC_PIPE, KC_TRNS
    ),

  [_RS] = LAYOUT( /* [> Raise <] */
    KC_TRNS, KC_TRNS, KC_KB_VOLUME_UP,   KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN,       KC_PGUP,       KC_END,   KC_TRNS,
    KC_TRNS, KC_MPRV, KC_KB_VOLUME_DOWN, KC_MNXT, KC_TRNS,                   KC_LEFT, KC_DOWN,       KC_UP,         KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MUTE,           KC_TRNS, QK_BOOT, QK_RBT,  KC_TRNS, KC_TRNS, SGUI(KC_LBRC), SGUI(KC_RBRC), KC_TRNS,  KC_TRNS,
    NK_ON,   NK_OFF,  KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_MPLY
    )
};

qk_tap_dance_action_t tap_dance_actions[] = {

};
