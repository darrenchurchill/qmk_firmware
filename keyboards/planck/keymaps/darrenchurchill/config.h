#pragma once

#ifdef AUDIO_ENABLE
// TODO: pick a startup song when you have free time
// see quantum/audio/song_list.h
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define PLANCK_EZ_LED_LOWER 1 // Lower
#define PLANCK_EZ_LED_RAISE 2 // Raise
#define PLANCK_EZ_LED_ADJUST 4 // KB_LED (my version of "adjust")

#define USB_SUSPEND_WAKEUP_DELAY 0

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_16BIT
