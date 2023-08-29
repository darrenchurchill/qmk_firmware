#include QMK_KEYBOARD_H
#include "darrenchurchill.h"
#include "achordion.h"


__attribute__ ((weak))
void keyboard_post_init_keymap(void) {
    return;
}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
}

/*
  Auto Shift
*/
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case RSFT_T(KC_COMM):
        case RALT_T(KC_DOT):
        case RCTL_T(KC_SLSH):
        case LCTL_T(KC_GRV):
        case KC_EXLM:
        case KC_AT:
        case KC_HASH:
        case KC_DLR:
        case KC_PERC:
        case KC_CIRC:
        case KC_AMPR:
        case KC_ASTR:
        case KC_LPRN:
        case KC_RPRN:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_EXLM:
            register_code16((!shifted) ? KC_EXLM : KC_1);
            break;
        case KC_AT:
            register_code16((!shifted) ? KC_AT : KC_2);
            break;
        case KC_HASH:
            register_code16((!shifted) ? KC_HASH : KC_3);
            break;
        case KC_DLR:
            register_code16((!shifted) ? KC_DLR : KC_4);
            break;
        case KC_PERC:
            register_code16((!shifted) ? KC_PERC : KC_5);
            break;
        case KC_CIRC:
            register_code16((!shifted) ? KC_CIRC : KC_6);
            break;
        case KC_AMPR:
            register_code16((!shifted) ? KC_AMPR : KC_7);
            break;
        case KC_ASTR:
            register_code16((!shifted) ? KC_ASTR : KC_8);
            break;
        case KC_LPRN:
            register_code16((!shifted) ? KC_LPRN : KC_9);
            break;
        case KC_RPRN:
            register_code16((!shifted) ? KC_RPRN : KC_0);
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
    switch(keycode) {
        case KC_EXLM:
            unregister_code16((!shifted) ? KC_EXLM : KC_1);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_C):
        case RSFT_T(KC_COMM):
            return g_tapping_term - 30;
        default:
            return g_tapping_term;
    }
}
#endif // TAPPING_TERM_PER_KEY

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

uint8_t dance_step(tap_dance_state_t *state);

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

void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

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


// See https://getreuer.info/posts/keyboards/achordion/
// For per-keycode use of achordion_timeout()
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    // Default to default dynamic tapping term + nominal ms
    // Reducing the default achordion_timeout makes same-hand tap-hold combos
    // like LGUI_T(KC_M) + KC_SPACE on MacOS faster
    // I think this is the best option for this particular key combination,
    // because you somtimes also roll through M onto Space at the end of a word
    return g_tapping_term + 50;
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // https://getreuer.info/posts/keyboards/achordion/
    if (!process_achordion(keycode, record)) { return false; }

    return process_record_keymap(keycode, record);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
    achordion_task();

    matrix_scan_keymap();
}
