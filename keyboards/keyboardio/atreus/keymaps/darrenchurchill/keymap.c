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
    KC_Q,          KC_W,          KC_E,        KC_R,        KC_T,                             KC_Y,   KC_U,        KC_I,           KC_O,          KC_P,
    KC_A,          KC_S,          KC_D,        KC_F,        KC_G,                             KC_H,   KC_J,        KC_K,           KC_L,          KC_SCLN,
    LCTL_T(KC_Z),  ALT_T(KC_X),   SFT_T(KC_C), GUI_T(KC_V), KC_B,    HYPR_T(KC_GRV), KC_MINS, KC_N,   GUI_T(KC_M), SFT_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_SLSH),
    CTL_T(KC_GRV), ALT_T(KC_ESC), KC_TAB,      KC_LGUI,     MO(_LW), KC_LGUI,        KC_BSPC, KC_SPC, MO(_RS),     KC_ENT,         KC_QUOT,       KC_DQUO
    ),

  [_LW] = LAYOUT( /* [> Lower <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_UNDS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, KC_TRNS, KC_TRNS, KC_PLUS, KC_MINS, KC_EQUAL,KC_LCBR, KC_RCBR,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

  [_RS] = LAYOUT( /* [> Raise <] */
    KC_MUTE, KC_TRNS, KC_KB_VOLUME_UP,   KC_TRNS, KC_TRNS,                   KC_HOME, KC_PGDN,       KC_PGUP,       KC_END,   KC_MPLY,
    KC_TRNS, KC_MPRV, KC_KB_VOLUME_DOWN, KC_MNXT, KC_TRNS,                   KC_LEFT, KC_DOWN,       KC_UP,         KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, QK_BOOT, QK_RBT,  KC_DEL,  KC_TRNS, SGUI(KC_LBRC), SGUI(KC_RBRC), KC_TRNS,  KC_TRNS,
    CW_TOGG, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_TRNS
    )
};

qk_tap_dance_action_t tap_dance_actions[] = {

};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};
