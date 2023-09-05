/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

// Most combo #defines need to be in config.h, but this one can live here, and
// lets you use the _QWERTY macro definition
#define COMBO_ONLY_FROM_LAYER _QWERTY


enum combos {
    LOWER_SPACE_REPEAT,
    LOWER_RAISE_ALT_REPEAT,
    DF_ESC, // qwerty start
    FG_TAB,
    HJ_LSFT_TAB,
    JK_ENT,
    XC_RAISE,
    CVB_OS_COPY,
    VB_OS_PASTE,
    DK_CW_TOGG, // qwerty end
    ST_ESC, // colemak start
    TG_TAB,
    MN_LSFT_TAB,
    NE_ENT,
    CDV_OS_COPY,
    DV_OS_PASTE,
    SE_CW_TOGG, // colemak end
};

const uint16_t PROGMEM combo_lower_space[] = { LOWER, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_lower_raise[] = { LOWER, RAISE, COMBO_END};

// QWERTY combos
const uint16_t PROGMEM combo_df[] = { LSFT_T(KC_D), LGUI_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_fg[] = { LGUI_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM combo_hj[] = { KC_H, RGUI_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo_jk[] = { RGUI_T(KC_J), LSFT_T(KC_K), COMBO_END};

const uint16_t PROGMEM combo_xc[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cvb[] = { KC_C, KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_vb[] = { KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM combo_dk[] = { LSFT_T(KC_D), LSFT_T(KC_K), COMBO_END};

// Colemak DH combos
const uint16_t PROGMEM combo_st[] = { LSFT_T(KC_S), LGUI_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_tg[] = { LGUI_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM combo_mn[] = { KC_M, RGUI_T(KC_N), COMBO_END};
const uint16_t PROGMEM combo_ne[] = { RGUI_T(KC_N), LSFT_T(KC_E), COMBO_END};

// xc: same as qwerty above
const uint16_t PROGMEM combo_cdv[] = { KC_C, KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM combo_dv[] = { KC_D, KC_V, COMBO_END};

const uint16_t PROGMEM combo_se[] = { LSFT_T(KC_S), LSFT_T(KC_E), COMBO_END};


combo_t key_combos[] = {
    [LOWER_SPACE_REPEAT] = COMBO(combo_lower_space, QK_REPEAT_KEY),
    [LOWER_RAISE_ALT_REPEAT] = COMBO(combo_lower_raise, QK_ALT_REPEAT_KEY),
    [DF_ESC] = COMBO(combo_df, KC_ESC), // qwerty
    [FG_TAB] = COMBO(combo_fg, KC_TAB),
    [HJ_LSFT_TAB] = COMBO(combo_hj, LSFT(KC_TAB)),
    [JK_ENT] = COMBO(combo_jk, KC_ENT),
    [XC_RAISE] = COMBO(combo_xc, RAISE), // this one is both
    [CVB_OS_COPY] = COMBO(combo_cvb, UKC_OS_COPY),
    [VB_OS_PASTE] = COMBO(combo_vb, UKC_OS_PASTE),
    [DK_CW_TOGG] = COMBO(combo_dk, CW_TOGG),
    [ST_ESC] = COMBO(combo_st, KC_ESC), // colemak
    [TG_TAB] = COMBO(combo_tg, KC_TAB),
    [MN_LSFT_TAB] = COMBO(combo_mn, LSFT(KC_TAB)),
    [NE_ENT] = COMBO(combo_ne, KC_ENT),
    [CDV_OS_COPY] = COMBO(combo_cdv, UKC_OS_COPY),
    [DV_OS_PASTE] = COMBO(combo_dv, UKC_OS_PASTE),
    [SE_CW_TOGG] = COMBO(combo_se, CW_TOGG),
};


// This function returns true if a given combo should only fire when tapped
// (vs held)
// https://docs.qmk.fm/#/feature_combo?id=per-combo-timing-holding-tapping-and-key-press-order
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
      case FG_TAB:
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
