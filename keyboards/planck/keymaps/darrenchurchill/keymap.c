#include QMK_KEYBOARD_H
#include "darrenchurchill.h"
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#include "eeprom.h"


#define LAYOUT_planck_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)

// You can use macros to define "base" Raise layouts that can differ only in
// the keys you want to switch between Mac/Linux
// Something like this:
// https://github.com/qmk/qmk_firmware/blob/14e14e9ab8420bf15929d07da389a08a6d79fe3c/keyboards/moonlander/keymaps/drashna/keymap.c#L26

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_wrapper(
        _________________QWERTY_L1_________________, KC_GRV,         KC_MINS,        _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, KC_GRV,         KC_MINS,        _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, HYPR_T(KC_GRV), MEH_T(KC_MINS), _________________QWERTY_R3_________________,
        _________________BASE_5_L4_________________, KC_BSPC,        XXXXXXX,        _________________BASE_5_R4_________________
    ),

    [_LOWER] = LAYOUT_planck_wrapper(
        _________________LOWER_L1__________________, _______, _______, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _______, _______, _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________,
        ________________LOWER_5_L4_________________, _______, XXXXXXX, ________________LOWER_5_R4_________________
    ),

    [_RAISE] = LAYOUT_planck_wrapper(
        _________________RAISE_L1__________________, _______, _______, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _______, KC_DEL,  _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _______, _______, _________________RAISE_R3__________________,
        ________________RAISE_5_L4_________________, _______, XXXXXXX, ________________RAISE_5_R4_________________
    ),

    [_MOUSE] = LAYOUT_planck_wrapper(
        _________________MOUSE_L1__________________, _______, _______, _________________MOUSE_R1__________________,
        _________________MOUSE_L2__________________, _______, _______, _________________MOUSE_R2__________________,
        _________________MOUSE_L3__________________, _______, _______, _________________MOUSE_R3__________________,
        ________________MOUSE_5_L4_________________, _______, XXXXXXX, __________________BLANK_5__________________
    ),

    [_KB_LED] = LAYOUT_planck_wrapper(
        ________________KB_LED_L1__________________, _______, _______, ________________KB_LED_R1__________________,
        ________________KB_LED_L2__________________, _______, _______, ________________KB_LED_R2__________________,
        ________________KB_LED_L3__________________, _______, _______, ________________KB_LED_R3__________________,
        _______________KB_LED_5_L4_________________, _______, XXXXXXX, _______________KB_LED_5_R4_________________
    ),

    [_FN] = LAYOUT_planck_wrapper(
        ___________________FN_L1___________________, _______, _______, ___________________FN_R1___________________,
        ___________________FN_L2___________________, _______, _______, ___________________FN_R2___________________,
        __________________BLANK_5__________________, _______, _______, ___________________FN_R3___________________,
        _______, BASE,    _______, _______, _______, _______, XXXXXXX, __________________BLANK_5__________________
    ),

    [_LAYERS] = LAYOUT_planck_wrapper(
        ________________LAYERS_L1__________________, _______, _______, ________________LAYERS_R1__________________,
        ________________LAYERS_L2__________________, _______, _______, ________________LAYERS_R2__________________,
        ________________LAYERS_L3__________________, _______, _______, ________________LAYERS_R3__________________,
        _______________LAYERS_5_L4_________________, _______, XXXXXXX, __________________BLANK_5__________________
    ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_keymap(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = {
        {HSV_ON},  {HSV_ON},  {HSV_ON},  {HSV_ON},  {HSV_ON},  {HSV_ON},   {HSV_SYM}, {HSV_ON}, {HSV_ON},  {HSV_ON},  {HSV_ON},   {HSV_ON},
        {HSV_ON},  {HSV_ON},  {HSV_ON},  {HSV_ON},  {HSV_ON},  {HSV_ON},   {HSV_SYM}, {HSV_ON}, {HSV_ON},  {HSV_ON},  {HSV_ON},   {HSV_ON},
        {HSV_CTL}, {HSV_ALT}, {HSV_SFT}, {HSV_GUI}, {HSV_ON},  {HSV_ON},   {HSV_ON},  {HSV_ON}, {HSV_GUI}, {HSV_SFT}, {HSV_ALT},  {HSV_CTL},
        {HSV_CTL}, {HSV_ALT}, {HSV_ON},  {HSV_GUI}, {HSV_LYR}, {HSV_BSPC},            {HSV_ON}, {HSV_LYR}, {HSV_ON},  {HSV_QUOT}, {HSV_LYR}
    },

    [_LOWER] = {
        {HSV_NUM}, {HSV_NUM},     {HSV_NUM}, {HSV_NUM}, {HSV_NUM}, {HSV_OFF}, {HSV_OFF}, {HSV_NUM}, {HSV_NUM},  {HSV_NUM},  {HSV_NUM},  {HSV_NUM},
        {HSV_SYM}, {HSV_SYM},     {HSV_SYM}, {HSV_SYM}, {HSV_SYM}, {HSV_OFF}, {HSV_OFF}, {HSV_SYM}, {HSV_BRKT}, {HSV_BRKT}, {HSV_BRKT}, {HSV_BRKT},
        {HSV_SYM}, {HSV_SYM},     {HSV_SYM}, {HSV_SYM}, {HSV_SYM}, {HSV_OFF}, {HSV_OFF}, {HSV_SYM}, {HSV_SYM},  {HSV_SYM},  {HSV_BRKT}, {HSV_BRKT},
        {HSV_OFF}, {HSV_LYR_ESC}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},            {HSV_OFF}, {HSV_LYR},  {HSV_OFF},  {HSV_SYM},  {HSV_OFF}
    },

    [_RAISE] = {
        {HSV_MUTE}, {HSV_CAPS},    {HSV_VOL}, {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF},  {HSV_PG},    {HSV_PG},    {HSV_PG},    {HSV_PG},          {HSV_PLAY},
        {HSV_CAPS}, {HSV_PRV_NXT}, {HSV_VOL}, {HSV_PRV_NXT}, {HSV_OFF}, {HSV_OFF}, {HSV_BSPC}, {HSV_ARROW}, {HSV_ARROW}, {HSV_ARROW}, {HSV_ARROW},       {HSV_OFF},
        {HSV_CTL},  {HSV_ALT},     {HSV_SFT}, {HSV_GUI},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF},  {HSV_OFF},   {HSV_PNTAB}, {HSV_PNTAB}, {HSV_PNTAB_LINUX}, {HSV_PNTAB_LINUX},
        {HSV_OFF},  {HSV_LYR_ESC}, {HSV_OFF}, {HSV_OFF},     {HSV_LYR}, {HSV_OFF},             {HSV_OFF},   {HSV_OFF},   {HSV_OFF},   {HSV_OFF},         {HSV_OFF}
    },

    [_MOUSE] = {
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_MS},       {HSV_MS},       {HSV_MS},       {HSV_MS},       {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_MS},  {HSV_MS},  {HSV_OFF}, {HSV_OFF}, {HSV_MS_WHEEL}, {HSV_MS_WHEEL}, {HSV_MS_WHEEL}, {HSV_MS_WHEEL}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},      {HSV_OFF},      {HSV_OFF},      {HSV_OFF},      {HSV_OFF},
        {HSV_OFF}, {HSV_LYR_ESC}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},            {HSV_OFF},      {HSV_OFF},      {HSV_OFF},      {HSV_OFF},      {HSV_OFF}
    },

    [_KB_LED] = {
        {HSV_TOGGLE}, {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_TOGGLE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_KB_HUE}, {HSV_KB_HUE}, {HSV_OFF},  {HSV_TOGGLE},
        {HSV_OFF},    {HSV_ANIM},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_KB_BRT}, {HSV_KB_BRT}, {HSV_OFF},  {HSV_OFF},
        {HSV_OFF},    {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_KB_SAT}, {HSV_KB_SAT}, {HSV_OFF},  {HSV_OFF},
        {HSV_RESET},  {HSV_LYR_ESC}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},    {HSV_OFF},            {HSV_OFF}, {HSV_OFF},    {HSV_OFF},    {HSV_ANIM}, {HSV_ANIM}
    },

    [_FN] = {
        {HSV_FN},  {HSV_FN},      {HSV_FN},  {HSV_FN},  {HSV_FN},  {HSV_OFF}, {HSV_OFF}, {HSV_FN},  {HSV_FN},  {HSV_FN},  {HSV_FN},  {HSV_FN},
        {HSV_FN},  {HSV_FN},      {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_LYR_ESC}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},            {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}
    },

    [_LAYERS] = {
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_LYR}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_LYR}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_LYR}, {HSV_LYR}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},     {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_LYR}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_LYR_ESC}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},            {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}
    },

};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (!keyboard_config.rgb_matrix_enable) {
        return false;
    }
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case _BASE:
            set_layer_color(_BASE);
            break;
        case _LOWER:
            set_layer_color(_LOWER);
            break;
        case _RAISE:
            set_layer_color(_RAISE);
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
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}
