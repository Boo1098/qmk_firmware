BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = yes
AUDIO_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
UNICODEMAP_ENABLE = yes
LEADER_ENABLE = yes
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no

# reduce file size
EXTRAFLAGS += -flto

# Vim keyboard rules
include $(KEYBOARD_PATH_1)/keymaps/$(KEYMAP)/qmk-vim/rules.mk
   
