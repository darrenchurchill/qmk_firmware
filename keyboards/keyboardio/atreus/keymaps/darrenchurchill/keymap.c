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
#include "darrenchurchill.h"


#define LAYOUT_atreus_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_atreus_wrapper(
        _________________QWERTY_L1_________________,                                 _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,                                 _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, HYPR_T(KC_GRV), MEH_T(KC_MINS), _________________QWERTY_R3_________________,
        _________________BASE_5_L4_________________, KC_LSFT,        KC_BSPC,        _________________BASE_5_R4_________________
    ),

    [_LOWER] = LAYOUT_atreus_wrapper(
        _________________LOWER_L1__________________,                   _________________LOWER_R1__________________,
        _________________LOWER_L2__________________,                   _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________,
        ________________LOWER_5_L4_________________, _______, _______, ________________LOWER_5_R4_________________
    ),

    [_RAISE] = LAYOUT_atreus_wrapper(
        _________________RAISE_L1__________________,                   _________________RAISE_R1__________________,
        _________________RAISE_L2__________________,                   _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _______, KC_DEL,  _________________RAISE_R3__________________,
        ________________RAISE_5_L4_________________, _______, _______, ________________RAISE_5_R4_________________
    ),

    [_MOUSE] = LAYOUT_atreus_wrapper(
        _________________MOUSE_L1__________________,                   _________________MOUSE_R1__________________,
        _________________MOUSE_L2__________________,                   _________________MOUSE_R2__________________,
        _________________MOUSE_L3__________________, _______, _______, _________________MOUSE_R3__________________,
        ________________MOUSE_5_L4_________________, _______, _______, __________________BLANK_5__________________
    ),

    [_FN] = LAYOUT_atreus_wrapper(
        ___________________FN_L1___________________,                   ___________________FN_R1___________________,
        ___________________FN_L2___________________,                   ___________________FN_R2___________________,
        __________________BLANK_5__________________, _______, _______, ___________________FN_R3___________________,
        QK_BOOT, UKC_BASE, _______, _______, _______,  _______, _______, __________________BLANK_5__________________
    )
};
