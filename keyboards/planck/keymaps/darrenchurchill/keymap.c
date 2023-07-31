#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRV
#define ES_GRTR_MAC LSFT(KC_GRV)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRV
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)


enum tap_dance_codes {
  DANCE_0,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
  _LAYER7,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_Q,           KC_W,           KC_E,         KC_R,         KC_T,  KC_GRV,  KC_MINS, KC_Y,   KC_U,         KC_I,            KC_O,           KC_P,
    KC_A,           KC_S,           KC_D,         KC_F,         KC_G,  KC_DQUO, KC_QUOT, KC_H,   KC_J,         KC_K,            KC_L,           KC_SCLN,
    LCTL_T(KC_Z),   LALT_T(KC_X),   LSFT_T(KC_C), LGUI_T(KC_V), KC_B,  KC_HYPR, KC_MEH,  KC_N,   RGUI_T(KC_M), RSFT_T(KC_COMM), RALT_T(KC_DOT), RCTL_T(KC_SLASH),
    LCTL_T(KC_GRV), LALT_T(KC_ESC), KC_TAB,       KC_LGUI,      LOWER, KC_BSPC, KC_NO,   KC_SPC, RAISE,        KC_ENTER,        TD(DANCE_0),    KC_MUTE
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,     KC_8,     KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_UNDS, KC_LBRC,  KC_RBRC,  KC_LPRN, KC_RPRN,
    KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, _______, _______, KC_PLUS, KC_MINUS, KC_EQUAL, KC_LCBR, KC_RCBR,
    _______, TO(0),   _______, _______, _______, _______, KC_NO,   _______, MO(4),    _______,  KC_GRV,  _______
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_MUTE, CW_TOGG, KC_VOLU, _______, _______, TO(0),   _______, KC_HOME, KC_PGDN,       KC_PGUP,       KC_END,        KC_MPLY,
    KC_CAPS, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN,       KC_UP,         KC_RIGHT,      _______,
    _______, _______, _______, _______, _______, _______, _______, _______, SGUI(KC_LBRC), SGUI(KC_RBRC), LCTL(KC_PGUP), LCTL(KC_PGDN),
    _______, TO(0),   _______, _______, MO(6),   _______, KC_NO,   _______, _______,       _______,       _______,       _______
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_NO,   _______, _______, _______, _______, _______
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    _______, _______, _______, _______,    _______,    _______, TO(0),   KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT,    _______,
    _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______,
    _______, _______, _______, _______,    _______,    _______, _______, _______,       _______,       _______,     _______,        _______,
    _______, TO(0),   _______, _______,    _______,    _______, KC_NO,   _______,       _______,       _______,     _______,        _______
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    RGB_TOG, _______, _______, _______, TOGGLE_LAYER_COLOR, _______, _______, _______, RGB_HUD, RGB_HUI, _______, RGB_MODE_PLAIN,
    _______, RGB_MOD, _______, _______, _______,            _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, _______, _______, _______,            _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______,
    QK_RBT,  TO(0),   _______, _______, _______,            _______, KC_NO,   _______, _______, _______, RGB_SPD, RGB_SPI
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   TO(0),   TO(0),   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, TO(0),   _______, _______, _______, _______, KC_NO,   _______, _______, _______, _______, _______
  ),

  [_LAYER7] = LAYOUT_planck_grid(
    _______, _______, _______, TO(2),   _______, TO(0),   TO(0),   _______, _______, _______, _______, _______,
    _______, _______, _______, TO(6),   _______, _______, _______, _______, _______, TO(5),   TO(1),   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, TO(4),   _______, _______, _______,
    _______, TO(0),   _______, _______, _______, _______, KC_NO,   _______, _______, _______, _______, _______
  ),

};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {196,219,209}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {151,140,149}, {151,140,149}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {3,252,255}, {218,219,209}, {35,252,255}, {139,218,208}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,218,208}, {35,252,255}, {218,219,209}, {3,252,255},
        {3,252,255}, {218,219,209}, {0,0,255}, {139,218,208}, {53,255,255}, {0,245,245}, {0,0,255}, {53,255,255}, {0,0,255}, {53,255,255}, {3,252,255}
    },

    [1] = {
        {89,243,150}, {89,243,150}, {89,243,150}, {89,243,150}, {89,243,150}, {0,0,0}, {0,0,0}, {89,243,150}, {89,243,150}, {89,243,150}, {89,243,150}, {89,243,150},
        {196,219,209}, {196,219,209}, {196,219,209}, {196,219,209}, {196,219,209}, {0,0,0}, {0,0,0}, {196,219,209}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255},
        {196,219,209}, {196,219,209}, {196,219,209}, {196,219,209}, {196,219,209}, {0,0,0}, {0,0,0}, {196,219,209}, {196,219,209}, {196,219,209}, {152,255,255}, {152,255,255},
        {0,0,0}, {16,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {16,252,255}, {0,0,0}, {196,219,209}, {0,0,0}
    },

    [2] = {
        {0,255,255}, {41,255,255}, {91,243,139}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {69,253,143}, {69,253,143}, {69,253,143}, {69,253,143}, {148,245,230},
        {41,255,255}, {200,218,204}, {91,243,139}, {200,218,204}, {0,0,0}, {0,0,0}, {0,245,245}, {163,253,255}, {163,253,255}, {163,253,255}, {163,253,255}, {0,0,0},
        {3,252,255}, {218,219,209}, {35,252,255}, {139,218,208}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {164,218,204}, {164,218,204}, {11,219,233}, {11,219,233},
        {0,0,0}, {16,252,255}, {0,0,0}, {0,0,0}, {16,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    },

    [4] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {37,246,235}, {37,246,235}, {37,246,235}, {37,246,235}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {37,246,235}, {37,246,235}, {0,0,0}, {0,0,0}, {139,218,208}, {139,218,208}, {139,218,208}, {139,218,208}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {16,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    },

    [5] = {
        {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {139,218,208}, {139,218,208}, {0,0,0}, {0,255,255},
        {0,0,0}, {187,242,221}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {77,211,255}, {77,211,255}, {0,0,0}, {0,0,0},
        {77,211,255}, {16,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {187,242,221}, {187,242,221}
    },

    [6] = {
        {53,255,255}, {53,255,255}, {53,255,255}, {53,255,255}, {53,255,255}, {0,0,0}, {0,0,0}, {53,255,255}, {53,255,255}, {53,255,255}, {53,255,255}, {53,255,255},
        {53,255,255}, {53,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {16,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    },

    [7] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {77,211,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {77,211,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {77,211,255}, {77,211,255}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {77,211,255}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {16,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
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
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint16_t layer_state_set_user(uint16_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: layer_move(7); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
};
