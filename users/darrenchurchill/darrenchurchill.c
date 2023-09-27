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


#ifdef TAP_DANCE_ENABLE
typedef enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t step;
} td_tap_t;

static td_tap_t dance_state[1];

td_state_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            tap_code16(KC_DQUO);
            break;
        case DOUBLE_TAP:
            layer_move(_LAYERS);
            break;
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
        case DOUBLE_SINGLE_TAP:
        case MORE_TAPS:
            // Do nothing;
            break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
};
#endif // TAP_DANCE_ENABLE


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
            case QKC_C:
            case QKC_V:
            case QKC_B:
            case BKC_N: // Cmd + Space
            case KC_TAB:
                return true;
        }
    }

    if (tap_hold_keycode_mods & MOD_MASK_SHIFT) {
        switch (other_keycode) {
            case LWR: // Shift + Tab
            case KC_TAB:
            case KC_ENT:
                return true;
        }
    }

    if (tap_hold_keycode_mods & MOD_MASK_ALT) {
        switch (other_keycode) {
            case BKC_B: // Alt + Tab
            case KC_TAB:
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
            // Right Hand
            case QKC_Y:
            case QKC_U:
            case QKC_I:
            case QKC_O:
            case KC_TAB:
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
        case LKC_A:
        case LKC_S:
        case LKC_D:
        case LKC_F:
        case LKC_G:
        case LKC_H:
        case LKC_J:
        case LKC_K:
        case LKC_L:
        case LKC_SC:
        case UKC_LWR_SLSH:
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
        case LKC_A:
            register_code16((!shifted) ? LKC_A : KC_7);
            break;
        case LKC_S:
            register_code16((!shifted) ? LKC_S : KC_8);
            break;
        case LKC_D:
            register_code16((!shifted) ? LKC_D : KC_9);
            break;
        case LKC_F:
            register_code16((!shifted) ? LKC_F : KC_0);
            break;
        case LKC_G:
            register_code16((!shifted) ? LKC_G : KC_5);
            break;
        case LKC_H:
            register_code16((!shifted) ? LKC_H : KC_6);
            break;
        case LKC_J:
            register_code16((!shifted) ? LKC_J : KC_1);
            break;
        case LKC_K:
            register_code16((!shifted) ? LKC_K : KC_2);
            break;
        case LKC_L:
            register_code16((!shifted) ? LKC_L : KC_3);
            break;
        case LKC_SC:
            register_code16((!shifted) ? LKC_SC : KC_4);
            break;
        case UKC_LWR_SLSH:
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
        case LKC_A:
            unregister_code16((!shifted) ? LKC_A : KC_7);
            break;
        case LKC_S:
            unregister_code16((!shifted) ? LKC_S : KC_8);
            break;
        case LKC_D:
            unregister_code16((!shifted) ? LKC_D : KC_9);
            break;
        case LKC_F:
            unregister_code16((!shifted) ? LKC_F : KC_0);
            break;
        case LKC_G:
            unregister_code16((!shifted) ? LKC_G : KC_5);
            break;
        case LKC_H:
            unregister_code16((!shifted) ? LKC_H : KC_6);
            break;
        case LKC_J:
            unregister_code16((!shifted) ? LKC_J : KC_1);
            break;
        case LKC_K:
            unregister_code16((!shifted) ? LKC_K : KC_2);
            break;
        case LKC_L:
            unregister_code16((!shifted) ? LKC_L : KC_3);
            break;
        case LKC_SC:
            unregister_code16((!shifted) ? LKC_SC : KC_4);
            break;
        case UKC_LWR_SLSH:
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
    {LKC_A, KC_7},
    {LKC_S, KC_8},
    {LKC_D, KC_9},
    {LKC_F, KC_0},
    {LKC_G, KC_5},
    {LKC_H, KC_6},
    {LKC_J, KC_1},
    {LKC_K, KC_2},
    {LKC_L, KC_3},
    {LKC_SC, KC_4},
    {UKC_LWR_SLSH, KC_BSLS},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


/*
  Repeat Key
  https://getreuer.info/posts/keyboards/repeat-key/index.html
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
            // Handle non-basic keycode KC_PLUS
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PLUS);
                return false;
            }
            return true;

        case LKC_K:
            // Handle non-basic keycode KC_LPRN
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
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

        case UKC_SG_ARRW:
            // Handle my custom keycode for a single arrow
            if (record->event.pressed) {
                tap_code16(KC_MINS);
                tap_code16(KC_RABK);
            }
            return false;

        case UKC_DB_ARRW:
            // Handle my custom keycode for a double arrow
            if (record->event.pressed) {
                tap_code16(KC_EQUAL);
                tap_code16(KC_RABK);
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
