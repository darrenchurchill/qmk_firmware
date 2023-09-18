#pragma once
#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
enum tap_dance_codes {
    DANCE_0,
};
#endif // TAP_DANCE_ENABLE

enum userspace_layers {
    _QWERTY,
    _QWERTY_NO_MODS, // top-level "default" layout so can override others temporarily
    _LOWER,
    _RAISE,
    _EXTEND,
    _MOUSE,
    _KB_LED,
    _FN,
    _LAYERS,
};

// "UKC" Userspace KeyCode
// NOTE: When adding a new custom keycode, consider whether to ignore it
// inside of Repeat Key's remember_last_key_user()
enum userspace_custom_keycodes {
  UKC_BASE = SAFE_RANGE,
  UKC_OS_COPY,
  UKC_OS_PASTE,
  UKC_OS_PREV_TAB,
  UKC_OS_NEXT_TAB,
  KEYMAP_SAFE_RANGE  //use "KEYMAP_SAFE_RANGE" for keymap specific codes
};

#define QNM_T(KC) LT(_QWERTY_NO_MODS, KC)
#define LOWER MO(_LOWER)
// TODO: change RAISE macro to a custom tap dance keycode, where tap is QK_REPEAT_KEY
#define RAISE MO(_RAISE)
#define EXT_T(KC) LT(_EXTEND, KC)
#define MOUSE MO(_MOUSE)
#define KB_LED MO(_KB_LED)
#define FN MO(_FN)
#define LAYERS MO(_LAYERS)

/*
  Keycode wrappers
  https://docs.qmk.fm/#/keycodes
 */
#define LEFT_MODS(K01, K02, K03, K04) LCTL_T(K01), LALT_T(K02), LSFT_T(K03), LGUI_T(K04)
#define RIGHT_MODS(K01, K02, K03, K04) RGUI_T(K01), LSFT_T(K02), RALT_T(K03), RCTL_T(K04)


#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       LEFT_MODS(KC_A, KC_S, KC_D, KC_F),  KC_G
#define _________________QWERTY_L3_________________       KC_Z,    EXT_T(KC_X),    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    RIGHT_MODS(KC_J, KC_K, KC_L, KC_SCLN)
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH

#define _____________QWERTY_NO_MODS_R2_____________       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN

#define _________________BASE_5_L4_________________       _____________BASE_4_L4_____________, LOWER
#define _____________BASE_4_L4_____________               LCTL_T(KC_GRV), LALT_T(KC_ESC), KC_LGUI, QNM_T(KC_TAB)

#define _____________BASE_4_R4_____________                        RAISE,  KC_ENT,  KC_QUOT, TD(DANCE_0)
#define _________________BASE_5_R4_________________       LSFT_T(KC_SPC), _____________BASE_4_R4_____________


#define ________________NUMBER_LEFT________________       KC_7,    KC_8,    KC_9,    KC_0,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_1,    KC_2,    KC_3,    KC_4

#define ______________BLANK_4______________               _______, _______, _______, _______
#define __________________BLANK_5__________________       _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________       ________________NUMBER_LEFT________________
#define _________________LOWER_L2__________________       KC_UNDS, KC_PLUS, LSFT_T(KC_MINS), LGUI_T(KC_EQUAL), KC_GRV
#define _________________LOWER_L3__________________       KC_AMPR, KC_SLSH, KC_ASTR, KC_PIPE,  KC_BSLS
#define ____________LOWER_4_L4_____________               _______, UKC_BASE, _______, _______
#define ________________LOWER_5_L4_________________       ____________LOWER_4_L4_____________, _______

#define _________________LOWER_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________LOWER_R2__________________       KC_HASH, RGUI_T(KC_LBRC),  LSFT_T(KC_RBRC), KC_LPRN, KC_RPRN
#define _________________LOWER_R3__________________       QK_AREP, QK_REP, KC_QUOT,  KC_LABK, KC_RABK
#define ____________LOWER_4_R4_____________                        MOUSE,  KC_TILDE, KC_GRV,  _______
#define ________________LOWER_5_R4_________________       _______, ____________LOWER_4_R4_____________


#define _________________RAISE_L1__________________       KC_MUTE, _______, KC_KB_VOLUME_UP,   _______, _______
#define _________________RAISE_L2__________________       _______, KC_MPRV, KC_KB_VOLUME_DOWN, KC_MNXT, _______
#define _________________RAISE_L3__________________       QK_RBT,  _______, _______,           _______, _______
#define ____________RAISE_4_L4_____________               ____________LOWER_4_L4_____________
#define ________________RAISE_5_L4_________________       ____________RAISE_4_L4_____________, FN

#define _________________RAISE_R1__________________       KC_HOME, KC_PGDN,         KC_PGUP,         KC_END,        KC_MPLY
#define _________________RAISE_R2__________________       KC_LEFT, KC_DOWN,         KC_UP,           KC_RIGHT,      LCTL(KC_GRV)
#define _________________RAISE_R3__________________       _______, UKC_OS_PREV_TAB, UKC_OS_NEXT_TAB, _______,       LGUI(KC_GRV)
#define ____________RAISE_4_R4_____________                        ______________BLANK_4______________
#define ________________RAISE_5_R4_________________       _______, ____________RAISE_4_R4_____________


#define _________________EXTEND_L1_________________       __________________BLANK_5__________________
#define _________________EXTEND_L2_________________       __________________BLANK_5__________________
#define _________________EXTEND_L3_________________       __________________BLANK_5__________________
#define ____________EXTEND_4_L4____________               ____________LOWER_4_L4_____________
#define ________________EXTEND_5_L4________________       ____________EXTEND_4_L4____________, _______

#define _________________EXTEND_R1_________________       _______, _______, _______, _______, _______
#define _________________EXTEND_R2_________________       KC_BSPC, KC_QUOT, KC_DQUO, KC_DEL,  KC_GRV
#define _________________EXTEND_R3_________________       _______, _______, _______, _______, _______
#define ____________EXTEND_4_R4____________                        ______________BLANK_4______________
#define ________________EXTEND_5_R4________________       _______, ____________EXTEND_4_R4____________


#define _________________MOUSE_L1__________________       __________________BLANK_5__________________
#define _________________MOUSE_L2__________________       _______, _______, _______, KC_BTN1, KC_BTN2
#define _________________MOUSE_L3__________________       __________________BLANK_5__________________
#define ____________MOUSE_4_L4_____________               ____________LOWER_4_L4_____________
#define ________________MOUSE_5_L4_________________       ____________MOUSE_4_L4_____________, _______

#define _________________MOUSE_R1__________________       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _________________MOUSE_R2__________________       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______
#define _________________MOUSE_R3__________________       __________________BLANK_5__________________


#define ________________KB_LED_L1__________________       RGB_TOG, _______, _______, _______, TOGGLE_LAYER_COLOR
#define ________________KB_LED_L2__________________       _______, RGB_MOD, _______, _______, _______
#define ________________KB_LED_L3__________________       __________________BLANK_5__________________
#define ___________KB_LED_4_L4_____________               QK_BOOT, UKC_BASE,    _______, _______
#define _______________KB_LED_5_L4_________________       ___________KB_LED_4_L4_____________, _______

#define ________________KB_LED_R1__________________       _______, RGB_HUD, RGB_HUI, _______, RGB_MODE_PLAIN
#define ________________KB_LED_R2__________________       _______, RGB_VAD, RGB_VAI, _______, _______
#define ________________KB_LED_R3__________________       _______, RGB_SAD, RGB_SAI, _______, _______
#define ___________KB_LED_4_R4_____________                        _______, _______, RGB_SPD, RGB_SPI
#define _______________KB_LED_5_R4_________________       _______, ___________KB_LED_4_R4_____________


#define ___________________FN_L1___________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ___________________FN_L2___________________       KC_F11,  KC_F12,  _______, _______, _______

#define ___________________FN_R1___________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ___________________FN_R2___________________       DT_PRNT, DT_DOWN, DT_UP,   _______, _______
#define ___________________FN_R3___________________       AS_RPT,  AS_DOWN, AS_UP,   _______, _______


#define ________________LAYERS_L1__________________       _______, _______, _______, TO(_RAISE), _______
#define ________________LAYERS_L2__________________       _______, _______, _______, TO(_FN),    _______
#define ________________LAYERS_L3__________________       __________________BLANK_5__________________
#define ___________LAYERS_4_L4_____________               ____________LOWER_4_L4_____________
#define _______________LAYERS_5_L4_________________       ___________LAYERS_4_L4_____________, _______

#define ________________LAYERS_R1__________________       __________________BLANK_5__________________
#define ________________LAYERS_R2__________________       _______, _______, TO(_KB_LED), TO(_LAYERS), _______
#define ________________LAYERS_R3__________________       _______, TO(_MOUSE), _______, _______, _______


/*
  Color wrappers
 */
// See color.h for example HSV and RGB macro definitions
#ifdef RGB_MATRIX_ENABLE
#define HSV_ON              HSV_WHITE

#define HSV_CTL             3, 252, 255    // Carolina Reaper red
#define HSV_ALT             218, 219, 209  // Magentella purple
#define HSV_SFT             35, 252, 255   // Inca Yellow yellow
#define HSV_GUI             139, 218, 208  // Hu Lan Blue blue

#define HSV_LYR             53, 255, 255   // French Lime green
#define HSV_LYR_ESC         16, 252, 255   // Safety Orange orange

#define HSV_BSPC            0, 245, 245    // Assassin's Red red
#define HSV_CAPS            41, 255, 255   // Cadmium yellow
#define HSV_QUOT            151, 140, 149  // Queen Blue blue
#define HSV_NUM             89, 243, 150   // Green Gardens green
#define HSV_SYM             196, 219, 209  // Lilac Spring purple
#define HSV_BRKT            152, 255, 255  // Blue Sparkle blue

#define HSV_MUTE            HSV_CTL
#define HSV_PLAY            148, 245, 230  // Blue Cola blue
#define HSV_VOL             91, 243, 139   // Emerald green
#define HSV_PRV_NXT         HSV_SYM

#define HSV_PG              69, 253, 143   // Planter green
#define HSV_ARROW           163, 253, 255  // Blinking Blue blue
#define HSV_PNTAB           164, 218, 204  // Blue blue
#define HSV_PNTAB_LINUX     11, 219, 233   // Ubuntu orange
#define HSV_MS              37, 246, 235   // Golden Crescent yellow
#define HSV_MS_WHEEL        HSV_GUI

#define HSV_TOGGLE          HSV_RED
#define HSV_ANIM            187, 242, 221  // Space Opera purple
#define HSV_RESET           77, 211, 255   // Alien Parasite green
#define HSV_KB_HUE          HSV_GUI
#define HSV_KB_BRT          HSV_WHITE
#define HSV_KB_SAT          HSV_RESET

#define HSV_FN              HSV_LYR
#endif // RGB_MATRIX_ENABLE
