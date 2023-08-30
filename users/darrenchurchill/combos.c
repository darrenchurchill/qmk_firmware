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
    COMBO(combo_lower_space, QK_REPEAT_KEY),
    COMBO(combo_lower_raise, QK_ALT_REPEAT_KEY),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_fg, KC_TAB),
    COMBO(combo_hj, LSFT(KC_TAB)),
    COMBO(combo_jk, KC_ENT),
    COMBO(combo_cvb, UKC_OS_COPY),
    COMBO(combo_vb, UKC_OS_PASTE),
    COMBO(combo_dk, CW_TOGG)
};
