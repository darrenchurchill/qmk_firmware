#pragma once
#include QMK_KEYBOARD_H


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
  UKC_OS_PREV_SPACE,
  UKC_OS_NEXT_SPACE,
  UKC_SG_ARRW,
  UKC_DB_ARRW,
  UKC_LWR_SLSH,
  UKC_REP,  // Repeat Key
  UKC_AREP,  // Alt Repeat Key
  KEYMAP_SAFE_RANGE  //use "KEYMAP_SAFE_RANGE" for keymap specific codes
};


/*
  Layer Macros
*/
#define QNM_T(KC) LT(_QWERTY_NO_MODS, KC)
#define LWR LT(_LOWER, KC_TAB)
#define LWR_T(KC) LT(_LOWER, KC)
#define RSE OSL(_RAISE)
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
#define OS_PSPC UKC_OS_PREV_SPACE
#define OS_NSPC UKC_OS_NEXT_SPACE

// QWERTY Layer Keys: QKC -> "Qwerty KeyCode"
// Left Hand
#define QKC_Q KC_Q
#define QKC_W KC_W
#define QKC_E KC_E
#define QKC_R KC_R
#define QKC_T KC_T
#define QKC_A LWR_T(KC_A)
#define QKC_S LALT_T(KC_S)
#define QKC_D LSFT_T(KC_D)
#define QKC_F LCTL_T(KC_F)
#define QKC_G KC_G
#define QKC_Z FN_T(KC_Z)
#define QKC_X EXT_T(KC_X)
#define QKC_C MS_T(KC_C)
#define QKC_V LGUI_T(KC_V)
#define QKC_B KC_B
// Right Hand
#define QKC_Y KC_Y
#define QKC_U KC_U
#define QKC_I KC_I
#define QKC_O KC_O
#define QKC_P KC_P
#define QKC_H KC_H
#define QKC_J RCTL_T(KC_J)
#define QKC_K LSFT_T(KC_K)
#define QKC_L RALT_T(KC_L)
#define QKC_SC LWR_T(KC_SCLN)
#define QKC_N KC_N
#define QKC_M RGUI_T(KC_M)
#define QKC_DOT KC_DOT
#define QKC_COM KC_COMM
#define QKC_SL KC_SLSH

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
#define BKC_M RSE
#define BKC_COM KC_ENT
#define BKC_DOT KC_QUOT
#define BKC_SL KC_DQUO

// LOWER Layer Keys: LKC -> "Lower KeyCode"
// Mostly inspired by:
// https://getreuer.info/posts/keyboards/symbol-layer/index.html
// https://github.com/getreuer/qmk-keymap
// Left Hand
/*
   7    8    9    0    5 (Available w/ custom shift keys on top row)
   @    <    >    "    `
   !    -    +    =    #
  ___   /    *    ^    \
*/
#define LKC_Q KC_AT
#define LKC_W KC_LABK
#define LKC_E KC_RABK
#define LKC_R KC_DQUO
#define LKC_T KC_GRV
#define LKC_A KC_EXLM
#define LKC_S KC_MINS
#define LKC_D LSFT_T(KC_PLUS)
#define LKC_F KC_EQUAL
#define LKC_G KC_HASH
#define LKC_Z _______
#define LKC_X UKC_LWR_SLSH
#define LKC_C KC_ASTR
#define LKC_V KC_CIRC
#define LKC_B KC_BSLS

// Right Hand
/*
   6    1    2    3    4 (Available w/ custom shift keys on top row)
   &    '    [    ]    %
   |    _    (    )    ?
   ~    $    {    }   ___
*/
#define LKC_Y KC_AMPR
#define LKC_U KC_QUOT
#define LKC_I KC_LBRC
#define LKC_O KC_RBRC
#define LKC_P KC_PERC
#define LKC_H KC_PIPE
#define LKC_J KC_UNDS
#define LKC_K LSFT_T(KC_LPRN)
#define LKC_L KC_RPRN
#define LKC_SC KC_QUES
#define LKC_N KC_TILD
#define LKC_M KC_DLR
#define LKC_COM KC_LCBR
#define LKC_DOT KC_RCBR
#define LKC_SL  _______

/*
  Keycode wrappers
  https://docs.qmk.fm/#/keycodes
*/
#define _________________QWERTY_L1_________________       QKC_Q,   QKC_W,   QKC_E,   QKC_R,   QKC_T
#define _________________QWERTY_L2_________________       QKC_A,   QKC_S,   QKC_D,   QKC_F,   QKC_G
#define _________________QWERTY_L3_________________       QKC_Z,   QKC_X,   QKC_C,   QKC_V,   QKC_B

#define _________________QWERTY_R1_________________       QKC_Y,   QKC_U,   QKC_I,   QKC_O,   QKC_P
#define _________________QWERTY_R2_________________       QKC_H,   QKC_J,   QKC_K,   QKC_L,   QKC_SC
#define _________________QWERTY_R3_________________       QKC_N,   QKC_M,   QKC_COM, QKC_DOT, QKC_SL

#define _____________QWERTY_NO_MODS_R2_____________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN

#define _____________BASE_4_L4_____________               BKC_Z,   BKC_X,   BKC_C,   BKC_V
#define _________________BASE_5_L4_________________       _____________BASE_4_L4_____________, BKC_B

#define _____________BASE_4_R4_____________                        BKC_M,   BKC_COM, BKC_DOT, BKC_SL
#define _________________BASE_5_R4_________________       BKC_N, _____________BASE_4_R4_____________


#define ________________NUMBER_LEFT________________       KC_7,    KC_8,    KC_9,    KC_0,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_1,    KC_2,    KC_3,    KC_4

#define ______________BLANK_4______________               _______, _______, _______, _______
#define __________________BLANK_5__________________       _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________       LKC_Q,   LKC_W,   LKC_E,   LKC_R,   LKC_T
#define _________________LOWER_L2__________________       LKC_A,   LKC_S,   LKC_D,   LKC_F,   LKC_G
#define _________________LOWER_L3__________________       LKC_Z,   LKC_X,   LKC_C,   LKC_V,   LKC_B
#define ____________LOWER_4_L4_____________               _______, UKC_BASE, _______, _______
#define ________________LOWER_5_L4_________________       ____________LOWER_4_L4_____________, _______

#define _________________LOWER_R1__________________       LKC_Y,   LKC_U,   LKC_I,    LKC_O,   LKC_P
#define _________________LOWER_R2__________________       LKC_H,   LKC_J,   LKC_K,    LKC_L,   LKC_SC
#define _________________LOWER_R3__________________       LKC_N,   LKC_M,   LKC_COM,  LKC_DOT, LKC_SL
#define ____________LOWER_4_R4_____________                        _______, _______, _______, _______
#define ________________LOWER_5_R4_________________       _______, ____________LOWER_4_R4_____________


#define _________________RAISE_L1__________________       __________________BLANK_5__________________
#define _________________RAISE_L2__________________       __________________BLANK_5__________________
#define _________________RAISE_L3__________________       _______, _______, _______, _______, _______
#define ____________RAISE_4_L4_____________               ____________LOWER_4_L4_____________
#define ________________RAISE_5_L4_________________       ____________RAISE_4_L4_____________, _______

#define _________________RAISE_R1__________________       KC_HOME, KC_PGDN, KC_PGUP, KC_END,   LGUI(KC_GRV)
#define _________________RAISE_R2__________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, LCTL(KC_GRV)
#define _________________RAISE_R3__________________       _______, OS_PTAB, OS_NTAB, OS_PSPC,  OS_NSPC
#define ____________RAISE_4_R4_____________                        ______________BLANK_4______________
#define ________________RAISE_5_R4_________________       _______, ____________RAISE_4_R4_____________


#define _________________EXTEND_L1_________________       __________________BLANK_5__________________
#define _________________EXTEND_L2_________________       __________________BLANK_5__________________
#define _________________EXTEND_L3_________________       __________________BLANK_5__________________
#define ____________EXTEND_4_L4____________               ____________LOWER_4_L4_____________
#define ________________EXTEND_5_L4________________       ____________EXTEND_4_L4____________, _______

#define _________________EXTEND_R1_________________       KC_MPRV, VOL_DN,  VOL_UP,  KC_MNXT, KC_MPLY
#define _________________EXTEND_R2_________________       KC_BSPC, _______, _______, KC_DEL,  UKC_REP
#define _________________EXTEND_R3_________________       _______, KC_MUTE, UKC_AREP, UKC_REP, _______
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
#define ___________KB_LED_4_L4_____________               _______, UKC_BASE, _______, _______
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
