// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "darrenchurchill.h"

#define LAYOUT_voyager_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN_GOLD] = LAYOUT_voyager_wrapper(
        KC_GRV,  ________________NUMBER_LEFT________________,                     ________________NUMBER_RIGHT_______________, KC_BSLS,
        KC_TAB,  ____________HANDS_DOWN_GOLD_L1_____________,                     ____________HANDS_DOWN_GOLD_R1_____________, S(KC_TAB),
        KC_J,    ____________HANDS_DOWN_GOLD_L2_____________,                     ____________HANDS_DOWN_GOLD_R2_____________, KC_ENT,
        KC_BSPC, ____________HANDS_DOWN_GOLD_L3_____________,                     ____________HANDS_DOWN_GOLD_R3_____________, KC_DEL,
                                                      HDKC_T,  TKC_L01,  TKC_R01, TKC_R00
    ),

    [_QWERTY] = LAYOUT_voyager_wrapper(
        KC_GRV,  ________________NUMBER_LEFT________________,                    ________________NUMBER_RIGHT_______________, KC_BSLS,
        KC_TAB,  _________________QWERTY_L1_________________,                    _________________QWERTY_R1_________________, S(KC_TAB),
        KC_ESC,  _________________QWERTY_L2_________________,                    _________________QWERTY_R2_________________, KC_ENT,
        KC_BSPC, _________________QWERTY_L3_________________,                    _________________QWERTY_R3_________________, KC_DEL,
                                                     TKC_L00, TKC_L01,  TKC_R01, TKC_R00
    ),

    [_QWERTY_ALT_SHIFT] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_LOWER] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, _________________LOWER_L1__________________,                    _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_NUMPAD] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, _________________NUMPAD_L1_________________,                    _________________NUMPAD_R1_________________, _______,
        _______, _________________NUMPAD_L2_________________,                    _________________NUMPAD_R2_________________, _______,
        _______, _________________NUMPAD_L3_________________,                    _________________NUMPAD_R3_________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_RAISE] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_EXTEND] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, _________________EXTEND_L1_________________,                    _________________EXTEND_R1_________________, _______,
        _______, _________________EXTEND_L2_________________,                    _________________EXTEND_R2_________________, _______,
        _______, _________________EXTEND_L3_________________,                    _________________EXTEND_R3_________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_ARROWS] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, _________________ARROWS_L2_________________,                    _________________ARROWS_R2_________________, _______,
        _______, _________________ARROWS_L3_________________,                    __________________BLANK_5__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_MOUSE] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, _________________MOUSE_L1__________________,                    _________________MOUSE_R1__________________, _______,
        _______, _________________MOUSE_L2__________________,                    _________________MOUSE_R2__________________, _______,
        _______, _________________MOUSE_L3__________________,                    _________________MOUSE_R3__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    // TODO: Add a leader sequence to access this layer?
    [_KB_LED] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, ________________KB_LED_L1__________________,                    ________________KB_LED_R1__________________, _______,
        _______, ________________KB_LED_L2__________________,                    ________________KB_LED_R2__________________, _______,
        _______, ________________KB_LED_L3__________________,                    ________________KB_LED_R3__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_FN] = LAYOUT_voyager_wrapper(
        _______, ___________________FN_L1___________________,                    ___________________FN_R1___________________, _______,
        _______, ___________________FN_L2___________________,                    ___________________FN_R2___________________, _______,
        _______, ___________________FN_L3___________________,                    ___________________FN_R3___________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
                                                     _______, _______,  _______, _______
    ),

    [_LAYERS] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, ________________LAYERS_L1__________________,                    ________________LAYERS_R1__________________, _______,
        _______, ________________LAYERS_L2__________________,                    ________________LAYERS_R2__________________, _______,
        _______, ________________LAYERS_L3__________________,                    ________________LAYERS_R3__________________, _______,
                                                     _______, _______,  _______, _______
    )
};

/*  Blank

    [_LAYER] = LAYOUT_voyager_wrapper(
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
        _______, __________________BLANK_5__________________,                    __________________BLANK_5__________________, _______,
                                                     _______, _______,  _______, _______
    ),

*/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_keymap(void) {
    rgb_matrix_enable();
}

#define LEDMAP_LAYOUT( \
    C00, C01, C02, C03, C04, C05, \
    C10, C11, C12, C13, C14, C15, \
    C20, C21, C22, C23, C24, C25, \
    C30, C31, C32, C33, C34, C35, \
                        C44, C45, \
    C06, C07, C08, C09, C0A, C0B, \
    C16, C17, C18, C19, C1A, C1B, \
    C26, C27, C28, C29, C2A, C2B, \
    C36, C37, C38, C39, C3A, C3B, \
    C46, C47 \
    ) \
    { \
        {C00}, {C01}, {C02}, {C03}, {C04}, {C05}, /* left top row */ \
        {C10}, {C11}, {C12}, {C13}, {C14}, {C15}, \
        {C20}, {C21}, {C22}, {C23}, {C24}, {C25}, \
        {C30}, {C31}, {C32}, {C33}, {C34}, {C35}, \
                                    {C44}, {C45}, /* thumb keys, inner & outer */ \
        {C06}, {C07}, {C08}, {C09}, {C0A}, {C0B}, /* right top row */ \
        {C16}, {C17}, {C18}, {C19}, {C1A}, {C1B}, \
        {C26}, {C27}, {C28}, {C29}, {C2A}, {C2B}, \
        {C36}, {C37}, {C38}, {C39}, {C3A}, {C3B}, \
        {C46}, {C47} /* thumb keys, outer & inner */ \
    }

// const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
//     [0] = {
//         {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, // left top row
//         {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
//         {0,0,255}, {0,255,255}, {74,254,255}, {195,255,244}, {169,255,255}, {0,0,255},
//         {0,0,255}, {169,255,255}, {205,251,246}, {39,255,255}, {0,255,255}, {0,0,255},
//         {39,255,255}, {0,0,255}, // thumb keys, inner & outer
//         {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
//         {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255},
//         {0,0,255}, {169,255,255}, {195,255,244}, {74,254,255}, {0,255,255}, {0,0,255},
//         {0,0,255}, {0,255,255}, {39,255,255}, {205,251,246}, {169,255,255}, {0,0,255},
//         {0,255,255}, {0,0,255} // thumb keys, outer & inner
//     },
// };

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_HANDS_DOWN_GOLD] = LEDMAP_LAYOUT(
        __ON__, __ON__,  __ON__,  __ON__,  __ON__,  __ON__,
        __ON__, __ON__,  __ON__,  __ON__,  __ON__,  __ON__,
        __ON__, HSV_CTL, HSV_LYR, HSV_LYR, HSV_GUI, __ON__,
        __ON__, HSV_GUI, HSV_ALT, HSV_SFT, HSV_CTL, __ON__,
                                           HSV_LYR, HSV_BSPC,

        __ON__,   __ON__,  __ON__,  __ON__,   __ON__,   __ON__,
        __ON__,   __ON__,  __ON__,  __ON__,   __ON__,   __ON__,
        __ON__,   HSV_GUI, HSV_LYR, HSV_LYR,  HSV_CTL,  __ON__,
        __ON__,   HSV_CTL, HSV_SFT, HSV_ALT,  HSV_GUI,  __ON__,
        HSV_BSPC, __ON__
    ),

    [_QWERTY] = LEDMAP_LAYOUT(
        __ON__, __ON__,  __ON__,  __ON__,  __ON__,  __ON__,
        __ON__, __ON__,  __ON__,  __ON__,  __ON__,  __ON__,
        __ON__, HSV_CTL, HSV_LYR, HSV_LYR, HSV_GUI, __ON__,
        __ON__, HSV_GUI, HSV_ALT, HSV_SFT, HSV_CTL, __ON__,
                                           HSV_LYR, HSV_BSPC,

        __ON__,   __ON__,  __ON__,  __ON__,  __ON__,   __ON__,
        __ON__,   __ON__,  __ON__,  __ON__,  __ON__,   __ON__,
        __ON__,   HSV_GUI, HSV_LYR, HSV_LYR, HSV_CTL,  __ON__,
        __ON__,   HSV_CTL, HSV_SFT, HSV_ALT, HSV_GUI,  __ON__,
        HSV_BSPC, __ON__
    ),

    [_LOWER] = LEDMAP_LAYOUT(
        __xx__, __xx__,  __xx__,  __xx__,   __xx__,   __xx__,
        __xx__, __xx__,  __xx__,  HSV_BRKT, HSV_BRKT, __xx__,
        __xx__, HSV_SYM, HSV_SYM, HSV_SYM,  HSV_SYM,  HSV_SYM,
        __xx__, HSV_SYM, HSV_SYM, HSV_SYM,  HSV_SYM,  HSV_SYM,
                                            __xx__,   __xx__,

        __xx__,  __xx__,  __xx__,   __xx__,   __xx__,  __xx__,
        __xx__,  __xx__,  HSV_BRKT, HSV_BRKT, __xx__,  __xx__,
        HSV_SYM, HSV_SYM, HSV_BRKT, HSV_BRKT, HSV_SYM, __xx__,
        HSV_SYM, HSV_SYM, HSV_BRKT, HSV_BRKT, HSV_SYM, __xx__,
        __xx__,  __xx__
    ),

    [_NUMPAD] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__,   __xx__,   __xx__,   __xx__,
        __xx__, __xx__, __xx__,   HSV_BRKT, HSV_BRKT, __xx__,
        __xx__, HSV_SYM, HSV_SYM, HSV_SYM,  HSV_SYM,  HSV_SYM,
        __xx__, HSV_SYM, HSV_SYM, HSV_SYM,  HSV_SYM,  HSV_SYM,
                                            __xx__,   __xx__,

        __xx__,  __xx__,  __xx__,  __xx__,  __xx__, __xx__,
        __xx__,  HSV_NUM, HSV_NUM, HSV_NUM, __xx__, __xx__,
        HSV_NUM, HSV_NUM, HSV_NUM, HSV_NUM, __ON__, __xx__,
        __xx__,  HSV_NUM, HSV_NUM, HSV_NUM, __xx__, __xx__,
        __xx__,  __xx__
    ),

    [_RAISE] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__,     __xx__,    __xx__,    __xx__,
        __xx__, __xx__, HSV_SELWD,  HSV_ARROW, HSV_SELWD, HSV_PG,
        __xx__, HSV_CTL, HSV_ARROW, HSV_ARROW, HSV_ARROW, HSV_PG,
        __xx__, HSV_CTL, HSV_ALT,   HSV_SFT,   HSV_GUI,   __xx__,
                                               __xx__,    __xx__,

        __xx__,    __xx__,    __xx__,    __xx__,     __xx__,       __xx__,
        HSV_PG,    HSV_PG,    HSV_PG,    HSV_PG,      HSV_GUI,     __xx__,
        HSV_ARROW, HSV_ARROW, HSV_ARROW, HSV_ARROW,   HSV_CTL,     __xx__,
        __xx__,    HSV_PNTAB, HSV_PNTAB, HSV_PNSPACE, HSV_PNSPACE, __xx__,
        __xx__,    __xx__
    ),

    [_EXTEND] = LEDMAP_LAYOUT(
        __xx__, __xx__,  __xx__,  __xx__,  __xx__,  __xx__,
        __xx__, __xx__,  __xx__,  __xx__,  __xx__,  __xx__,
        __xx__, HSV_CTL, __xx__,  HSV_SFT, HSV_GUI, __xx__,
        __xx__, HSV_CTL, HSV_ALT, HSV_SFT, __xx__,  __xx__,
                                           __xx__,  __xx__,

        __xx__,      __xx__,  __xx__,  __xx__,      __xx__,   __xx__,
        HSV_PRV_NXT, HSV_VOL, HSV_VOL, HSV_PRV_NXT, HSV_PLAY, __xx__,
        HSV_BSPC,    __xx__,  __xx__,  HSV_BSPC,    __xx__,   __xx__,
        HSV_MUTE,    __xx__,  __xx__,  __xx__,      __xx__,   __xx__,
        __xx__,      __xx__
    ),

    [_ARROWS] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__, __xx__,    __xx__,    __xx__,
        __xx__, __xx__, __xx__, __xx__,    __xx__,    __xx__,
        __xx__, HSV_PG, HSV_PG, HSV_ARROW, HSV_ARROW, __xx__,
        __xx__, __xx__, __xx__, HSV_BSPC,  HSV_BSPC,  __xx__,
                                           __xx__,    __xx__,

        __xx__,    __xx__,    __xx__,    __xx__,    __xx__, __xx__,
        __xx__,    __xx__,    __xx__,    __xx__,    __xx__, __xx__,
        HSV_ARROW, HSV_ARROW, HSV_ARROW, HSV_ARROW, __xx__, __xx__,
        __xx__,    __xx__,    __xx__,    __xx__,    __xx__, __xx__,
        __xx__,    __xx__
    ),

    [_MOUSE] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
                                        __xx__, __xx__,

        __xx__,       __xx__,       __xx__,       __xx__,       __xx__, __xx__,
        HSV_MS_WHEEL, HSV_MS_WHEEL, HSV_MS_WHEEL, HSV_MS_WHEEL, __xx__, __xx__,
        HSV_MS,       HSV_MS,       HSV_MS,       HSV_MS,       __xx__, __xx__,
        __xx__,       HSV_MS,       HSV_MS,       __xx__,       __xx__, __xx__,
        __xx__,       __xx__
    ),

    [_KB_LED] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__,   __xx__, __xx__, __xx__,
        __xx__, __ON__, __xx__,   __xx__, __xx__, __ON__,
        __xx__, __xx__, HSV_ANIM, __xx__, __xx__, __xx__,
        __xx__, __xx__, __xx__,   __xx__, __xx__, __xx__,
                                          __xx__, __xx__,

        __xx__, __xx__,     __xx__,     __xx__, __xx__, __xx__,
        __xx__, HSV_KB_HUE, HSV_KB_HUE, __xx__, __ON__, __xx__,
        __xx__, __ON__,     __ON__,     __xx__, __xx__, __xx__,
        __xx__, HSV_KB_SAT, HSV_KB_SAT, __xx__, __xx__, __xx__,
        __xx__, __xx__
    ),

    [_FN] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
        __xx__, __xx__, __ON__, __ON__, __ON__, __xx__,
        __xx__, __xx__, __ON__, __ON__, __ON__, __xx__,
                                        __xx__, __xx__,

        __xx__, __xx__, __xx__, __xx__, __xx__, __xx__,
        HSV_FN, HSV_FN, HSV_FN, HSV_FN, HSV_FN, __xx__,
        HSV_FN, HSV_FN, HSV_FN, HSV_FN, HSV_FN, __xx__,
        HSV_FN, HSV_FN, HSV_FN, HSV_FN, HSV_FN, __xx__,
        __xx__, __xx__
    ),

    [_LAYERS] = LEDMAP_LAYOUT(
        __xx__, __xx__, __xx__, __xx__, __xx__,  __xx__,
        __xx__, __xx__, __xx__, __xx__, HSV_LYR, __xx__,
        __xx__, __xx__, __xx__, __xx__, HSV_LYR, __xx__,
        __xx__, __xx__, __xx__, __xx__, __xx__,  __xx__,
                                        __xx__,  __xx__,

        __xx__, __xx__,  __xx__,  __xx__,  __xx__, __xx__,
        __xx__, __xx__,  __xx__,  __xx__,  __xx__, __xx__,
        __xx__, __xx__,  HSV_LYR, HSV_LYR, __xx__, __xx__,
        __xx__, HSV_LYR, __xx__,  __xx__,  __xx__, __xx__,
        __xx__, __xx__
    ),
};

/*  Blank

    [_LAYER_NAME] = LEDMAP_LAYOUT(
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
                                        __ON__, __ON__,

        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__, __ON__, __ON__, __ON__, __ON__,
        __ON__, __ON__
    ),

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
        case _HANDS_DOWN_GOLD:
            set_layer_color(_HANDS_DOWN_GOLD);
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
        case _ARROWS:
            set_layer_color(_ARROWS);
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
