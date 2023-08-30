/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

// Most combo #defines need to be in config.h, but this one can live here, and
// lets you use the _BASE macro definition
#define COMBO_ONLY_FROM_LAYER _BASE


enum combos {
    LOWER_SPACE_REPEAT,
    LOWER_RAISE_ALT_REPEAT,
    DF_ESC,
    FG_TAB,
    HJ_LSFT_TAB,
    JK_ENT,
    CVB_OS_COPY,
    VB_OS_PASTE,
    DK_CW_TOGG,
};

const uint16_t PROGMEM combo_lower_space[] = { LOWER, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_lower_raise[] = { LOWER, RAISE, COMBO_END};

const uint16_t PROGMEM combo_df[] = { LSFT_T(KC_D), LGUI_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_fg[] = { LGUI_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM combo_hj[] = { KC_H, RGUI_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo_jk[] = { RGUI_T(KC_J), RSFT_T(KC_K), COMBO_END};

const uint16_t PROGMEM combo_cvb[] = { KC_C, KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_vb[] = { KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM combo_dk[] = { LSFT_T(KC_D), RSFT_T(KC_K), COMBO_END};

combo_t key_combos[] = {
    [LOWER_SPACE_REPEAT] = COMBO(combo_lower_space, QK_REPEAT_KEY),
    [LOWER_RAISE_ALT_REPEAT] = COMBO(combo_lower_raise, QK_ALT_REPEAT_KEY),
    [DF_ESC] = COMBO(combo_df, KC_ESC),
    [FG_TAB] = COMBO(combo_fg, KC_TAB),
    [HJ_LSFT_TAB] = COMBO(combo_hj, LSFT(KC_TAB)),
    [JK_ENT] = COMBO(combo_jk, KC_ENT),
    [CVB_OS_COPY] = COMBO(combo_cvb, UKC_OS_COPY),
    [VB_OS_PASTE] = COMBO(combo_vb, UKC_OS_PASTE),
    [DK_CW_TOGG] = COMBO(combo_dk, CW_TOGG)
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
