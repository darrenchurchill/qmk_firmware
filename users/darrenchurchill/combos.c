/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

// TODO: change these to evaluate from _COLEMAK instead
// NOTE: Combos are defined to be evaluated from the _QWERTY layer
// See config.h COMBO_ONLY_FROM_LAYER

// Uncomment this enum and add a constant element if you need to reference a
// combo's key_combos[] index elsewhere.
enum required_idx_combos {
    COMBO_BSPC_LH,
    COMBO_DEL_LH,
    COMBO_BSPC_RH,
    COMBO_DEL_RH,
    COMBO_DF,
    COMBO_JK,
    COMBO_JKL,
    COMBO_KL,
    COMBO_SL,
    COMBO_DK,
    COMBO_CCOMMA,
};


// Left Hand
// Horizontal combos
// Top Row
const uint16_t PROGMEM combo_qwer[] = { QKC_Q, QKC_W, QKC_E, QKC_R, COMBO_END };
const uint16_t PROGMEM combo_wer[] = { QKC_W, QKC_E, QKC_R, COMBO_END };
const uint16_t PROGMEM combo_rt[] = { QKC_R, QKC_T, COMBO_END };
// Home Row
const uint16_t PROGMEM combo_asdf[] = { QKC_A, QKC_S, QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_df[] = { QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_fg[] = { QKC_F, QKC_G, COMBO_END };
// Bottom Row
const uint16_t PROGMEM combo_zxcv[] = { QKC_Z, QKC_X, QKC_C, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_xcv[] = { QKC_X, QKC_C, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_cv[] = { QKC_C, QKC_V, COMBO_END };

// Vertical combos
// Top + Home Rows
const uint16_t PROGMEM combo_ed[] = { QKC_E, QKC_D, COMBO_END };
const uint16_t PROGMEM combo_rf[] = { QKC_R, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_tg[] = { QKC_T, QKC_G, COMBO_END };
// Home + Bottom Rows
const uint16_t PROGMEM combo_fv[] = { QKC_F, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_gb[] = { QKC_G, QKC_B, COMBO_END };


// Right Hand
// Horizontal combos
// Top Row
const uint16_t PROGMEM combo_yu[] = { QKC_Y, QKC_U, COMBO_END };
const uint16_t PROGMEM combo_uio[] = { QKC_U, QKC_I, QKC_O, COMBO_END };
// Home Row
const uint16_t PROGMEM combo_hj[] = { QKC_H, QKC_J, COMBO_END };
const uint16_t PROGMEM combo_jk[] = { QKC_J, QKC_K, COMBO_END };
const uint16_t PROGMEM combo_jkl[] = { QKC_J, QKC_K, QKC_L, COMBO_END };
const uint16_t PROGMEM combo_kl[] = { QKC_K, QKC_L, COMBO_END };
// Bottom Row
const uint16_t PROGMEM combo_m_comma[] = { QKC_M, QKC_COM, COMBO_END };
const uint16_t PROGMEM combo_m_comma_dot[] = { QKC_M, QKC_COM, QKC_DOT, COMBO_END };
const uint16_t PROGMEM combo_comma_dot[] = { QKC_COM, QKC_DOT, COMBO_END };

// Vertical combos
// Top + Home Rows
const uint16_t PROGMEM combo_yh[] = { QKC_Y, QKC_H, COMBO_END };
const uint16_t PROGMEM combo_uj[] = { QKC_U, QKC_J, COMBO_END };
const uint16_t PROGMEM combo_ik[] = { QKC_I, QKC_K, COMBO_END };

// Home + Bottom Rows
const uint16_t PROGMEM combo_hn[] = { QKC_H, QKC_N, COMBO_END };
const uint16_t PROGMEM combo_jm[] = { QKC_J, QKC_M, COMBO_END };
const uint16_t PROGMEM combo_kcomma[] = { QKC_K, QKC_COM, COMBO_END };


// Both Hands
const uint16_t PROGMEM combo_sl[] = { QKC_S, QKC_L, COMBO_END };
const uint16_t PROGMEM combo_dk[] = { QKC_D, QKC_K, COMBO_END };
const uint16_t PROGMEM combo_ccomma[] = { QKC_C, QKC_COM, COMBO_END };
#ifdef RGB_MATRIX_ENABLE
const uint16_t PROGMEM combo_lyr[] = { QKC_L, QKC_Y, QKC_R, COMBO_END };
#endif


combo_t key_combos[] = {
    // Required indexed combos:
    [COMBO_BSPC_LH] = COMBO(combo_tg, KC_BSPC),
    [COMBO_DEL_LH] = COMBO(combo_rt, KC_DEL),
    [COMBO_BSPC_RH] = COMBO(combo_yh, KC_BSPC),
    [COMBO_DEL_RH] = COMBO(combo_yu, KC_DEL),
    [COMBO_DF] = COMBO(combo_df, RSE_T(KC_TAB)),
    [COMBO_JK] = COMBO(combo_jk, KC_ENT),
    [COMBO_JKL] = COMBO(combo_jkl, UKC_DB_UNDS),
    [COMBO_KL] = COMBO(combo_kl, KC_UNDS),
    [COMBO_SL] = COMBO(combo_sl, TG(_NUMPAD)),
    [COMBO_DK] = COMBO(combo_dk, TG(_LOWER)),
    [COMBO_CCOMMA] = COMBO(combo_ccomma, UKC_CW_TOGG),


    // Left Hand
    // Horizontal combos
    // Top Row
    COMBO(combo_qwer, UKC_OS_CUT),
    COMBO(combo_wer, LLOCK),
    // Home Row
    COMBO(combo_asdf, UKC_OS_COPY),
    COMBO(combo_fg, KC_QUES),
    // Bottom Row
    COMBO(combo_zxcv, UKC_OS_PASTE),
    COMBO(combo_xcv, UKC_TRP_GRAVE),
    COMBO(combo_cv, KC_GRAVE),

    // Vertical combos
    // Top + Home Rows
    COMBO(combo_ed, UKC_LARRW), // "<-"
    COMBO(combo_rf, UKC_LEQ), // "<="
    // Home + Bottom Rows
    COMBO(combo_fv, UKC_GEQ), // ">="
    COMBO(combo_gb, UKC_LEAD),


    // Right Hand
    // Horizontal combos
    // Top Row
    COMBO(combo_uio, LLOCK),
    // Home Row
    COMBO(combo_hj, KC_SLASH),
    // Bottom Row
    COMBO(combo_m_comma, KC_DQUO),
    COMBO(combo_m_comma_dot, UKC_DB_MINS),
    COMBO(combo_comma_dot, KC_MINS),

    // Vertical combos
    // Top + Home Rows
    COMBO(combo_uj, UKC_DBRARRW), // "=>"
    COMBO(combo_ik, UKC_RARRW), // "->"
    // Home + Bottom Rows
    COMBO(combo_hn, UKC_LEAD),
    COMBO(combo_jm, KC_CIRCUMFLEX), // "^", for vim
    COMBO(combo_kcomma, KC_DOLLAR), // "$", for vim


    // Both Hands
#ifdef RGB_MATRIX_ENABLE
    COMBO(combo_lyr, TG(_LAYERS)),
#endif
};


// https://docs.qmk.fm/#/feature_combo?id=per-combo-timing-holding-tapping-and-key-press-order
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_DF:
        case COMBO_JK:
        case COMBO_JKL:
        case COMBO_KL:
        case COMBO_SL:
        case COMBO_DK:
        case COMBO_CCOMMA:
            return COMBO_TERM_FAST;
    }

    return COMBO_TERM;
}


// This function returns true if a given combo should only fire when tapped
// (vs held)
// https://docs.qmk.fm/#/feature_combo?id=per-combo-timing-holding-tapping-and-key-press-order
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_BSPC_LH:
        case COMBO_DEL_LH:
        case COMBO_BSPC_RH:
        case COMBO_DEL_RH:
            return false;
    }

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in
    // its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }

    // Default: allow combo to fire when held
    return false;
}
