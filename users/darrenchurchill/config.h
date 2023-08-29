/*
  Set any config.h overrides for your userspace here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#pragma once

// Tap Hold
#undef TAPPING_TERM
#define TAPPING_TERM 165
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// Combos
#define COMBO_TERM 70

// Caps Word
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_MODIFIERS

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
