/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

// NOTE: Combos are defined to be evaluated from the _QWERTY layer
// See config.h COMBO_ONLY_FROM_LAYER

enum combos {
    JK_ENT,
    COMMA_DOT_SG_ARRW,
    M_COMMA_UNDS,
    DF_ESC,
    CV_TAB,
    CVB_OS_COPY,
    VB_OS_PASTE,
    DK_CW_TOGG,
#ifdef RGB_MATRIX_ENABLE
    LYR_TG_LAYER,
#endif
    QWER_REBOOT,
    QWERT_BOOTLOADER
};


const uint16_t PROGMEM combo_df[] = { QKC_D, QKC_F, COMBO_END };
const uint16_t PROGMEM combo_jk[] = { QKC_J, QKC_K, COMBO_END };

const uint16_t PROGMEM combo_cv[] = { QKC_C, QKC_V, COMBO_END };
const uint16_t PROGMEM combo_cvb[] = { QKC_C, QKC_V, QKC_B, COMBO_END };
const uint16_t PROGMEM combo_vb[] = { QKC_V, QKC_B, COMBO_END };

const uint16_t PROGMEM combo_comma_dot[] = { QKC_COM, QKC_DOT, COMBO_END };
const uint16_t PROGMEM combo_m_comma[] = { QKC_M, QKC_COM, COMBO_END };

const uint16_t PROGMEM combo_dk[] = { QKC_D, QKC_K, COMBO_END };
#ifdef RGB_MATRIX_ENABLE
const uint16_t PROGMEM combo_lyr[] = { QKC_L, QKC_Y, QKC_R, COMBO_END };
#endif
const uint16_t PROGMEM combo_qwer[] = { QKC_Q, QKC_W, QKC_E, QKC_R, COMBO_END };
const uint16_t PROGMEM combo_qwert[] = { QKC_Q, QKC_W, QKC_E, QKC_R, QKC_T, COMBO_END };


combo_t key_combos[] = {
    [DF_ESC] = COMBO(combo_df, KC_ESC),
    [JK_ENT] = COMBO(combo_jk, KC_ENT),
    [CV_TAB] = COMBO(combo_cv, KC_TAB),
    [CVB_OS_COPY] = COMBO(combo_cvb, UKC_OS_COPY),
    [VB_OS_PASTE] = COMBO(combo_vb, UKC_OS_PASTE),
    [COMMA_DOT_SG_ARRW] = COMBO(combo_comma_dot, UKC_ARRW),
    [M_COMMA_UNDS] = COMBO(combo_m_comma, KC_UNDS),
    [DK_CW_TOGG] = COMBO(combo_dk, CW_TOGG),
#ifdef RGB_MATRIX_ENABLE
    [LYR_TG_LAYER] = COMBO(combo_lyr, TG(_LAYERS)),
#endif
    [QWER_REBOOT] = COMBO(combo_qwer, QK_REBOOT),
    [QWERT_BOOTLOADER] = COMBO(combo_qwert, QK_BOOTLOADER),
};


// This function returns true if a given combo should only fire when tapped
// (vs held)
// https://docs.qmk.fm/#/feature_combo?id=per-combo-timing-holding-tapping-and-key-press-order
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
      case CV_TAB:
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
