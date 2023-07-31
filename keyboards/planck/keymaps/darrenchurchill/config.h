#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 225

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 40

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 90

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80

#define FIRMWARE_VERSION u8"65M0L/v7YAL"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT

#define RGB_MATRIX_STARTUP_SPD 60

