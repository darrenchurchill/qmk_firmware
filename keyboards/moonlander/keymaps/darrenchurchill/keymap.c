#include QMK_KEYBOARD_H
#include "darrenchurchill.h"
#include "version.h"


#define LAYOUT_moonlander_wrapper(...) LAYOUT_moonlander(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_moonlander_wrapper(
        KC_EQL,  ________________NUMBER_LEFT________________,  _______,       _______, ________________NUMBER_RIGHT_______________, KC_BSLS,
        KC_GRV,  ________________COLEMAK_L1_________________,  KC_GRV,        KC_MINS, ________________COLEMAK_R1_________________, KC_MINS,
        KC_TAB,  ________________COLEMAK_L2_________________,  KC_GRV,        KC_DQUO, ________________COLEMAK_R2_________________, KC_QUOT,
        KC_BSPC, ________________COLEMAK_L3_________________,                          ________________COLEMAK_R3_________________, KC_DEL,
        KC_LCTL, _____________BASE_4_L4_____________,          TKC_L10,       TKC_R10,         _____________BASE_4_R4_____________, KC_RCTL,
                                            TKC_L00, TKC_L01, TKC_L02,        TKC_R02, TKC_R01, TKC_R00
    ),

    [_QWERTY] = LAYOUT_moonlander_wrapper(
        KC_EQL,  ________________NUMBER_LEFT________________,  _______,       _______, ________________NUMBER_RIGHT_______________, KC_BSLS,
        KC_GRV,  _________________QWERTY_L1_________________,  KC_GRV,        KC_MINS, _________________QWERTY_R1_________________, KC_MINS,
        KC_TAB,  _________________QWERTY_L2_________________,  KC_GRV,        KC_DQUO, _________________QWERTY_R2_________________, KC_QUOT,
        KC_BSPC, _________________QWERTY_L3_________________,                          _________________QWERTY_R3_________________, KC_DEL,
        KC_LCTL, _____________BASE_4_L4_____________,          TKC_L10,       TKC_R10,         _____________BASE_4_R4_____________, KC_RCTL,
                                            TKC_L00, TKC_L01, TKC_L02,        TKC_R02, TKC_R01, TKC_R00
    ),

    [_LOWER] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,         _______, __________________BLANK_5__________________, _______,
        _______, _________________LOWER_L1__________________, _______,         _______, _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________, _______,         _______, _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________,                           _________________LOWER_R3__________________, _______,
        _______, ____________LOWER_4_L4_____________,         _______,         _______,         ____________LOWER_4_R4_____________, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_NUMPAD] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,         _______, __________________BLANK_5__________________, _______,
        _______, _________________NUMPAD_L1_________________, _______,         _______, _________________NUMPAD_R1_________________, _______,
        _______, _________________NUMPAD_L2_________________, _______,         _______, _________________NUMPAD_R2_________________, _______,
        _______, _________________NUMPAD_L3_________________,                           _________________NUMPAD_R3_________________, _______,
        _______, ____________NUMPAD_4_L4____________,         _______,         _______,         ____________NUMPAD_4_R4____________, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_RAISE] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,         _______, __________________BLANK_5__________________, _______,
        _______, _________________RAISE_L1__________________, _______,         _______, _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________, _______,         KC_DEL,  _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________,                           _________________RAISE_R3__________________, _______,
        _______, ____________RAISE_4_L4_____________,         _______,         _______,         ____________RAISE_4_R4_____________, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_EXTEND] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,         _______, __________________BLANK_5__________________, _______,
        _______, _________________EXTEND_L1_________________, _______,         _______, _________________EXTEND_R1_________________, _______,
        _______, _________________EXTEND_L2_________________, _______,         _______, _________________EXTEND_R2_________________, _______,
        _______, _________________EXTEND_L3_________________,                           _________________EXTEND_R3_________________, _______,
        _______, ____________EXTEND_4_L4____________,         _______,         _______,         ____________EXTEND_4_R4____________, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_ARROWS] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,         _______, __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________, _______,         _______, __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________, _______,         _______, _________________ARROWS_R2_________________, _______,
        _______, __________________BLANK_5__________________,                           __________________BLANK_5__________________, _______,
        _______, ______________BLANK_4______________,         _______,         _______,         ______________BLANK_4______________, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,        _______, __________________BLANK_5__________________, _______,
        _______, _________________MOUSE_L1__________________, _______,        _______, _________________MOUSE_R1__________________, _______,
        _______, _________________MOUSE_L2__________________, _______,        _______, _________________MOUSE_R2__________________, _______,
        _______, _________________MOUSE_L3__________________,                          _________________MOUSE_R3__________________, _______,
        _______, ____________MOUSE_4_L4_____________,         _______,        _______,         _____________MOUSE_4_R4____________, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    // TODO: Add a leader sequence to access this layer?
    [_KB_LED] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,        _______, __________________BLANK_5__________________, _______,
        _______, ________________KB_LED_L1__________________, _______,        _______, ________________KB_LED_R1__________________, _______,
        _______, ________________KB_LED_L2__________________, _______,        _______, ________________KB_LED_R2__________________, _______,
        _______, ________________KB_LED_L3__________________,                          ________________KB_LED_R3__________________, _______,
        _______, ___________KB_LED_4_L4_____________,         _______,        _______,         ___________KB_LED_4_R4_____________, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_FN] = LAYOUT_moonlander_wrapper(
        _______, ___________________FN_L1___________________, _______,        _______, ___________________FN_R1___________________, _______,
        _______, ___________________FN_L2___________________, _______,        _______, ___________________FN_R2___________________, _______,
        _______, ___________________FN_L3___________________, _______,        _______, ___________________FN_R3___________________, _______,
        _______, __________________BLANK_5__________________,                          __________________BLANK_5__________________, _______,
        _______, _______, UKC_BASE, _______, _______,         _______,        _______,         ______________BLANK_4______________, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

    [_LAYERS] = LAYOUT_moonlander_wrapper(
        _______, __________________BLANK_5__________________, _______,        _______, __________________BLANK_5__________________, _______,
        _______, ________________LAYERS_L1__________________, _______,        _______, ________________LAYERS_R1__________________, _______,
        _______, ________________LAYERS_L2__________________, _______,        _______, ________________LAYERS_R2__________________, _______,
        _______, ________________LAYERS_L3__________________,                          ________________LAYERS_R3__________________, _______,
        _______, ___________LAYERS_4_L4_____________,         _______,        _______,         ______________BLANK_4______________, _______,
                                            _______, _______, _______,        _______, _______, _______
    )
};

/*  Blank

    [_LAYER] = LAYOUT_moonlander_wrapper(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,        _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______
    ),

*/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_keymap(void) {
    rgb_matrix_enable();
}

// in columns, NOT rows
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_COLEMAK] = {
        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},  {HSV_ON}, // left outside column, top to bottom
        {HSV_ON},  {HSV_ON},   {HSV_CTL}, {HSV_CTL}, {HSV_CTL},
        {HSV_ON},  {HSV_ON},   {HSV_LYR}, {HSV_ALT}, {HSV_ALT},
        {HSV_ON},  {HSV_ON},   {HSV_SFT}, {HSV_SFT}, {HSV_GUI},
        {HSV_ON},  {HSV_ON},   {HSV_GUI}, {HSV_ON},  {HSV_LYR},
        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},
        {HSV_OFF}, {HSV_QUOT}, {HSV_ON},
        {HSV_LYR}, {HSV_BSPC}, {HSV_ON}, // piano keys
        {HSV_ON}, // thumb key

        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},  {HSV_ON}, // right outside column, top to bottom
        {HSV_ON},  {HSV_ON},   {HSV_CTL}, {HSV_CTL}, {HSV_QUOT},
        {HSV_ON},  {HSV_ON},   {HSV_LYR}, {HSV_ALT}, {HSV_QUOT},
        {HSV_ON},  {HSV_ON},   {HSV_SFT}, {HSV_SFT}, {HSV_ON},
        {HSV_ON},  {HSV_ON},   {HSV_GUI}, {HSV_ON},  {HSV_LYR},
        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},
        {HSV_OFF}, {HSV_QUOT}, {HSV_SYM},
        {HSV_ON},  {HSV_BSPC}, {HSV_ON},
        {HSV_ON}
    },

    [_QWERTY] = {
        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},  {HSV_ON}, // left outside column, top to bottom
        {HSV_ON},  {HSV_ON},   {HSV_CTL}, {HSV_CTL}, {HSV_CTL},
        {HSV_ON},  {HSV_ON},   {HSV_LYR}, {HSV_ALT}, {HSV_ALT},
        {HSV_ON},  {HSV_ON},   {HSV_SFT}, {HSV_SFT}, {HSV_GUI},
        {HSV_ON},  {HSV_ON},   {HSV_GUI}, {HSV_ON},  {HSV_LYR},
        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},
        {HSV_OFF}, {HSV_QUOT}, {HSV_ON},
        {HSV_LYR}, {HSV_BSPC}, {HSV_ON}, // piano keys
        {HSV_ON}, // thumb key

        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},  {HSV_ON}, // right outside column, top to bottom
        {HSV_ON},  {HSV_ON},   {HSV_CTL}, {HSV_CTL}, {HSV_QUOT},
        {HSV_ON},  {HSV_ON},   {HSV_LYR}, {HSV_ALT}, {HSV_QUOT},
        {HSV_ON},  {HSV_ON},   {HSV_SFT}, {HSV_SFT}, {HSV_ON},
        {HSV_ON},  {HSV_ON},   {HSV_GUI}, {HSV_ON},  {HSV_LYR},
        {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON},
        {HSV_OFF}, {HSV_QUOT}, {HSV_SYM},
        {HSV_ON},  {HSV_BSPC}, {HSV_ON},
        {HSV_ON}
    },

    [_LOWER] = {
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM}, {HSV_SYM}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM}, {HSV_SYM}, {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_BRKT}, {HSV_SYM}, {HSV_SYM}, {HSV_OFF},
        {HSV_OFF}, {HSV_BRKT}, {HSV_SYM}, {HSV_SYM}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM}, {HSV_SYM},
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},  {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM},  {HSV_SYM},  {HSV_OFF},
        {HSV_OFF}, {HSV_BRKT}, {HSV_BRKT}, {HSV_BRKT}, {HSV_OFF},
        {HSV_OFF}, {HSV_BRKT}, {HSV_BRKT}, {HSV_BRKT}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM},  {HSV_SYM},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM},  {HSV_SYM},
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}
    },

    [_NUMPAD] = {
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM}, {HSV_SYM}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM}, {HSV_SYM}, {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_BRKT}, {HSV_SYM}, {HSV_SYM}, {HSV_OFF},
        {HSV_OFF}, {HSV_BRKT}, {HSV_SYM}, {HSV_SYM}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_SYM}, {HSV_SYM},
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_ON},  {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_NUM}, {HSV_NUM}, {HSV_NUM}, {HSV_OFF},
        {HSV_OFF}, {HSV_NUM}, {HSV_NUM}, {HSV_NUM}, {HSV_OFF},
        {HSV_OFF}, {HSV_NUM}, {HSV_NUM}, {HSV_NUM}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_NUM}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}
    },

    [_RAISE] = {
        {HSV_OFF}, {HSV_OFF},   {HSV_OFF},   {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},   {HSV_CTL},   {HSV_CTL}, {HSV_OFF},
        {HSV_OFF}, {HSV_SELWD}, {HSV_ARROW}, {HSV_ALT}, {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_ARROW}, {HSV_ARROW}, {HSV_SFT}, {HSV_OFF},
        {HSV_OFF}, {HSV_SELWD}, {HSV_ARROW}, {HSV_GUI}, {HSV_OFF},
        {HSV_OFF}, {HSV_PG},    {HSV_PG},    {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},   {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},   {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},   {HSV_OFF},     {HSV_OFF},
        {HSV_OFF}, {HSV_GUI}, {HSV_CTL},   {HSV_PNSPACE}, {HSV_OFF},
        {HSV_OFF}, {HSV_PG},  {HSV_ARROW}, {HSV_PNSPACE}, {HSV_OFF},
        {HSV_OFF}, {HSV_PG},  {HSV_ARROW}, {HSV_PNTAB},   {HSV_OFF},
        {HSV_OFF}, {HSV_PG},  {HSV_ARROW}, {HSV_PNTAB},   {HSV_OFF},
        {HSV_OFF}, {HSV_PG},  {HSV_ARROW}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_BSPC},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}
    },

    [_EXTEND] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_CTL}, {HSV_CTL}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_ALT}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_SFT}, {HSV_SFT}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_GUI}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF},     {HSV_OFF},  {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_PLAY},    {HSV_OFF},  {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_PRV_NXT}, {HSV_BSPC}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_VOL},     {HSV_OFF},  {HSV_OFF},  {HSV_OFF},
        {HSV_OFF}, {HSV_VOL},     {HSV_OFF},  {HSV_MUTE}, {HSV_OFF},
        {HSV_OFF}, {HSV_PRV_NXT}, {HSV_BSPC}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},     {HSV_QUOT},
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF},
        {HSV_OFF}
    },

    [_MOUSE] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_MS_WHEEL}, {HSV_MS}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_MS_WHEEL}, {HSV_MS}, {HSV_MS}, {HSV_OFF},
        {HSV_OFF}, {HSV_MS_WHEEL}, {HSV_MS}, {HSV_MS}, {HSV_OFF},
        {HSV_OFF}, {HSV_MS_WHEEL}, {HSV_MS}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}
    },

    [_KB_LED] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_ON}, {HSV_OFF}, {HSV_OFF}, {HSV_RESET},
        {HSV_OFF}, {HSV_OFF}, {HSV_ANIM}, {HSV_OFF}, {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_ON}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_ON}, {HSV_OFF}, {HSV_OFF}, {HSV_ANIM},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_ANIM},
        {HSV_OFF}, {HSV_KB_HUE}, {HSV_ON}, {HSV_KB_SAT}, {HSV_OFF},
        {HSV_OFF}, {HSV_KB_HUE}, {HSV_ON}, {HSV_KB_SAT}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}
    },

    [_FN] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_ON},  {HSV_ON},  {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_OFF}, {HSV_ON},  {HSV_ON},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_ON},  {HSV_ON},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_FN},  {HSV_FN},  {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_FN},  {HSV_FN},  {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_FN},  {HSV_FN},  {HSV_FN},  {HSV_OFF},
        {HSV_OFF}, {HSV_FN},  {HSV_FN},  {HSV_FN},  {HSV_OFF},
        {HSV_OFF}, {HSV_FN},  {HSV_FN},  {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}
    },

    [_LAYERS] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_LYR_ESC},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_LYR}, {HSV_LYR}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_LYR}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_LYR}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_LYR}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}
    },
};

/*  Blank

    [_LAYER_NAME] = {
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, // left outside column, top to bottom
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, // piano keys
        {HSV_ON}, // thumb key

        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, // right outside column, top to bottom
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_LYR},
        {HSV_ON}, {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}, {HSV_ON}, {HSV_ON},
        {HSV_ON}
    },

*/

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (!keyboard_config.rgb_matrix_enable) {
        return false;
    }
    if (keyboard_config.disable_layer_led) { return false; }
    switch (biton32(layer_state)) {
        case _COLEMAK:
            set_layer_color(_COLEMAK);
            break;
        case _QWERTY:
            set_layer_color(_QWERTY);
            break;
        case _LOWER:
            set_layer_color(_LOWER);
            break;
        case _NUMPAD:
            set_layer_color(_NUMPAD);
            break;
        case _RAISE:
            set_layer_color(_RAISE);
            break;
        case _EXTEND:
            set_layer_color(_EXTEND);
            break;
        case _MOUSE:
            set_layer_color(_MOUSE);
            break;
        case _KB_LED:
            set_layer_color(_KB_LED);
            break;
        case _FN:
            set_layer_color(_FN);
            break;
        case _LAYERS:
            set_layer_color(_LAYERS);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE)
            rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}
