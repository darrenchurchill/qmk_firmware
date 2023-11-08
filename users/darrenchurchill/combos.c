/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

// NOTE: Combos are defined to be evaluated from the _QWERTY layer
// See config.h COMBO_ONLY_FROM_LAYER

// Uncomment this enum and add a constant element if you need to reference a
// combo's key_combos[] index elsewhere.
enum required_idx_combos {
    COMBO_BSPC_LH,
    COMBO_DEL_LH,
    COMBO_BSPC_RH,
    COMBO_DEL_RH,
};


// Left Hand
// Horizontal combos
// Top Row
const uint16_t PROGMEM combo_qwer[] = { QKC_Q, QKC_W, QKC_E, QKC_R, COMBO_END };
const uint16_t PROGMEM combo_wer[] = { QKC_W, QKC_E, QKC_R, COMBO_END };
const uint16_t PROGMEM combo_rt[] = { QKC_R, QKC_T, COMBO_END };
// Home Row
const uint16_t PROGMEM combo_asdf[] = { QKC_A, QKC_S, QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_sd[] = { QKC_S, QKC_D, COMBO_END };
const uint16_t PROGMEM combo_sdf[] = { QKC_S, QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_df[] = { QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_dfg[] = { QKC_D, QKC_F, QKC_G, COMBO_END };
const uint16_t PROGMEM combo_fg[] = { QKC_F, QKC_G, COMBO_END };
// Bottom Row
const uint16_t PROGMEM combo_zxcv[] = { QKC_Z, QKC_X, QKC_C, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_xc[] = { QKC_X, QKC_C, COMBO_END };
const uint16_t PROGMEM combo_cv[] = { QKC_C, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_cvb[] = { QKC_C, QKC_V, QKC_B, COMBO_END };
const uint16_t PROGMEM combo_vb[] = { QKC_V, QKC_B, COMBO_END };

// Vertical combos
// Top + Home Rows
const uint16_t PROGMEM combo_ws[] = { QKC_W, QKC_S, COMBO_END };
const uint16_t PROGMEM combo_ed[] = { QKC_E, QKC_D, COMBO_END };
const uint16_t PROGMEM combo_rf[] = { QKC_R, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_tg[] = { QKC_T, QKC_G, COMBO_END };
// Home + Bottom Rows
const uint16_t PROGMEM combo_dc[] = { QKC_D, QKC_C, COMBO_END };
const uint16_t PROGMEM combo_fv[] = { QKC_F, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_gb[] = { QKC_G, QKC_B, COMBO_END };


// Right Hand
// Horizontal combos
// Top Row
const uint16_t PROGMEM combo_yu[] = { QKC_Y, QKC_U, COMBO_END };
const uint16_t PROGMEM combo_uio[] = { QKC_U, QKC_I, QKC_O, COMBO_END };
// Home Row
const uint16_t PROGMEM combo_hj[] = { QKC_H, QKC_J, COMBO_END };
const uint16_t PROGMEM combo_hjk[] = { QKC_H, QKC_J, QKC_K, COMBO_END };
const uint16_t PROGMEM combo_jk[] = { QKC_J, QKC_K, COMBO_END };
const uint16_t PROGMEM combo_jkl[] = { QKC_J, QKC_K, QKC_L, COMBO_END };
const uint16_t PROGMEM combo_kl[] = { QKC_K, QKC_L, COMBO_END };
// Bottom Row
const uint16_t PROGMEM combo_nm[] = { QKC_N, QKC_M, COMBO_END };
const uint16_t PROGMEM combo_nm_comma[] = { QKC_N, QKC_M, QKC_COM, COMBO_END };
const uint16_t PROGMEM combo_m_comma[] = { QKC_M, QKC_COM, COMBO_END };
const uint16_t PROGMEM combo_m_comma_dot[] = { QKC_M, QKC_COM, QKC_DOT, COMBO_END };
const uint16_t PROGMEM combo_comma_dot[] = { QKC_COM, QKC_DOT, COMBO_END };

// Vertical combos
// Top + Home Rows
const uint16_t PROGMEM combo_yh[] = { QKC_Y, QKC_H, COMBO_END };
const uint16_t PROGMEM combo_uj[] = { QKC_U, QKC_J, COMBO_END };
const uint16_t PROGMEM combo_ik[] = { QKC_I, QKC_K, COMBO_END };
const uint16_t PROGMEM combo_ol[] = { QKC_O, QKC_L, COMBO_END };

// Home + Bottom Rows
const uint16_t PROGMEM combo_hn[] = { QKC_H, QKC_N, COMBO_END };
const uint16_t PROGMEM combo_jm[] = { QKC_J, QKC_M, COMBO_END };
const uint16_t PROGMEM combo_kcomma[] = { QKC_K, QKC_COM, COMBO_END };


// Both Hands
const uint16_t PROGMEM combo_dk[] = { QKC_D, QKC_K, COMBO_END };
#ifdef RGB_MATRIX_ENABLE
const uint16_t PROGMEM combo_lyr[] = { QKC_L, QKC_Y, QKC_R, COMBO_END };
#endif

/*
  Combo -> keycode definitions

  A few justifications for my placements:

  Backspace/delete:
    - left hand & right hand combos mirror each other.
    - They are convenient to access when the thumb is occupied holding down a
      layer key.

  Cut/copy/paste:
    - These are all 4-key combos arranged vertically on the left hand, so
      they're usable when the mouse is in the right hand.

  Less-than/greater-than:
    - Vertical combos mirrored vertically on left hand.
    - This is so "<=", or "double left arrow", mirrors "=>" on the right hand.

  Minus/underscore:
    - These are used as separators in variable names, depending on language, so
      I hope they'll be easy to type once and return to typing letters.
        - I've also tried them on SD/KL, CV/MComma, and KL/CommaDot (all RHand)
        - Hopefully the benefits of other combos makes their placement
          acceptable.

  Colon/semicolon:
    - Semicolon is Vim repeat motion in same direction. Comma is Vim repeat
      motion in opposite direction.
        - The overlap between combo & regular key is convenient.
    - Both symbols are often followed by a new line, and I think both of these
      combos are easy to follow with jk -> KC_ENT.
    - Colon/semicolon shifted/un-shifted combo keycodes overlap.

  Remaining symbols:
    - The remaining combos are arranged in mirrored pairs, when applicable, left
      hand & right hand, either shifted/unshifted, or "directional", as in
      left/right arrow.
*/

combo_t key_combos[] = {
    // Required indexed combos:
    [COMBO_BSPC_LH] = COMBO(combo_tg, KC_BSPC),
    [COMBO_DEL_LH] = COMBO(combo_rt, KC_DEL),
    [COMBO_BSPC_RH] = COMBO(combo_yh, KC_BSPC),
    [COMBO_DEL_RH] = COMBO(combo_yu, KC_DEL),


    // Left Hand
    // Horizontal combos
    // Top Row
    COMBO(combo_qwer, UKC_OS_CUT),
    COMBO(combo_wer, XXXXXXX),
    // Home Row
    COMBO(combo_asdf, UKC_OS_COPY),
    COMBO(combo_sd, KC_QUOT),
    COMBO(combo_sdf, XXXXXXX), // triple single quote?
    COMBO(combo_df, KC_ESC),
    COMBO(combo_dfg, UKC_DB_MINS),
    COMBO(combo_fg, KC_MINS),
    // Bottom Row
    COMBO(combo_zxcv, UKC_OS_PASTE),
    COMBO(combo_xc, KC_SLASH),
    COMBO(combo_cv, KC_GRV),
    COMBO(combo_cvb, XXXXXXX), // triple backtick?
    COMBO(combo_vb, XXXXXXX),

    // Vertical combos
    // Top + Home Rows
    COMBO(combo_ws, LLOCK),
    COMBO(combo_ed, UKC_LARRW), // "<-"
    COMBO(combo_rf, UKC_LEQ), // "<="
    // Home + Bottom Rows
    COMBO(combo_dc, XXXXXXX),
    COMBO(combo_fv, UKC_GEQ), // ">="
    COMBO(combo_gb, UKC_LEAD),


    // Right Hand
    // Horizontal combos
    // Top Row
    COMBO(combo_uio, XXXXXXX),
    // Home Row
    COMBO(combo_hj, KC_UNDS),
    COMBO(combo_hjk, UKC_DB_UNDS),
    COMBO(combo_jk, KC_ENT),
    COMBO(combo_jkl, XXXXXXX), // triple double quote?
    COMBO(combo_kl, KC_DQUO),
    // Bottom Row
    COMBO(combo_nm, XXXXXXX),
    COMBO(combo_nm_comma, XXXXXXX),
    COMBO(combo_m_comma, KC_SEMICOLON),
    COMBO(combo_m_comma_dot, KC_COLON),
    COMBO(combo_comma_dot, KC_QUES),

    // Vertical combos
    // Top + Home Rows
    COMBO(combo_uj, UKC_DBRARRW), // "=>"
    COMBO(combo_ik, UKC_RARRW), // "->"
    COMBO(combo_ol, LLOCK), // "LO" for "Lock"
    // Home + Bottom Rows
    COMBO(combo_hn, UKC_LEAD),
    COMBO(combo_jm, KC_CIRCUMFLEX), // "^", for vim
    COMBO(combo_kcomma, KC_DOLLAR), // "$", for vim


    // Both Hands
    COMBO(combo_dk, UKC_CW_TOGG),
#ifdef RGB_MATRIX_ENABLE
    COMBO(combo_lyr, TG(_LAYERS)),
#endif
};


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
