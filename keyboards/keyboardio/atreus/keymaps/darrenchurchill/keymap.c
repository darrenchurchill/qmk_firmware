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

// TODO: Try figuring out why flashing from command line doesn't work
// You can still flash from QMK Toolbox for now
// Try updating to the latest breaking changes tag
// Review QMK's flashing documentation to see what's happening with AVRDude

#define LAYOUT_atreus_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_atreus_wrapper(
        ________________COLEMAK_L1_________________,                   ________________COLEMAK_R1_________________,
        ________________COLEMAK_L2_________________,                   ________________COLEMAK_R2_________________,
        ________________COLEMAK_L3_________________, TKC_L10, TKC_R10, ________________COLEMAK_R3_________________,
        _____________________BASE_6_L4____________________,      _____________________BASE_6_R4____________________
    ),

    [_QWERTY] = LAYOUT_atreus_wrapper(
        _________________QWERTY_L1_________________,                   _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,                   _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, TKC_L10, TKC_R10, _________________QWERTY_R3_________________,
        _____________________BASE_6_L4____________________,      _____________________BASE_6_R4____________________
    ),

    [_LOWER] = LAYOUT_atreus_wrapper(
        _________________LOWER_L1__________________,                   _________________LOWER_R1__________________,
        _________________LOWER_L2__________________,                   _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________,
        ________________LOWER_5_L4_________________, _______, _______, ________________LOWER_5_R4_________________
    ),

    [_NUMPAD] = LAYOUT_atreus_wrapper(
        _________________NUMPAD_L1_________________,                   _________________NUMPAD_R1_________________,
        _________________NUMPAD_L2_________________,                   _________________NUMPAD_R2_________________,
        _________________NUMPAD_L3_________________, _______, _______, _________________NUMPAD_R3_________________,
        ________________NUMPAD_5_L4________________, _______, _______, ________________NUMPAD_5_R4________________
    ),

    [_RAISE] = LAYOUT_atreus_wrapper(
        _________________RAISE_L1__________________,                   _________________RAISE_R1__________________,
        _________________RAISE_L2__________________,                   _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _______, KC_DEL,  _________________RAISE_R3__________________,
        ________________RAISE_5_L4_________________, _______, _______, ________________RAISE_5_R4_________________
    ),

    [_EXTEND] = LAYOUT_atreus_wrapper(
        _________________EXTEND_L1_________________,                   _________________EXTEND_R1_________________,
        _________________EXTEND_L2_________________,                   _________________EXTEND_R2_________________,
        _________________EXTEND_L3_________________, _______, _______, _________________EXTEND_R3_________________,
        ________________EXTEND_5_L4________________, _______, _______, ________________EXTEND_5_R4________________
    ),

    [_ARROWS] = LAYOUT_atreus_wrapper(
        __________________BLANK_5__________________,                   __________________BLANK_5__________________,
        _________________ARROWS_L2_________________,                   _________________ARROWS_R2_________________,
        _________________ARROWS_L3_________________, _______, _______, __________________BLANK_5__________________,
        ________________ARROWS_5_R4________________, _______, _______, __________________BLANK_5__________________
    ),

    [_MOUSE] = LAYOUT_atreus_wrapper(
        _________________MOUSE_L1__________________,                   _________________MOUSE_R1__________________,
        _________________MOUSE_L2__________________,                   _________________MOUSE_R2__________________,
        _________________MOUSE_L3__________________, _______, _______, _________________MOUSE_R3__________________,
        ________________MOUSE_5_L4_________________, _______, _______, _________________MOUSE_5_R4________________
    ),

    [_FN] = LAYOUT_atreus_wrapper(
        ___________________FN_L1___________________,                   ___________________FN_R1___________________,
        ___________________FN_L2___________________,                   ___________________FN_R2___________________,
        ___________________FN_L3___________________, _______, _______, ___________________FN_R3___________________,
        _______, UKC_BASE, _______, _______, _______, _______, _______, __________________BLANK_5__________________
    )
};
