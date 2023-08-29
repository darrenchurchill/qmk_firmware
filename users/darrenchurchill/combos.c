/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

const uint16_t PROGMEM combo_lower_space[] = { LOWER, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_lower_raise[] = { LOWER, RAISE, COMBO_END};
const uint16_t PROGMEM combo_df[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_fg[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_hj[] = { KC_H, KC_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_lower_space, QK_REPEAT_KEY),
    COMBO(combo_lower_raise, QK_ALT_REPEAT_KEY),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_fg, KC_TAB),
    COMBO(combo_hj, KC_ENTER)
};
