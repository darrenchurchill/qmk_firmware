/*
  Combos
  https://docs.qmk.fm/#/feature_combo?id=combos
*/
#include QMK_KEYBOARD_H

#include "combos.h"
#include "darrenchurchill.h"

const uint16_t PROGMEM combo1[] = { LOWER, KC_SPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, QK_REPEAT_KEY),
};
