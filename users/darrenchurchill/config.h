/*
  Set any config.h overrides for your userspace here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#pragma once

// TODO: figure out which of these is/may be fixing the input problem at boot
// login on MacOS
#define TAP_CODE_DELAY 10
#define TAP_HOLD_CAPS_DELAY 200

// Tap Hold
#undef TAPPING_TERM
// NOTE: If TAPPING_TERM is too short, rolling over home row keys like I,E,N can
// allow you to enter the LOWER layer without intending to. I imagine this has
// to do with the when the TAPPING_TERM timer is reset.
#define TAPPING_TERM 240
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


// Leader Key
#define LEADER_NO_TIMEOUT // Disable the timeout for the leader key itself
#define LEADER_TIMEOUT 500 // ms, the timeout for the remaining key sequence
#define LEADER_PER_KEY_TIMING // Reset the timer after each keypress

// Select Word
#define SELECT_WORD_TIMEOUT 2000 // ms; When idle, clear state after this duration

// One Shot Keys
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 500

// Combos
#define COMBO_TERM 70
#define COMBO_TERM_FAST 30 // My own personal macro definition, not in QMK
#define COMBO_TERM_PER_COMBO
// Define COMBO_HOLD_TERM such that my tap-only combos don't have to be pressed
// too quickly in order to fire. The value defaults to TAPPING_TERM, but my
// TAPPING_TERM is short so home-row shift works quickly.
#define COMBO_ONLY_FROM_LAYER 1  // layer 1 is _QWERTY. Macro isn't available here
#define COMBO_HOLD_TERM 300
#define COMBO_MUST_TAP_PER_COMBO

// Caps Word, from features/casemodes.[h|c]
#define DEFAULT_CAMEL_CASE_ON_SPACE
#define CAPSWORD_USE_SHIFT

// Mouse Keys
#define MOUSEKEY_INTERVAL           20
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_TIME_TO_MAX        60
#define MOUSEKEY_MAX_SPEED          7
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 40
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 90
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80

// RGB Matrix
#ifdef RGB_MATRIX_ENABLE
// TODO: figure out if RGB_DISABLE_TIMEOUT applies to anything on your boards
#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000
#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 5 * 60 * 1000 // min * sec/min * ms/sec
#define RGB_MATRIX_STARTUP_SPD 60
#endif // RGB_MATRIX_ENABLE
