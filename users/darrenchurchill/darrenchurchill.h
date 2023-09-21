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
  UKC_SG_ARRW,
  UKC_DB_ARRW,
  KEYMAP_SAFE_RANGE  //use "KEYMAP_SAFE_RANGE" for keymap specific codes
};


/*
  Layer Macros
*/
#define QNM_T(KC) LT(_QWERTY_NO_MODS, KC)
#define LWR MO(_LOWER)
// TODO: change RAISE macro to a custom tap dance keycode, where tap is QK_REPEAT_KEY
#define RSE_T(KC) LT(_RAISE, KC)
#define EXT_T(KC) LT(_EXTEND, KC)
#define MS_T(KC) LT(_MOUSE, KC)
#define KB_LED MO(_KB_LED)
#define FN_T(KC) LT(_FN, KC)
#define LAYERS MO(_LAYERS)


/*
  Keycode Macros
*/
#define VOL_DN  KC_KB_VOLUME_DOWN
#define VOL_UP  KC_KB_VOLUME_UP
#define OS_PTAB UKC_OS_PREV_TAB
#define OS_NTAB UKC_OS_NEXT_TAB

// QWERTY Layer Keys: QKC -> "Qwerty KeyCode"
// Left Hand
#define QKC_A LCTL_T(KC_A)
#define QKC_S LALT_T(KC_S)
#define QKC_D LSFT_T(KC_D)
#define QKC_F LGUI_T(KC_F)
#define QKC_Z FN_T(KC_Z)
#define QKC_X EXT_T(KC_X)
#define QKC_V MS_T(KC_V)
// Right Hand
#define QKC_J RGUI_T(KC_J)
#define QKC_K LSFT_T(KC_K)
#define QKC_L RALT_T(KC_L)
#define QKC_SC RCTL_T(KC_SCLN)

// Base Keys (Bottom Row + Thumb Keys): BKC -> "Base KeyCode"
// These are named by the Qwerty key they sit below
// Left Hand
#define BKC_Z LCTL_T(KC_GRV)
#define BKC_X LALT_T(KC_ESC)
#define BKC_C KC_LGUI
#define BKC_V QNM_T(KC_TAB)
#define BKC_B LWR
// Right Hand
#define BKC_N LSFT_T(KC_SPACE)
#define BKC_M RSE_T(KC_ENT)
#define BKC_COM KC_ENT
#define BKC_DOT KC_QUOT
#define BKC_SLSH TD(DANCE_0)

// LOWER Layer Keys: LKC -> "Lower KeyCode"
// Left Hand
#define LKC_D LSFT_T(KC_HASH)
#define LKC_F LGUI_T(KC_DLR)
// Right Hand
#define LKC_J RGUI_T(KC_LPRN)
#define LKC_K LSFT_T(KC_RPRN)

/*
  Keycode wrappers
  https://docs.qmk.fm/#/keycodes
*/
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       QKC_A,   QKC_S,   QKC_D,   QKC_F,   KC_G
#define _________________QWERTY_L3_________________       QKC_Z,   QKC_X,   KC_C,    QKC_V,   KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    QKC_J,   QKC_K,   QKC_L,   QKC_SC
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _____________QWERTY_NO_MODS_R2_____________       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN

#define _____________BASE_4_L4_____________               BKC_Z,   BKC_X,   BKC_C,   BKC_V
#define _________________BASE_5_L4_________________       _____________BASE_4_L4_____________, BKC_B

#define _____________BASE_4_R4_____________                        BKC_M,   BKC_COM, BKC_DOT, BKC_SLSH
#define _________________BASE_5_R4_________________       BKC_N, _____________BASE_4_R4_____________


#define ________________NUMBER_LEFT________________       KC_7,    KC_8,    KC_9,    KC_0,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_1,    KC_2,    KC_3,    KC_4

#define ______________BLANK_4______________               _______, _______, _______, _______
#define __________________BLANK_5__________________       _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________       ________________NUMBER_LEFT________________
#define _________________LOWER_L2__________________       KC_QUOT, KC_DQUO,  LKC_D,   LKC_F,   KC_GRV
#define _________________LOWER_L3__________________       KC_AMPR, KC_SLSH,  KC_ASTR, KC_PLUS, KC_PIPE
#define ____________LOWER_4_L4_____________               _______, UKC_BASE, _______, _______
#define ________________LOWER_5_L4_________________       ____________LOWER_4_L4_____________, _______

#define _________________LOWER_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________LOWER_R2__________________       KC_UNDS, LKC_J,   LKC_K,   KC_LBRC, KC_RBRC
#define _________________LOWER_R3__________________       KC_BSLS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR
#define ____________LOWER_4_R4_____________                        _______, _______, KC_EXLM, _______
#define ________________LOWER_5_R4_________________       _______, ____________LOWER_4_R4_____________


#define _________________RAISE_L1__________________       __________________BLANK_5__________________
#define _________________RAISE_L2__________________       __________________BLANK_5__________________
#define _________________RAISE_L3__________________       QK_RBT,  _______, _______, _______, _______
#define ____________RAISE_4_L4_____________               ____________LOWER_4_L4_____________
#define ________________RAISE_5_L4_________________       ____________RAISE_4_L4_____________, _______

#define _________________RAISE_R1__________________       KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______
#define _________________RAISE_R2__________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, LCTL(KC_GRV)
#define _________________RAISE_R3__________________       _______, OS_PTAB, OS_NTAB, _______,  LGUI(KC_GRV)
#define ____________RAISE_4_R4_____________                        ______________BLANK_4______________
#define ________________RAISE_5_R4_________________       _______, ____________RAISE_4_R4_____________


#define _________________EXTEND_L1_________________       __________________BLANK_5__________________
#define _________________EXTEND_L2_________________       __________________BLANK_5__________________
#define _________________EXTEND_L3_________________       __________________BLANK_5__________________
#define ____________EXTEND_4_L4____________               ____________LOWER_4_L4_____________
#define ________________EXTEND_5_L4________________       ____________EXTEND_4_L4____________, _______

#define _________________EXTEND_R1_________________       KC_MPRV, VOL_DN,  VOL_UP,  KC_MNXT, KC_MPLY
#define _________________EXTEND_R2_________________       KC_BSPC, _______, _______, KC_DEL,  _______
#define _________________EXTEND_R3_________________       _______, KC_MUTE, _______, _______, _______
#define ____________EXTEND_4_R4____________                        ______________BLANK_4______________
#define ________________EXTEND_5_R4________________       _______, ____________EXTEND_4_R4____________


#define _________________MOUSE_L1__________________       __________________BLANK_5__________________
#define _________________MOUSE_L2__________________       __________________BLANK_5__________________
#define _________________MOUSE_L3__________________       __________________BLANK_5__________________
#define ____________MOUSE_4_L4_____________               ____________LOWER_4_L4_____________
#define ________________MOUSE_5_L4_________________       ____________MOUSE_4_L4_____________, _______

#define _________________MOUSE_R1__________________       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______
#define _________________MOUSE_R2__________________       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _________________MOUSE_R3__________________       _______, KC_BTN1, KC_BTN2, _______, _______


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


#define ___________________FN_L1___________________       __________________BLANK_5__________________
#define ___________________FN_L2___________________       _______, DT_PRNT, DT_DOWN, DT_UP,   _______
#define ___________________FN_L3___________________       _______, AS_RPT,  AS_DOWN, AS_UP,   _______

#define ___________________FN_R1___________________       KC_F6,   KC_F1,   KC_F2,   KC_F3,   KC_F4
#define ___________________FN_R2___________________       KC_F5,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ___________________FN_R3___________________       _______, KC_F11,  KC_F12,  _______, _______


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
