/*
  Set any config.h overrides for your userspace here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#pragma once

// Tap Hold
#undef TAPPING_TERM
#define TAPPING_TERM 200 // good for moonlander right now, check others and decide whether they need their own
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// Combos
#define COMBO_TERM 70
// Define COMBO_HOLD_TERM such that my tap-only combos don't have to be pressed
// too quickly in order to fire. The value defaults to TAPPING_TERM, but my
// TAPPING_TERM is short so home-row shift works quickly.
#define COMBO_ONLY_FROM_LAYER 0  // layer 0 is _QWERTY. Macro isn't available here
#define COMBO_HOLD_TERM 300
#define COMBO_MUST_TAP_PER_COMBO

// Caps Word
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_MODIFIERS
#define AUTO_SHIFT_TIMEOUT_PER_KEY

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
