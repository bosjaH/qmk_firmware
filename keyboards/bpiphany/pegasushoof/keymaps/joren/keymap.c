#include QMK_KEYBOARD_H
#include "action_code.h"
#include "action_layer.h"

// Layers
enum layer_id {
    L_DEFAULT,
    L_DEFAULT_ANSI,
    L_GAME,
    L_SPACE_FN,
    L_EXTENDED,
    L_EXTENDED_LOCK,
    L_NUMPAD,
    L_CONFIG
};

// Keycodes
enum custom_keycodes {
    C_LCKEXT = SAFE_RANGE,
    C_CLSEXT,
    C_AACUTE,
    C_AGRAVE,
    C_TILDE
};

// Fillers to make layering clearer
#define ______ KC_TRNS
#define XXXXXX KC_NO

// Macros
#define M_PIPE  RALT(KC_1)           // |
#define M_AT    RALT(KC_2)           // @
#define M_HASH  RALT(KC_3)           // #
#define M_LCBR  RALT(KC_9)           // {
#define M_RCBR  RALT(KC_0)           // }
#define M_BSLS  RALT(KC_NUBS)        // Backslash
#define M_LBRC  RALT(KC_LBRC)        // [
#define M_RBRC  RALT(KC_RBRC)        // ]
#define M_LT    KC_NUBS              // <
#define M_GT    LSFT(KC_NUBS)        // >
#define M_WRDL  LCTL(KC_LEFT)        // Word left
#define M_WRDR  LCTL(KC_RIGHT)       // Word right
#define M_TM    LCTL(LSFT(KC_ESC))   // Task manager

// Layer switching
#define FN_SPACE_FN LT(L_SPACE_FN, KC_SPC)
#define FN_EXT      MO(L_EXTENDED)
#define FN_NUM      TG(L_NUMPAD)
#define FN_GAME     TG(L_GAME)
#define FN_CONFIG   MO(L_CONFIG)
#define DL_ISO      DF(L_DEFAULT)
#define DL_ANSI     DF(L_DEFAULT_ANSI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Layer 0: Standard ISO layer */
	[L_DEFAULT] = LAYOUT_tkl_ansi( \
		KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS, \
		KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NUBS,  KC_DEL,   KC_END,   KC_PGDN, \
        FN_EXT,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      KC_RSFT,            KC_UP,             \
        KC_LCTL,  KC_LGUI,  KC_LALT,                             FN_SPACE_FN,                               KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT  \
	),
	[L_DEFAULT_ANSI] = LAYOUT_tkl_ansi( \
		KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_PAUS, \
		KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN, \
        FN_EXT,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                                \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      KC_RSFT,            KC_UP,             \
        KC_LCTL,  KC_LGUI,  KC_LALT,                             FN_SPACE_FN,                               KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT  \
	),
	/* Overlay: Game Layer (disable left win and SpaceFN)
     * ,-----------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |Backspc|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    | NO |    |         Space          |    |    |NpFN|    |
     * `-----------------------------------------------------------'
     */
	[L_GAME] = LAYOUT_tkl_ansi( \
		______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   KC_BSPC,  ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,                                \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______,             ______,            \
		______,   XXXXXX,   ______,                                 KC_SPC,                                 ______,   ______,   FN_NUM,   ______,   ______,   ______,   ______   \
	),
	[L_SPACE_FN] = LAYOUT_tkl_ansi( \
		______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   M_PIPE,   M_AT,     M_HASH,   ______,   ______,   ______,   ______,   ______,   M_LCBR,   M_RCBR,   ______,   ______,   KC_DEL,   ______,   ______,   ______,  \
		______,   ______,   ______,   KC_WH_U,  ______,   KC_BTN4,  KC_BTN5,  KC_HOME,  KC_UP,    KC_END,   ______,   M_LBRC,   M_RBRC,   M_BSLS,   ______,   ______,   ______,  \
		KC_CAPS,  ______,   KC_WH_L,  KC_WH_D,  KC_WH_R,  ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, C_AACUTE, C_AGRAVE,           ______,                                \
		______,   ______,   ______,   KC_SPC,   KC_SPC,   KC_SPC,   KC_PGDN,  M_WRDL,   M_WRDR,   ______,   C_TILDE,                      ______,             ______,            \
		______,   ______,   ______,                                 ______,                                 ______,   ______,   ______,   ______,   ______,   ______,   ______   \
	),
	[L_EXTENDED] = LAYOUT_tkl_ansi( \
		______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		C_LCKEXT, KC_BTN4,  KC_WH_U,  KC_BTN5,  ______,   M_TM,     KC_CALC,  KC_HOME,  KC_UP,    KC_END,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   KC_WH_L,  KC_WH_D,  KC_WH_R,  ______,   ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ______,   ______,          FN_CONFIG,                                \
		______,   ______,   ______,   ______,   ______,   ______,   KC_PGDN,  ______,   KC_VOLD,  KC_VOLU,  KC_MUTE,                      ______,             ______,            \
		______,   ______,   ______,                                 ______,                                 ______,   ______,   FN_NUM,   ______,   ______,   ______,   ______   \
	),
	[L_EXTENDED_LOCK] = LAYOUT_tkl_ansi( \
		______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		KC_TAB,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		C_CLSEXT, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             KC_ENT,                                \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______,             ______,            \
		______,   ______,   ______,                                 ______,                                 ______,   KC_RGUI,  KC_APP,   ______,   ______,   ______,   ______   \
	),
	[L_NUMPAD] = LAYOUT_tkl_ansi( \
		______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_PMNS,  KC_PPLS,  KC_BSPC,  ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   KC_PMNS,  KC_P7,    KC_P8,    KC_P9,    KC_PSLS,  ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   KC_PPLS,  KC_P4,    KC_P5,    KC_P6,    KC_PAST,  ______,             KC_PENT,                               \
		______,   ______,   ______,   ______,   ______,   ______,   KC_PDOT,  KC_P1,    KC_P2,    KC_P3,    ______,                       KC_PENT,            ______,            \
		______,   ______,   ______,                                 KC_P0,                                  KC_PDOT,  ______,   ______,   KC_NLCK,  ______,   ______,   ______   \
	),
    [L_CONFIG] = LAYOUT_tkl_ansi( \
		______,             ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   DL_ISO,   DL_ANSI,  ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   RESET,    ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
		______,   ______,   ______,   ______,   ______,   FN_GAME,  ______,   ______,   ______,   ______,   ______,   ______,          FN_CONFIG,                                \
		______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______,             ______,            \
		______,   ______,   ______,                                 ______,                                 ______,   ______,   ______,   ______,   ______,   ______,   ______   \
	)
};

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		ph_caps_led_on();
	} else {
		ph_caps_led_off();
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		ph_sclk_led_on();
	} else {
		ph_sclk_led_off();
	}
}
