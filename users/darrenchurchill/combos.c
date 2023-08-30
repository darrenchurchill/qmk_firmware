/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

#define COMBO_ONLY_FROM_LAYER _BASE


// left hand
// home row
const uint16_t PROGMEM combo_as[] = { KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_sd[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_df[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_fg[] = { KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM combo_asd[] = { KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_adf[] = { KC_A, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_sdf[] = { KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_dfg[] = { KC_D, KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM combo_asdf[] = { KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_sdfg[] = { KC_S, KC_D, KC_F, KC_G, COMBO_END};

// 1 below home row
const uint16_t PROGMEM combo_xc[] = { LALT_T(KC_X), LSFT_T(KC_C), COMBO_END};
const uint16_t PROGMEM combo_cv[] = { LSFT_T(KC_C), LGUI_T(KC_V), COMBO_END};

const uint16_t PROGMEM combo_cvb[] = { LSFT_T(KC_C), LGUI_T(KC_V), KC_B, COMBO_END};
const uint16_t PROGMEM combo_vb[] = { LGUI_T(KC_V), KC_B, COMBO_END};

const uint16_t PROGMEM combo_ccomma[] = { LSFT_T(KC_C), RSFT_T(KC_COMM), COMBO_END};

// right hand
// home row
const uint16_t PROGMEM combo_hj[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_jk[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_lscln[] = { KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM combo_hjk[] = { KC_H, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_jkl[] = { KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_jkscln[] = { KC_J, KC_K, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_klscln[] = { KC_K, KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM combo_hjkl[] = { KC_H, KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_jklscln[] = { KC_J, KC_K, KC_L, KC_SCLN, COMBO_END};

// 1 below home row
const uint16_t PROGMEM combo_mcomma[] = { RGUI_T(KC_M), RSFT_T(KC_COMMA), COMBO_END};

// two hand
// home row
const uint16_t PROGMEM combo_dfjk[] = { KC_D, KC_F, KC_J, KC_K, COMBO_END};

// thumb keys
const uint16_t PROGMEM combo_lower_space[] = { LOWER, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_lower_raise[] = { LOWER, RAISE, COMBO_END};


combo_t key_combos[] = {
    // left hand
    COMBO(combo_as, KC_LCTL),
    COMBO(combo_sd, KC_LALT),
    COMBO(combo_df, KC_LSFT),
    COMBO(combo_fg, KC_LGUI),

    COMBO(combo_asd, LCTL(KC_LALT)),
    COMBO(combo_adf, LCTL(KC_LSFT)),
    COMBO(combo_sdf, LALT(KC_LSFT)),
    COMBO(combo_dfg, LSFT(KC_LGUI)),

    COMBO(combo_asdf, LCTL(LALT(KC_LSFT))),
    COMBO(combo_sdfg, LALT(LSFT(KC_LGUI))),

    COMBO(combo_xc, KC_TAB),
    COMBO(combo_cv, KC_ESC),

    COMBO(combo_cvb, UKC_OS_COPY),
    COMBO(combo_vb, UKC_OS_PASTE),
    COMBO(combo_ccomma, CW_TOGG),

    // right hand
    COMBO(combo_hj, KC_RGUI),
    COMBO(combo_jk, KC_RSFT),
    COMBO(combo_kl, KC_RALT),
    COMBO(combo_lscln, KC_RCTL),

    COMBO(combo_hjk, RSFT(KC_RGUI)),
    COMBO(combo_jkl, RALT(KC_RSFT)),
    COMBO(combo_jkscln, RCTL(KC_RSFT)),
    COMBO(combo_klscln, RCTL(KC_RALT)),

    COMBO(combo_hjkl, RALT(RSFT(KC_RGUI))),
    COMBO(combo_jklscln, RCTL(RALT(KC_RSFT))),

    COMBO(combo_mcomma, KC_ENT),

    // two hand
    COMBO(combo_dfjk, CW_TOGG),
    COMBO(combo_lower_space, QK_REPEAT_KEY),
    COMBO(combo_lower_raise, QK_ALT_REPEAT_KEY),
};
