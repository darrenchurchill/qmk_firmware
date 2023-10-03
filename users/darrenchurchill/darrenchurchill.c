#include QMK_KEYBOARD_H
#include "os_detection.h"

#include "darrenchurchill.h"
#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/repeat_key.h"


// helper function for some macros in process_record_user()
os_variant_t get_host_os(void) {
    static os_variant_t host_os = OS_UNSURE;

    if (host_os == OS_UNSURE) {
        host_os = detected_host_os();
    }

    return host_os;
}

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
    uint8_t tap_hold_keycode_mods = QK_MODS_GET_MODS(tap_hold_keycode);

    if (tap_hold_keycode_mods & MOD_MASK_GUI) {
        switch (other_keycode) {
            case QKC_Q:
                return false; // Any Cmd + Q should wait for achordion's timeout
            case QKC_C:
            case QKC_V:
            case QKC_B:
            case BKC_N: // Cmd + Space
            case BKC_B: // Cmd + Tab
                return true;
        }
    }

    if (tap_hold_keycode_mods & MOD_MASK_SHIFT) {
        switch (other_keycode) {
            case LWR: // Shift + Tab
            case UKC_ARRW:
                return true;
        }
    }

    if (tap_hold_keycode_mods & MOD_MASK_ALT) {
        switch (other_keycode) {
            case BKC_B: // Alt + Tab
                return true;
        }
    }

    if (tap_hold_keycode_mods & MOD_MASK_CTRL) {
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
  Auto Shift Per Key, in addition to the config in config.h
  https://docs.qmk.fm/#/feature_auto_shift
*/
__attribute__ ((weak))
bool get_custom_auto_shifted_key_keymap(uint16_t keycode, keyrecord_t *record) {
    return false;
}

// This is the code from the default function, but calls *_keymap() fn instead
// See quantum/process_keycode/process_auto_shift.c
bool get_default_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
        case AUTO_SHIFT_ALPHA:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
        case AUTO_SHIFT_NUMERIC:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
        case AUTO_SHIFT_SPECIAL:
#    endif
            return true;
    }

    return get_custom_auto_shifted_key_keymap(keycode, record);
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LBRC:
        case KC_RBRC:
            // I have these symbols' shifted varients on their own keys in the
            // _LOWER layer, so I don't want to auto-shift them.
            return false;
        case LKC_H: // TODO: remove if you keep ampersand on it's own key
        case LKC_X: // TODO: remove is you keep backslash on it's own key
            return true;
    }
    return get_default_auto_shifted_key(keycode, record);
}

// The default function, overrode to re-plumb the order default cases are
// checked. This way I can override KC_0 and KC_9 while leaving
// AUTO_SHIFT_NUMERIC enabled
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    return get_custom_auto_shifted_key(keycode, record);
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case LKC_H:
            register_code16((!shifted) ? KC_PIPE : KC_AMPR);
            break;
        case LKC_X:
            register_code16((!shifted) ? KC_SLSH : KC_BSLS);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case LKC_H:
            unregister_code16((!shifted) ? KC_PIPE : KC_AMPR);
            break;
        case LKC_X:
            unregister_code16((!shifted) ? KC_SLSH : KC_BSLS);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using the
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}


/*
  Custom Shift Keys
  https://getreuer.info/posts/keyboards/custom-shift-keys/index.html

  Note: anything you add here that you also want Auto Shift to act on, you need
        to add to the Auto Shift pipeline functions above.
*/
const custom_shift_key_t custom_shift_keys[] = {
    // I have these symbols' shifted variants on their own keys in the
    // _LOWER layer, so I don't want to shift them.
    {KC_LBRC, KC_LBRC},
    {KC_RBRC, KC_RBRC},
    // Remaining custom shift keys
    {LKC_H, KC_AMPR}, // TODO: change LKC_H to KC_PIPE if you keep it here
    {UKC_LWR_SLSH, KC_BSLS},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


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


// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // https://getreuer.info/posts/keyboards/achordion/
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_repeat_key_with_alt(keycode, record, UKC_REP, UKC_AREP)) {
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    static os_variant_t host_os = OS_UNSURE;
    host_os = detected_host_os();
    uint8_t cur_mods = get_mods();
    uint8_t mod_tap_kc = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    uint8_t mod_tap_mods = QK_MOD_TAP_GET_MODS(keycode);

    switch (keycode) {
        // _QWERTY layer keycodes
        case KC_ESC:
            if (record->event.pressed
                    && get_highest_layer(layer_state) > _QWERTY_NO_MODS) {
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
            if (!process_repeated_keycode(keycode, record)) { return false; }

            // Handle non-basic mod-tap keycode
            if (record->tap.count && record->event.pressed) {
                set_last_mods(mod_tap_mods);
                set_last_keycode(mod_tap_kc);

                register_weak_mods(mod_tap_mods);
                tap_code16(mod_tap_kc);
                unregister_weak_mods(mod_tap_mods);
                return false;
            }
            return true;

        // My custom keycodes
        case UKC_BASE:
            if (!record->event.pressed) return false; // already processed
            // It's normally recommended to use layer_move() rather than
            // layer_state_set()
            // See: https://docs.qmk.fm/#/feature_layers?id=functions
            // but the default_layer_state variable is already a layer_mask, so
            // it's easy enough this way.
            layer_state_set(default_layer_state); // move back to cur default layer
            return false;

        case UKC_OS_COPY:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(LGUI(KC_C));
                } else {
                    tap_code16(LCTL(KC_C));
                }
            }
            return false;

        case UKC_OS_PASTE:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(LGUI(KC_V));
                } else {
                    tap_code16(LCTL(KC_V));
                }
            }
            return false;

        case UKC_OS_PREV_TAB:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(SGUI(KC_LBRC));
                } else {
                    tap_code16(LCTL(KC_PGUP));
                }
            }
            return false;

        case UKC_OS_NEXT_TAB:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(SGUI(KC_RBRC));
                } else {
                    tap_code16(LCTL(KC_PGDN));
                }
            }
            return false;

        case UKC_OS_PREV_SPACE:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(LCTL(KC_LEFT));
                } else {
                    // TODO: confirm this is correct for Ubuntu
                    tap_code16(LCA(KC_UP));
                }
            }
            return false;

        case UKC_OS_NEXT_SPACE:
            if (record->event.pressed) {
                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(LCTL(KC_RIGHT));
                } else {
                    // TODO: confirm this is correct for Ubuntu
                    tap_code16(LCA(KC_DOWN));
                }
            }
            return false;

        case UKC_ARRW:
            // Handle my custom keycode for a single arrow
            if (record->event.pressed) {
                if (cur_mods & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_EQUAL);
                    set_mods(cur_mods);
                } else {
                    tap_code16(KC_MINS);
                }
                tap_code16(KC_RABK);
            }
            return false;

        case UKC_DB_MINS:
            // Handle my custom keycode for a double minus/dash
            if (record->event.pressed) {
                tap_code16(KC_MINS);
                tap_code16(KC_MINS);
            }
            return false;

        case UKC_DB_UNDS:
            // Handle my custom keycode for a double underscore
            if (record->event.pressed) {
                tap_code16(KC_UNDS);
                tap_code16(KC_UNDS);
            }
            return false;
    }

    return process_record_keymap(keycode, record);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
    achordion_task();

    matrix_scan_keymap();
}
