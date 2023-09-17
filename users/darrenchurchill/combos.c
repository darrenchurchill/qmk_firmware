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
    DF_TAB,
    FG_ESC,
    CVB_OS_COPY,
    VB_OS_PASTE,
    DK_CW_TOGG,
};


const uint16_t PROGMEM combo_df[] = { LSFT_T(KC_D), LGUI_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_fg[] = { LGUI_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM combo_jk[] = { RGUI_T(KC_J), LSFT_T(KC_K), COMBO_END};

const uint16_t PROGMEM combo_cvb[] = { KC_C, KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_vb[] = { KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM combo_dk[] = { LSFT_T(KC_D), LSFT_T(KC_K), COMBO_END};


combo_t key_combos[] = {
    [DF_TAB] = COMBO(combo_df, KC_TAB),
    [FG_ESC] = COMBO(combo_fg, KC_ESC),
    [JK_ENT] = COMBO(combo_jk, KC_ENT),
    [CVB_OS_COPY] = COMBO(combo_cvb, UKC_OS_COPY),
    [VB_OS_PASTE] = COMBO(combo_vb, UKC_OS_PASTE),
    [DK_CW_TOGG] = COMBO(combo_dk, CW_TOGG),
};


// This function returns true if a given combo should only fire when tapped
// (vs held)
// https://docs.qmk.fm/#/feature_combo?id=per-combo-timing-holding-tapping-and-key-press-order
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
      case DF_TAB:
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
