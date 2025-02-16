#include QMK_KEYBOARD_H
#include "print.h"
#include "os_detection.h"
#include "repeat_key.h"

#include "darrenchurchill.h"
#include "features/achordion.h"
#include "features/casemodes.h"
#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"
#include "features/leader.h"
#include "features/select_word.h"


#define IS_APPLE_OS(host_os) (host_os == OS_MACOS || host_os == OS_IOS)

__attribute__ ((weak))
void keyboard_post_init_keymap(void) {
    return;
}

void keyboard_post_init_user(void) {
    // https://docs.qmk.fm/#/faq_debug?id=debugging
    // Uncomment any of the debug_* variables to enable debug modes at boot
    // You need CONSOLE_ENABLE = yes in your rules.mk to use these
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;
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
    // Disable tap-hold repeat for layer-tap keys to the below layers
    switch (QK_LAYER_TAP_GET_LAYER(keycode)) {
        case _LOWER: // This LT key is usually on the home row
        case _ARROWS: // This LT key is usually on the R thumb
            return 0;
    }

    return QUICK_TAP_TERM;
}
#endif // QUICK_TAP_TERM_PER_KEY

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#endif // HOLD_ON_OTHER_KEY_PRESS_PER_KEY


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
    uint8_t other_keycode_basic_kc = QK_MODS_GET_BASIC_KEYCODE(other_keycode);

    // A mod-tap tap-hold keycode stores the modifier in the 5 bit form, so in
    // the following 4 tests, we can & with the Left Hand MOD_L* values to check
    // for either the Left or Right hand version. The left/right flag is stored
    // in its own bit.
    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_LGUI) {
        switch (other_keycode_basic_kc) {
            // TODO: swap with cases for CKC_* macros, and leave any QKC_* cases
            // that don't overlap
            // case CKC_Q:
            // case CKC_M:
            // case CKC_C:
            // case CKC_V:
            // case CKC_B:
            case KC_Q: // Cmd + Q -> quit
            case KC_M: // Cmd + M -> minimize window
                return false; // Should wait for achordion's timeout
            // I think C, V, & B were here to handle the case where GUI was the
            // tap hold key on either the left bottom row or the left thumb
            // case KC_C:
            // case KC_V:
            // case KC_B:
            case KC_SPC: // Cmd + Space
            case KC_TAB: // Cmd + Tab, (combo TAB, which achordion can't determine handedness for)
                return true;
        }
    }

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_LSFT) {
        switch (other_keycode_basic_kc) {
            case KC_TAB: // Shift + Tab, (combo TAB, which achordion can't determine handedness for)
                return true;
        }
    }

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_LALT) {
        switch (other_keycode_basic_kc) {
            case KC_TAB: // Alt + Tab, (combo TAB, which achordion can't determine handedness for)
                return true;
        }
    }

    if (is_tap_hold_mod_tap && tap_hold_keycode_mods & MOD_LCTL) {
        switch (other_keycode_basic_kc) {
            case KC_TAB: // Ctrl + Tab, (combo TAB, which achordion can't determine handedness for)
                return true;
        }
    }

    if (QK_LAYER_TAP_GET_LAYER(tap_hold_keycode) == _LOWER) {
        switch (other_keycode_basic_kc) {
            case KC_BSPC:
            case KC_SPC:
                return true;
        }
    }

    // The default choice is to return true if the keys are on opposite hands
    return achordion_opposite_hands(tap_hold_record, other_record);
}


// See link above for per-keycode use of achordion_timeout()
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case TKC_L00: // Bypass achordion for thumb keys
        case TKC_L01:
        case TKC_L02:
        case TKC_L10:
        case TKC_R00:
        case TKC_R01:
        case TKC_R02:
        case TKC_R10:
            return 0;  // Bypass achordion
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
    {KC_LBRC, KC_LBRC},
    {KC_RBRC, KC_RBRC},
    // Remaining custom shift keys
    {LKC_H, KC_AMPR}, // TODO: change LKC_H to KC_PIPE if you keep it here
    {LKC_E, KC_LABK},
    {LKC_R, KC_RABK},
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
    if (caps_word_enabled() || get_xcase_state() == XCASE_ON) {
        if (caps_word_enabled()) disable_caps_word();
        if (get_xcase_state() == XCASE_ON) disable_xcase();
    } else {
        enable_xcase();
        enable_caps_word();
    }
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
  https://docs.qmk.fm/#/feature_repeat_key
  TODO: are you still using repeat key?
*/
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        // Ignore the following keys

        // You might want to add other ranges from keycodes.h as necessary. I'm
        // trying to limit them here to the ones I use, to hopefully avoid
        // unexpected issues.
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) return false; // ignore the hold event
            break;

        case KC_BACKSPACE:
        case KC_DELETE:
        case KC_ENTER:

        // Custom keycodes I want to ignore
        case UKC_OS_CUT ... UKC_OS_PASTE:
        case UKC_LARRW ... UKC_DB_UNDS:
        case UKC_CW_TOGG:
        case UKC_XCASE:
            return false;
    }

    return true;  // Other keys can be repeated.
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


/*
  Tap Dance
*/
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} td_tap_hold_t;

void td_tap_hold_finished(tap_dance_state_t* state, void* user_data) {
    td_tap_hold_t* tap_hold = (td_tap_hold_t*)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            if (IS_QK_LAYER_MOD(tap_hold->hold)) {
                layer_on(QK_LAYER_MOD_GET_LAYER(tap_hold->hold));
                // FIXME: Using `register_weak_mods()` caused the modifiers to
                // be released before another key's (ex: "l") up event. I don't
                // know if I've done something wrong somewhere, but this is fine
                // for now. The problem with using `register_mods()` is its
                // meant to track the real key state, so you can lose a modifier
                // if you press and release an overlapping real modifier while
                // this tap_hold key is held down.
                register_mods(QK_LAYER_MOD_GET_MODS(tap_hold->hold));
            } else {
                register_code16(tap_hold->hold);
            }
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void td_tap_hold_reset(tap_dance_state_t* state, void* user_data) {
    td_tap_hold_t* tap_hold = (td_tap_hold_t*)user_data;

    if (tap_hold->held) {
        if (IS_QK_LAYER_MOD(tap_hold->held)) {
            layer_off(QK_LAYER_MOD_GET_LAYER(tap_hold->held));
            unregister_mods(QK_LAYER_MOD_GET_MODS(tap_hold->held));
        } else {
            unregister_code16(tap_hold->held);
        }
        tap_hold->held = 0;
    }
}

#define ACTION_TD_TAP_HOLD(tap, hold) \
    { .fn = {NULL, td_tap_hold_finished, td_tap_hold_reset}, \
      .user_data = (void*)&((td_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL_T_OS_PREV_SPACE] = ACTION_TD_TAP_HOLD(UKC_OS_PREV_SPACE, KC_LCTL),
    [TD_LALT_T_OS_NEXT_SPACE] = ACTION_TD_TAP_HOLD(UKC_OS_NEXT_SPACE, KC_LALT),
    [TD_LSFT_T_OS_PREV_TAB] = ACTION_TD_TAP_HOLD(UKC_OS_PREV_TAB, KC_LSFT),
    [TD_LGUI_T_OS_NEXT_TAB] = ACTION_TD_TAP_HOLD(UKC_OS_NEXT_TAB, KC_LGUI),
    [TD_LT_QWERTY_ALT_SHIFT_F] = ACTION_TD_TAP_HOLD(KC_F, LM(_QWERTY, MOD_LALT | MOD_LSFT)),
};


/*
  Process Record
*/
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

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
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
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (!process_case_modes(keycode, record)) { return false; }

    // TODO: add macros to explicitly set the host_os, in case it can't be detected
    // these OS detection things might be better in a separate features file
    os_variant_t host_os = detected_host_os();
    uint8_t mod_tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    static bool is_processing_tap_dance = false;

    // We generally only need to handle the key down event, and can let QMK
    // implicitly handle the key up events.
    // An exception is when we're recursively processing a keycode fired from
    // a tap dance tap-hold key. In that case, we need to handle the key up.
    if (record->event.pressed || is_processing_tap_dance) {
        switch (keycode) {
            // _QWERTY layer keycodes
            case KC_ESC:
                if (caps_word_enabled() || get_xcase_state() == XCASE_ON) {
                    disable_caps_word();
                    disable_xcase();
                    return false;
                }
                if (get_highest_layer(layer_state) > _COLEMAK) {
                    // If we're on a layer higher than _COLEMAK, return to the
                    // _COLEMAK layer instead of tapping KC_ESC. This includes
                    // cancelling the current One Shot mods & layer state.
                    clear_oneshot_mods();
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                    reset_oneshot_layer();
                    layer_move(_COLEMAK);
                    return false;
                }
                return true;

            // _LOWER layer keycodes
            case LKC_D:
            case LKC_J:
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

            case UKC_OS_CUT:
                if (IS_APPLE_OS(host_os)) tap_code16(LGUI(KC_C));
                else tap_code16(LCTL(KC_X));
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

            case UKC_LARRW:
                SEND_STRING("<-");
                return false;

            case UKC_RARRW:
                SEND_STRING("->");
                return false;

            case UKC_DBRARRW:
                SEND_STRING("=>");
                return false;

            case UKC_LEQ:
                SEND_STRING("<=");
                return false;

            case UKC_GEQ:
                SEND_STRING(">=");
                return false;

            case UKC_TRP_GRAVE:
                SEND_STRING("```");
                return false;

            case UKC_DB_MINS:
                SEND_STRING("--");
                return false;

            case UKC_DB_UNDS:
                SEND_STRING("__");
                return false;

            case UKC_CW_TOGG:
                toggle_screaming_snake_case();
                return false;

            case UKC_LEAD:
                start_leading();
                return false;

            case UKC_XCASE:
                enable_xcase();
                return false;
        }
    }

    // Tap Dance keycodes
    switch (keycode) {
        // tap-hold custom tap dance keycodes:
        case TD_OS_PTAB:
        case TD_OS_NTAB:
        case TD_OS_PSPC:
        case TD_OS_NSPC:
        case TD_LT_QAS_F:
        {
            tap_dance_action_t* action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed &&
                action->state.count &&
                !action->state.finished
            ) {
                td_tap_hold_t* tap_hold = (td_tap_hold_t*)action->user_data;
                if (IS_QK_USER(tap_hold->tap)) {
                    record->keycode = tap_hold->tap;
                    is_processing_tap_dance = true;
                    process_record_user(record->keycode, record);
                    is_processing_tap_dance = false;
                } else {
                    tap_code16(tap_hold->tap);
                }
            }
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
