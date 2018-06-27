
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FNCAPS 1
#define _FNRIGHTSHIFT 2

// Fillers to make layering more clear
#define ______ KC_TRNS
#define XXXXXXX KC_NO

// Func macro definitions.
#define S_LED   FUNC(0)
#define S_LEDI  FUNC(1)
#define S_LEDD  FUNC(2)

// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_BACKLIGHT_TOGGLE(),
	[1] = ACTION_BACKLIGHT_INCREASE(),
	[2] = ACTION_BACKLIGHT_DECREASE()
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Basic QWERTY */
      KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
      KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
      KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_RSFT,  \
      KC_LCTL,  KC_LALT,  KC_LGUI,                     KC_SPC,                             KC_NO,    KC_RGUI,  KC_RALT,  KC_RCTL,  RESET \
      ),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  return MACRO_NONE;
};
