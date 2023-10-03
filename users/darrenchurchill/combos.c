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
// enum required_idx_combos {};


// Left Hand
// Top Row
const uint16_t PROGMEM combo_qwer[] = { QKC_Q, QKC_W, QKC_E, QKC_R, COMBO_END };
const uint16_t PROGMEM combo_qwert[] = { QKC_Q, QKC_W, QKC_E, QKC_R, QKC_T, COMBO_END };
// Home Row
const uint16_t PROGMEM combo_sd[] = { QKC_S, QKC_D, COMBO_END };
const uint16_t PROGMEM combo_sdf[] = { QKC_S, QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_df[] = { QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_fg[] = { QKC_F, QKC_G, COMBO_END };
// Bottom Row
const uint16_t PROGMEM combo_cv[] = { QKC_C, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_cvb[] = { QKC_C, QKC_V, QKC_B, COMBO_END };
const uint16_t PROGMEM combo_vb[] = { QKC_V, QKC_B, COMBO_END };

// Right Hand
// Home Row
const uint16_t PROGMEM combo_hj[] = { QKC_H, QKC_J, COMBO_END };
const uint16_t PROGMEM combo_jk[] = { QKC_J, QKC_K, COMBO_END };
const uint16_t PROGMEM combo_jkl[] = { QKC_J, QKC_K, QKC_L, COMBO_END };
const uint16_t PROGMEM combo_kl[] = { QKC_K, QKC_L, COMBO_END };
// Bottom Row
const uint16_t PROGMEM combo_m_comma[] = { QKC_M, QKC_COM, COMBO_END };
const uint16_t PROGMEM combo_comma_dot[] = { QKC_COM, QKC_DOT, COMBO_END };

// Both Hands
const uint16_t PROGMEM combo_dk[] = { QKC_D, QKC_K, COMBO_END };
#ifdef RGB_MATRIX_ENABLE
const uint16_t PROGMEM combo_lyr[] = { QKC_L, QKC_Y, QKC_R, COMBO_END };
#endif


combo_t key_combos[] = {
    COMBO(combo_qwer, QK_REBOOT),
    COMBO(combo_qwert, QK_BOOTLOADER),
    COMBO(combo_sd, KC_UNDS),
    COMBO(combo_sdf, UKC_DB_UNDS),
    COMBO(combo_df, KC_QUOT),
    COMBO(combo_fg, KC_GRV),
    COMBO(combo_cv, KC_ESC),
    COMBO(combo_cvb, UKC_OS_COPY),
    COMBO(combo_vb, UKC_OS_PASTE),
    COMBO(combo_hj, QK_LEAD),
    COMBO(combo_jk, KC_DQUO),
    COMBO(combo_jkl, UKC_DB_MINS),
    COMBO(combo_kl, KC_MINS),
    COMBO(combo_m_comma, KC_ENT),
    COMBO(combo_comma_dot, UKC_ARRW),
    COMBO(combo_dk, UKC_CW_TOGG),
#ifdef RGB_MATRIX_ENABLE
    COMBO(combo_lyr, TG(_LAYERS)),
#endif
};


// This function returns true if a given combo should only fire when tapped
// (vs held)
// https://docs.qmk.fm/#/feature_combo?id=per-combo-timing-holding-tapping-and-key-press-order
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
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
