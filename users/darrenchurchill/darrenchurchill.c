#include QMK_KEYBOARD_H
#include "os_detection.h"

#include "darrenchurchill.h"
#include "achordion.h"


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
        case QNM_T(KC_TAB):
        case LSFT_T(KC_SPC):
        case RSE_T(KC_ENT):
            // Disable tap-hold repeat
            return 0;
    }
    return QUICK_TAP_TERM;
}
#endif // QUICK_TAP_TERM_PER_KEY

#ifdef AUTO_SHIFT_TIMEOUT_PER_KEY
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SLASH:
            if (IS_LAYER_ON(_LOWER)) return 2 * get_generic_autoshift_timeout();
    }
    return get_generic_autoshift_timeout();
}
#endif // AUTO_SHIFT_TIMEOUT_PER_KEY

#ifdef TAP_DANCE_ENABLE
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state) {
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
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {}
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
    switch (tap_hold_keycode) {
        case HYPR_T(KC_GRV):
        case MEH_T(KC_MINS):
            return true;
        // Home Row Modifiers
        case RGUI_T(KC_J):
            switch (other_keycode) {
                case LSFT_T(KC_SPC):
                    return true;
            }
            break;
        case RCTL_T(KC_SCLN):
            switch (other_keycode) {
                case KC_Y:
                case KC_U:
                case KC_I:
                case KC_O:
                    return true;
            }
            break;
        case LALT_T(KC_S):
            switch (other_keycode) {
                case KC_ENT:
                case KC_TAB:
                    return true;
            }
            break;
        case LSFT_T(KC_D):
            switch (other_keycode) {
                case LWR:
                case KC_TAB:
                case KC_ENT:
                    return true;
            }
            break;
        case LGUI_T(KC_F):
            switch (other_keycode) {
                case KC_TAB:
                    return true;
            }
            break;
        // Thumb Mod-Tap keys
        case LWR:
            return true;
        case RSE_T(KC_ENT):
            return true;
    }

    // The default choice is to return true if the keys are on opposite hands
    return achordion_opposite_hands(tap_hold_record, other_record);
}


// See link above for per-keycode use of achordion_timeout()
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LSFT_T(KC_SPACE):
            // Bypass achordion
            return 0;
        case LT(_QWERTY_NO_MODS, KC_TAB):
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
        case KC_0:
        case KC_9:
            // I already have left/right paren keys in LOWER layer, and I tend
            // to type 0 slowly and mistakenly trigger auto shift
            return false;
    }
    return get_default_auto_shifted_key(keycode, record);
}

// The default function, overrode to re-plumb the order default cases are
// checked. This way I can override KC_0 and KC_9 while leaving
// AUTO_SHIFT_NUMERIC enabled
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    return get_custom_auto_shifted_key(keycode, record);
}

/*
  Repeat Key
  https://docs.qmk.fm/#/feature_repeat_key
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


    switch (keycode) {
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
                os_variant_t host_os = detected_host_os();

                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(LGUI(KC_C));
                } else {
                    tap_code16(LCTL(KC_C));
                }
            }
            return false;

        case UKC_OS_PASTE:
            if (record->event.pressed) {
                os_variant_t host_os = detected_host_os();

                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(LGUI(KC_V));
                } else {
                    tap_code16(LCTL(KC_V));
                }
            }
            return false;

        case UKC_OS_PREV_TAB:
            if (record->event.pressed) {
                os_variant_t host_os = detected_host_os();

                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(SGUI(KC_LBRC));
                } else {
                    tap_code16(LCTL(KC_PGUP));
                }
            }
            return false;

        case UKC_OS_NEXT_TAB:
            if (record->event.pressed) {
                os_variant_t host_os = detected_host_os();

                if (host_os == OS_MACOS || host_os == OS_IOS) {
                    tap_code16(SGUI(KC_RBRC));
                } else {
                    tap_code16(LCTL(KC_PGDN));
                }
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
