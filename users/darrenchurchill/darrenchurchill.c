#include QMK_KEYBOARD_H
#include "print.h"
#include "os_detection.h"

#include "darrenchurchill.h"
#include "features/achordion.h"
#include "features/casemodes.h"
#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"
#include "features/leader.h"
#include "features/repeat_key.h"
#include "features/select_word.h"


#define IS_APPLE_OS(host_os) (host_os == OS_MACOS || host_os == OS_IOS)

__attribute__ ((weak))
void keyboard_post_init_keymap(void) {
    return;
}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
}


#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Return the current dynamic tapping term by default
    return g_tapping_term;
}
#endif // TAPPING_TERM_PER_KEY

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QKC_A:
        case QKC_SC:
        case BKC_V:
        case BKC_N:
            // Disable tap-hold repeat
            return 0;
    }
    return QUICK_TAP_TERM;
}
#endif // QUICK_TAP_TERM_PER_KEY


/*
  Achordion
  See https://getreuer.info/posts/keyboards/achordion/
*/
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    // consider the following keycodes as holds
    bool is_tap_hold_mod_tap = tap_hold_keycode & QK_MOD_TAP;
    uint8_t tap_hold_keycode_mods = QK_MODS_GET_MODS(tap_hold_keycode);

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_MASK_GUI) {
        switch (other_keycode) {
            case QKC_Q: // Cmd + Q -> quit
            case QKC_M: // Cmd + M -> minimize window
                return false; // Should wait for achordion's timeout
            case QKC_C:
            case QKC_V:
            case QKC_B:
            case BKC_N: // Cmd + Space
            case BKC_B: // Cmd + Tab
                return true;
        }
    }

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_MASK_SHIFT) {
        switch (other_keycode) {
            case BKC_B: // Shift + Tab
            case UKC_ARRW:
                return true;
        }
    }

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_MASK_ALT) {
        switch (other_keycode) {
            case BKC_B: // Alt + Tab
                return true;
        }
    }

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_MASK_CTRL) {
        switch (other_keycode) {
            // Left Hand
            case QKC_E:
            case QKC_A:
            case QKC_C:
            case QKC_V:
            case QKC_B:
            case BKC_B: // Ctrl + Tab
            // Right Hand
            case QKC_Y:
            case QKC_U:
            case QKC_I:
            case QKC_O:
                return true;
        }
    }

    if (QK_LAYER_TAP_GET_LAYER(tap_hold_keycode) == _LOWER) {
        switch (other_keycode) {
            case KC_BSPC:
            case BKC_N: // Space
            case BKC_M: // For layer lock w/ RHand
                return true;
        }
    }

    switch (tap_hold_keycode) {
        case HYPR_T(KC_GRV):
        case MEH_T(KC_MINS):
        case BKC_B:
        case BKC_M:
            return true;
    }

    // The default choice is to return true if the keys are on opposite hands
    return achordion_opposite_hands(tap_hold_record, other_record);
}


// See link above for per-keycode use of achordion_timeout()
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case BKC_N:
            // Bypass achordion
            return 0;
        case BKC_V:
            // This layer-tap key was frequently being changed from a hold->tap
            // when quickly pressing a key after holding the LT key, resulting
            // in tab + J, for example.
            return g_tapping_term;
    }

    // Default to default dynamic tapping term + nominal ms
    // Reducing the default achordion_timeout makes same-hand tap-hold combos
    // like LGUI_T(KC_M) + KC_SPACE on MacOS faster
    // I think this is the best option for this particular key combination,
    // because you somtimes also roll through M onto Space at the end of a word
    return g_tapping_term + 500;
}


/*
  Custom Shift Keys
  https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
*/
const custom_shift_key_t custom_shift_keys[] = {
    // I have these symbols' shifted variants on their own keys in the
    // _LOWER layer, so I don't want to shift them.
    {LKC_EQUAL, KC_EQUAL},
    {LKC_LBRC, KC_LBRC},
    {KC_RBRC, KC_RBRC},
    // Remaining custom shift keys
    {LKC_H, KC_AMPR}, // TODO: change LKC_H to KC_PIPE if you keep it here
    {LKC_E, KC_LABK},
    {LKC_R, KC_RABK},
    {UKC_LWR_SLSH, KC_BSLS},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


/*
  Case Modes:
  Caps Word and X-Case
  https://github.com/andrewjrae/kyria-keymap/tree/e3ad77dc4d48b8e6a842c9136c76c1021ab5976b#case-modes
*/

// Return `true` if the keycode should be considered part of the word you're
// typing, and x-case should use the default separator, `KC_UNDS`, or the value
// of DEFAULT_XCASE_SEPARATOR.
bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            return true;
    }
    return false;
}

// Returns true if the case modes should terminate, false if they continue
// Note that the keycodes given to this function will be stripped down to
// basic keycodes if they are dual function keys. Meaning a modtap on 'a'
// will pass KC_A rather than LSFT_T(KC_A).
// Case delimiters will also not be passed into this function.
bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        // Ignore these b/c they're part of the word you're typing
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        // Ignore these to be processed in process_record_user()
        case KC_ESC:
        case UKC_CW_TOGG:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

void toggle_screaming_snake_case(void) {
    if (get_xcase_state() == XCASE_ON) {
        disable_xcase();
    } else {
        enable_xcase();
    }
    toggle_caps_word();
}


/*
  Custom Userspace Leader Key
  https://github.com/andrewjrae/kyria-keymap/tree/master#userspace-leader-sequences
*/
void* leader_qmk_func(uint16_t keycode) {
    switch (keycode) {
        case KC_R:
            // "R" for reboot
            soft_reset_keyboard();
            break;
        case KC_B:
            // "B" for bootloader
            reset_keyboard();
            break;
        default:
            break;
    }
    return NULL;
}

void* leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_Q:
            // "Q" for QMK
            return leader_qmk_func;
        case KC_S:
            // "S" for snake_case
            // Also generic X-Case, see use_default_xcase_separator() above. You
            // can begin by typing a symbol to use that as the separator char.
            enable_xcase();
            break;
        case KC_D:
            // "D" is home row shift -> SCREAMING_SNAKE_CASE
            toggle_screaming_snake_case();
            break;
        case KC_C:
            // "C" for camelCase
            enable_xcase_with(OSM(MOD_LSFT));
            break;
        default:
            break;
    }
    return NULL;
}


/*
  Repeat Key
  https://getreuer.info/posts/keyboards/repeat-key/index.html
  TODO: are you still using repeat key?
*/
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        // Ignore the following keys
        case UKC_BASE ... UKC_OS_NEXT_TAB:  // My custom keycodes
        case KC_BACKSPACE:
        case KC_DELETE:
            return false;
    }

    return true;  // Other keys can be repeated.
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_repeated_keycode(uint16_t keycode, keyrecord_t* record) {
    if (get_repeat_key_count() > 0) {
        if (record->event.pressed) {
            register_code16(get_last_keycode());
        } else {
            unregister_code16(get_last_keycode());
        }
        return false;
    }
    return true;
}


void debug_process_record(uint16_t keycode, keyrecord_t* record) {
    dprintln("\n**** Process Record User ****");

    // Print statements modified from debug_event() and debug_record() in
    // action.c
    dprintf("RECORD: %04X%c(%u)",
            (record->event.key.row << 8 | record->event.key.col),
            (record->event.pressed ? 'd' : 'u'), record->event.time);
#ifndef NO_ACTION_TAPPING
    dprintf(":%u%c", record->tap.count, (record->tap.interrupted ? '-' : ' '));
#endif
    dprintf("\nKEYCODE: 0x%04X\n", keycode);
    dprintln("Mod Bits: GASC(R)GASC(L)");
    IGNORE_FORMAT_WARNING(dprintf("Cur Mods: 0b%08b\n", get_mods()));
}

// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
// There's also a good description of process_record_user() at link below:
// https://getreuer.info/posts/keyboards/macros/index.html#process_record_user-in-depth
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    debug_process_record(keycode, record);

    // https://github.com/andrewjrae/kyria-keymap/tree/master#userspace-leader-sequences
    if (!process_leader(keycode, record)) { return false; }
    // https://getreuer.info/posts/keyboards/achordion/
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    if (!process_select_word_or_line(keycode, record, SELWORD, SELLINE)) { return false; }
    if (!process_repeat_key_with_alt(keycode, record, UKC_REP, UKC_AREP)) {
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (!process_case_modes(keycode, record)) { return false; }

    // TODO: add macros to explicitly set the host_os, in case it can't be detected
    // these OS detection things might be better in a separate features file
    os_variant_t host_os = detected_host_os();
    uint8_t cur_mods = get_mods();
    uint8_t mod_tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

    // We generally only need to handle the key down event, and can let QMK
    // implicitly handle the key up events.
    if (record->event.pressed) {
        switch (keycode) {
            // _QWERTY layer keycodes
            case KC_ESC:
                if (caps_word_enabled() || get_xcase_state() == XCASE_ON) {
                    disable_caps_word();
                    disable_xcase();
                    return false;
                }
                if (get_highest_layer(layer_state) > _QWERTY_NO_MODS) {
                    // If we're on a layer higher than _QWERTY_NO_MODS, return to the
                    // _QWERTY layer instead of tapping KC_ESC. This includes cancelling
                    // the current One Shot mods & layer state.
                    clear_oneshot_mods();
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                    reset_oneshot_layer();
                    layer_move(_QWERTY);
                    return false;
                }
                return true;

            // _LOWER layer keycodes
            case LKC_D:
            case LKC_K:
            case LKC_L:
                // FIXME: the L/R parens register as <,> when repeated, b/c of
                // the custom shift key codes for 9 & 0. You might need to
                // change the non-basic mod-tap handling to a tap dance instead.
                // https://docs.qmk.fm/#/feature_tap_dance?id=example-5
                if (!process_repeated_keycode(keycode, record)) { return false; }

                // Let QMK process the hold action
                if (!record->tap.count) { return true; }

                // Handle the tap of a non-basic mod-tap keycode
                set_last_mods(MOD_BIT_LSHIFT);
                set_last_keycode(mod_tap_kc);

                register_weak_mods(MOD_BIT_LSHIFT);
                tap_code16(mod_tap_kc);
                unregister_weak_mods(MOD_BIT_LSHIFT);
                return false;

            // My custom keycodes
            case UKC_BASE:
                // It's normally recommended to use layer_move() rather than
                // layer_state_set()
                // See: https://docs.qmk.fm/#/feature_layers?id=functions
                // but the default_layer_state variable is already a layer_mask, so
                // it's easy enough this way.
                layer_state_set(default_layer_state); // move back to cur default layer
                return false;

            case UKC_OS_COPY:
                if (IS_APPLE_OS(host_os)) tap_code16(LGUI(KC_C));
                else tap_code16(LCTL(KC_C));
                return false;

            case UKC_OS_PASTE:
                if (IS_APPLE_OS(host_os)) tap_code16(LGUI(KC_V));
                else tap_code16(LCTL(KC_V));
                return false;

            case UKC_OS_PREV_TAB:
                if (IS_APPLE_OS(host_os)) tap_code16(SGUI(KC_LBRC));
                else tap_code16(LCTL(KC_PGUP));
                return false;

            case UKC_OS_NEXT_TAB:
                if (IS_APPLE_OS(host_os)) tap_code16(SGUI(KC_RBRC));
                else tap_code16(LCTL(KC_PGDN));
                return false;

            case UKC_OS_PREV_SPACE:
                if (IS_APPLE_OS(host_os)) tap_code16(LCTL(KC_LEFT));
                else tap_code16(LCA(KC_UP)); // TODO: confirm this is correct for Ubuntu
                return false;

            case UKC_OS_NEXT_SPACE:
                if (IS_APPLE_OS(host_os)) tap_code16(LCTL(KC_RIGHT));
                else tap_code16(LCA(KC_DOWN)); // TODO: confirm this is correct for Ubuntu
                return false;

            case UKC_ARRW:
                // Handle my custom keycode for a single arrow
                if (cur_mods & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_EQUAL);
                    set_mods(cur_mods);
                } else {
                    tap_code16(KC_MINS);
                }
                tap_code16(KC_RABK);
                return false;

            case UKC_DB_MINS:
                // Handle my custom keycode for a double minus/dash
                tap_code16(KC_MINS);
                tap_code16(KC_MINS);
                return false;

            case UKC_DB_UNDS:
                // Handle my custom keycode for a double underscore
                tap_code16(KC_UNDS);
                tap_code16(KC_UNDS);
                return false;

            case UKC_LWR_SLSH:
                // The only way to get here is if process_custom_shift_keys()
                // returns true, so we know Shift is not held.
                tap_code16(KC_SLSH);
                return false;

            case UKC_CW_TOGG:
                toggle_screaming_snake_case();
                return false;

            case UKC_LEAD:
                start_leading();
                return false;
        }
    }

    dprintln("**** End Process Record User ****\n");

    return process_record_keymap(keycode, record);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
    achordion_task();
    select_word_task();

    matrix_scan_keymap();
}
