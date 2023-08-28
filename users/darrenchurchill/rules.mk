# https://docs.qmk.fm/#/feature_userspace
SRC += $(USER_PATH)/darrenchurchill.c

# Set any rules.mk overrides for your specific user here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
TAP_DANCE_ENABLE = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = yes
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes

# https://github.com/qmk/qmk_firmware/issues/21137
# Using INTROSPECTION_KEYMAP_C isn't recommended, but it works for this purpose
ifdef COMBO_ENABLE
	INTROSPECTION_KEYMAP_C += $(USER_PATH)/combos.c
endif
