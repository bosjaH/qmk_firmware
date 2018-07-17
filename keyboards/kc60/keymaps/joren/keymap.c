
#include QMK_KEYBOARD_H
#include "keymap_common.h"
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
    C_UNLEXT
}

// Fillers to make layering more clear
#define ______ KC_TRNS
#define XXXXXX KC_NO

// Macros
#define M_PIPE  LCTL(LALT(KC_1))     // |
#define M_AT    LCTL(LALT(KC_2))     // @
#define M_HASH  LCTL(LALT(KC_3))     // #
#define M_LCBR  LCTL(LALT(KC_9))     // {
#define M_RCBR  LCTL(LALT(KC_0))     // }
#define M_BSLS  LCTL(LALT(KC_NUBS))  // Backslash
#define M_LBRC  LCTL(LALT(KC_LBRC))  // [
#define M_RBRC  LCTL(LALT(KC_RBRC))  // ]
#define M_LT    KC_NUBS              // <
#define M_GT    LSFT(KC_NUBS)        // >
#define M_WRDL  LCTL(KC_LEFT)        // Word left
#define M_WRDR  LCTL(KC_RIGHT)       // Word right
#define M_TM    LCTL(LSFT(KC_ESC))   // Task manager

// Special
#define S_LEDT  ACTION_BACKLIGHT_TOGGLE()
#define S_LEDI  ACTION_BACKLIGHT_INCREASE()
#define S_LEDD  ACTION_BACKLIGHT_DECREASE()

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer (using ISO backslash)
     * Keymap 1: Default Layer (using ANSI backslash)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspc|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |ExtFN |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |        SpaceFN         |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
   /* Qwerty
    * ,-----------------------------------------------------------------------------------------.
    * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
    * |-----------------------------------------------------------------------------------------|
    * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
    * |-----------------------------------------------------------------------------------------|
    * | Caps/FN1|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------|
    * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Up    | FN2 |
    * |-----------------------------------------------------------------------------------------|
    * | Ctrl  | Gui   | Alt   |               Space             | AltGr | Left  | Down  | Right |
    * `-----------------------------------------------------------------------------------------'
    */
  [L_DEFAULT] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NUBS,  \
        KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
        KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                     LT(L_SPACE_FN, KC_SPC),             KC_NO,    KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL \
    ),
  [L_DEFAULT_ANSI] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
        KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
        KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,    KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                     LT(L_SPACE_FN, KC_SPC),             KC_NO,    KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL \
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
  [L_GAME] = LAYOUT(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   KC_BSPC, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   XXXXXX,   ______,                       KC_SPC,                                 ______,   ______,   ______,TG(L_NUMPAD),______ \
    ),

    /* Overlay: SpaceFN Layer
     * ,-----------------------------------------------------------.
     * |   |  ||  @|  #|   |   |   |   |   |  {|  }|   |   | Delete|
     * |-----------------------------------------------------------|
     * |     |   |   |  [|  ]|Mb4|Mb5|Hom|Up |End|   |  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |CAPS  |   |   |  {|  }|   |PgU|Lef|Dow|Rig|  ´|  `|        |
     * |-----------------------------------------------------------|
     * |        |   |   |Spc|Spc|Spc|PgD|WLe|WRi|   |  ~|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Br: Browser (forward/back)
     */
  [L_SPACE_FN] = LAYOUT(
        ______,   M_PIPE,   M_AT,     M_HASH,   ______,   ______,   ______,   ______,   ______,   M_LCBR,   M_RCBR,   ______,   ______,   KC_DEL, \
        ______,   ______,   ______,   ______,   ______,   KC_BTN4,  KC_BTN5,  KC_HOME,  KC_UP,    KC_END,   ______,   M_LBRC,   M_RBRC,   M_BSLS, \
        KC_CAPS,  ______,   ______,   ______,   ______,   ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ______,   ______,             ______, \
        ______,   ______,   ______,   KC_SPC,   KC_SPC,   KC_SPC,   KC_PGDN,  M_WRDL,   M_WRDR,   ______,   ______,                    ______, \
        ______,   ______,   ______,                       ______,                                 ______,   ______,   ______,   ______,   ______ \
    ),

    /* Overlay: Extended Function Layer
     * ,-----------------------------------------------------------.
     * |  `| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Delete|
     * |-----------------------------------------------------------|
     * |Lock |Mb4|WhU|Mb5|   | Tm|Clc|Hom|Up |End|   |Psc|Pau|  Ins|
     * |-----------------------------------------------------------|
     * |      |WhL|WhD|WhR|   |   |PgU|Lef|Dow|Rig|  '|  \|ConfigFN|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |PgD|   |VDn|VUp|VMt|          |
     * |-----------------------------------------------------------|
     * |    |    |    |         Space          |    |    |NpFN|    |
     * `-----------------------------------------------------------'
     * Mb: Mouse Button
     * Wh: Mouse Wheel
     * Clc: Calculator
     * Tm: Task Manager
     */
  [L_EXTENDED] = LAYOUT(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL, \
        C_LCKEXT, KC_BTN4,  KC_WH_U,  KC_BTN5,   ______,   M_TM,     KC_CALC,  KC_HOME,  KC_UP,    KC_END,   ______,   KC_PSCR,  KC_PAUSE, KC_INS, \
        ______,   KC_WH_L,  KC_WH_D,  KC_WH_R,   ______,   ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ______,   ______,             ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PGDN,  ______,   KC_VOLD,  KC_VOLU,  KC_MUTE,                      ______, \
        ______,   ______,   ______,                       ______,                                 ______,   ______,   ______,TG(L_NUMPAD),______ \
  ),
    // KEYMAP_ANSI(
    //     GRV ,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, DEL, \
    //     FN8 ,BTN4,WH_U,BTN5,______,   FN23,CALC,HOME,  UP, END,______,   PSCR,PAUS, INS, \
    //     ______,   WH_L,WH_D,WH_R,______,   ______,   PGUP,LEFT,DOWN,RGHT,QUOT,BSLS,      FN7, \
    //     ______,   ______,   ______,   ______,   ______,   ______,   PGDN,______,   VOLD,VOLU,MUTE,          ______,    \
    //     ______,   ______,   ______,             SPC,                     ______,    FN3, FN4,______),

    /* Overlay: Extended Locking Layer
     * ,-----------------------------------------------------------.
     * |Esc|   |   |   |   |   |   |   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |Unlock|   |   |   |   |   |   |   |   |   |   |   |   Enter|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |Gui |App |    |
     * `-----------------------------------------------------------'
     */
  [L_EXTENDED_LOCK] = LAYOUT(
        KC_ESC,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,    \
        KC_TAB,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,    \
        C_UNLEXT, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             KC_ENT, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______,    \
        ______,   ______,   ______,                        ______,                                ______,   ______,   KC_RGUI,  KC_APP,   ______ \
  ),
    // KEYMAP_ANSI(
    //     ESC ,______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,    \
    //     TAB ,______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,    \
    //     FN9 ,______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,         ENT, \
    //     ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,    \
    //     ______,   ______,   ______,             ______,                       ______,   RGUI, APP,______),

    /* Overlay: Numpad
     * ,-----------------------------------------------------------.
     * |   |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  +|Backspc|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |  -|  7|  8|  9|  /|   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |  +|  4|  5|  6|  *|   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  .|  1|  2|  3|   |     Enter|
     * |-----------------------------------------------------------|
     * |    |    |    |                       0|   .|    |NmLc|Exit|
     * `-----------------------------------------------------------'
     * Mb: Mouse Button
     * Mw: Mouse Wheel
     * Mc: Mouse Cursor
     */
  [L_NUMPAD] = LAYOUT(
        ______,   KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_PMNS,  KC_PPLS,  KC_BSPC, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PMNS,  KC_P7,    KC_P8,    KC_P9,    KC_PSLS,  ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PPLS,  KC_P4,    KC_P5,    KC_P6,    KC_PAST,  ______,             KC_PENT, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PDOT,  KC_P1,    KC_P2,    KC_P3,    ______,                       KC_PENT, \
        ______,   ______,   ______,                       KC_P0,                                  KC_PDOT,  ______,   ______,   ______,   KC_NLCK \
  ),
    // KEYMAP_ANSI(
    //     ______,   KP_1,KP_2,KP_3,KP_4,KP_5,KP_6,KP_7,KP_8,KP_9,KP_0,PMNS,PPLS,BSPC, \
    //     ______,   ______,   ______,   ______,   ______,   ______,   PMNS,KP_7,KP_8,KP_9,PSLS,______,   ______,   ______,    \
    //     ______,   ______,   ______,   ______,   ______,   ______,   PPLS,KP_4,KP_5,KP_6,PAST,______,        PENT, \
    //     ______,   ______,   ______,   ______,   ______,   ______,   PDOT,KP_1,KP_2,KP_3,______,             PENT, \
    //     ______,   ______,   ______,             KP_0,                    PDOT,______,   NLCK, FN4),

    /* Overlay: Layout selection layer
     * ,-----------------------------------------------------------.
     * |   |Gm |   |   |   |   |   |   |   |   |   |ISO|ANS|BootLdr|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |ConfigFN|
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Gm: Game
     */
  [L_CONFIG] = LAYOUT(
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   ______,   ______,                       ______,                                 ______,   ______,   ______,   ______,   ______ \
  )
};

uint32_t layer_state_set_user(uint32_t state) {
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_LCKEXT:
      if (record->event.pressed) {
        layer_on(L_EXTENDED_LOCK);
      }
      return false;
    case C_UNLEXT:
      // Play a tone when enter is pressed
      if (record->event.release) {
        layer_off(L_EXTENDED_LOCK);
        layer_off(L_EXTENDED);
      }
      return false; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}
