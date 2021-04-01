
#include QMK_KEYBOARD_H
#include "action_code.h"
#include "action_layer.h"

// Layers
enum layer_id {
    L_DEFAULT,
    L_DEFAULT_ANSI,
    L_DEFAULT_F_ROW,
    L_GAME,
    L_SPACE_FN,
    L_NAVIGATION,
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
#define M_VDL   LCTL(LGUI(KC_LEFT))  // Previous virtual desktop
#define M_VDR   LCTL(LGUI(KC_RIGHT)) // Next virtual desktop
#define M_TM    LCTL(LSFT(KC_ESC))   // Task manager
#define M_EUR   RALT(KC_E)           // Euro sign
#define M_1     LSFT(KC_1)           // 1
#define M_2     LSFT(KC_2)           // 2
#define M_3     LSFT(KC_3)           // 3
#define M_4     LSFT(KC_4)           // 4
#define M_5     LSFT(KC_5)           // 5
#define M_6     LSFT(KC_6)           // 6
#define M_7     LSFT(KC_7)           // 7
#define M_8     LSFT(KC_8)           // 8
#define M_9     LSFT(KC_9)           // 9
#define M_0     LSFT(KC_0)           // 0

// Layer switching
#define FN_SPACE_FN LT(L_SPACE_FN, KC_SPC)
#define FN_NAV_D    LT(L_NAVIGATION, KC_D)
#define FN_NAV_F    LT(L_NAVIGATION, KC_F)
#define FN_NAV_SC   LT(L_NAVIGATION, KC_SCLN)
#define FN_EXT      LT(L_EXTENDED, KC_BSPC)
#define FN_NUM      TG(L_NUMPAD)
#define FN_GAME     TG(L_GAME)
#define FN_CONFIG   MO(L_CONFIG)
#define DL_ISO      DF(L_DEFAULT)
#define DL_ANSI     DF(L_DEFAULT_ANSI)
#define DL_FROW     DF(L_DEFAULT_F_ROW)


// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer (using ISO backslash)
     * Keymap 1: Default Layer (using ANSI backslash)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspc|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| [ | ] |    \|
     * |-----------------------------------------------------------|
     * |ExtFN |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |        SpaceFN         |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
  [L_DEFAULT] = LAYOUT_60_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NUBS,  \
        FN_EXT,   KC_A,     KC_S,     FN_NAV_D,FN_NAV_F, KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     FN_NAV_SC,KC_QUOT,            KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM, KC_DOT,   KC_SLSH,                      KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                            FN_SPACE_FN,                           KC_RALT,  KC_RGUI,  SFT_T(KC_APP),KC_RCTL   \
    ),
  [L_DEFAULT_ANSI] = LAYOUT_60_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
        FN_EXT,   KC_A,     KC_S,     FN_NAV_D,FN_NAV_F, KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     FN_NAV_SC,KC_QUOT,            KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM, KC_DOT,   KC_SLSH,                      KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                            FN_SPACE_FN,                           KC_RALT,  KC_RGUI,  SFT_T(KC_APP),KC_RCTL   \
    ),

    /* Keymap 2: Fixed F-Row Layer (using ISO backslash)
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Backspc|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| [ |  ]|    \|
     * |-----------------------------------------------------------|
     * |ExtFN |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|     Shift|
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |        SpaceFN         |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
  [L_DEFAULT_F_ROW] = LAYOUT_60_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,   KC_F8, KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC,  \
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NUBS,  \
        FN_EXT,   KC_A,     KC_S,     FN_NAV_D,FN_NAV_F, KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     FN_NAV_SC,KC_QUOT,            KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM, KC_DOT,   KC_SLSH,                      KC_RSFT,  \
        KC_LCTL,  KC_LGUI,  KC_LALT,                            FN_SPACE_FN,                           KC_RALT,  KC_RGUI,  SFT_T(KC_APP),KC_RCTL   \
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
  [L_GAME] = LAYOUT_60_ansi(
        ______,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,  \
        ______,   ______,   ______,   KC_D,     KC_F,     ______,   ______,   ______,   ______,   ______,   ______,   ______,             ______,  \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   XXXXXX,   ______,                       KC_SPC,                                           ______,   ______,   FN_NUM,   ______   \
    ),

    /* Overlay: SpaceFN Layer
     * ,-----------------------------------------------------------.
     * |   | | | @ | # |   |   |   |   |   | { |  }| - | = | Delete|
     * |-----------------------------------------------------------|
     * |     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | [ | ] |    \|
     * |-----------------------------------------------------------|
     * |CAPS  |   | [ | { | ( | " | ' | ) | } | ] |  ´|  `|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |  ~|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Br: Browser (forward/back)
     */
  [L_SPACE_FN] = LAYOUT_60_ansi(
        ______,   M_PIPE,   M_AT,     M_HASH,   ______,   ______,   ______,   ______,   ______,   M_LCBR,   M_RCBR,   KC_MINS,  KC_EQL,   KC_DEL, \
        ______,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     M_LBRC,   M_RBRC,   M_BSLS, \
        ______,   S(KC_EQL),M_LBRC,   M_LCBR,   KC_5,     KC_3,     KC_4,     KC_MINS,  M_RCBR,  M_RBRC,    C_AACUTE, C_AGRAVE,           ______, \
        ______,   ______,   C(KC_X),  C(KC_C),  C(KC_V),  ______,   ______,   ______,   ______,   ______,   C_TILDE,                      ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   ______,   ______ \
    ),

    /* Overlay: Navigation Layer
     * ,-----------------------------------------------------------.
     * |   |  ||  @|  #|   |   |   |   |   | { | } |   |   | Delete|
     * |-----------------------------------------------------------|
     * |     |MWu|Mb1|MUp|Mb2|Mb4|Mb5|Hom|Up |End|   |  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |CAPS  |MWd|MLt|MDn|MRt|Mb3|PgU|Lef|Dow|Rig|  ´|  `|        |
     * |-----------------------------------------------------------|
     * |        |   |   |Spc|Spc|Spc|PgD|WLe|WRi|   |  ~|          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     * Br: Browser (forward/back)
     */
  [L_NAVIGATION] = LAYOUT_60_ansi(
        ______,   M_PIPE,   M_AT,     M_HASH,   ______,   ______,   ______,   ______,   ______,   M_LCBR,   M_RCBR,   KC_MINS,  KC_EQL,   KC_DEL, \
        ______,   KC_WH_U,  ______,   ______,   ______,   KC_BTN4,  KC_BTN5,  KC_HOME,  KC_UP,    KC_END,   ______,   M_LBRC,   M_RBRC,   M_BSLS, \
        KC_CAPS,  KC_WH_D,  ______,   ______,   ______,   KC_BTN3,  KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, C_AACUTE, C_AGRAVE,           ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PGDN,  M_WRDL,   M_WRDR,   ______,   C_TILDE,                      ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   ______,   ______ \
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
  [L_EXTENDED] = LAYOUT_60_ansi(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL, \
        C_LCKEXT, KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,   M_TM,     KC_CALC,  KC_HOME,  KC_UP,    KC_END,   ______,   KC_PSCR,  KC_PAUSE, KC_INS, \
        ______,   KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,   ______,   KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RIGHT, ______,   KC_NUHS,         FN_CONFIG, \
        ______,   KC_WH_L,  KC_WH_R,  ______,   ______,   ______,   KC_PGDN,  ______,   KC_VOLD,  KC_VOLU,  KC_MUTE,                      ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   FN_NUM,   ______  \
  ),

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
  [L_EXTENDED_LOCK] = LAYOUT_60_ansi(
        KC_ESC,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        KC_TAB,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______, \
        C_CLSEXT, ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,             KC_ENT, \
        ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   ______,   ______,                       ______,                                           ______,   KC_RGUI,  KC_APP,   ______  \
  ),

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
     * |    |    |    |                       0|   .|    |Exit|NmLc|
     * `-----------------------------------------------------------'
     */
  [L_NUMPAD] = LAYOUT_60_ansi(
        ______,   KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_PMNS,  KC_PPLS,  KC_BSPC, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PMNS,  KC_P7,    KC_P8,    KC_P9,    KC_PSLS,  ______,   ______,   ______, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PPLS,  KC_P4,    KC_P5,    KC_P6,    KC_PAST,  ______,             KC_PENT, \
        ______,   ______,   ______,   ______,   ______,   ______,   KC_PDOT,  KC_P1,    KC_P2,    KC_P3,    ______,                       KC_PENT, \
        ______,   ______,   ______,                       KC_P0,                                            KC_PDOT,  ______,   ______,   KC_NLCK \
  ),

    /* Overlay: Layout selection layer
     * ,-----------------------------------------------------------.
     * |Gm |ISO|ANS|FRW|   |   |   |   |   |   |   |   |   |BootLdr|
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
  [L_CONFIG] = LAYOUT_60_ansi(
        FN_GAME,  DL_ISO,   DL_ANSI,  DL_FROW,  ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   ______,   RESET,  \
        ______,   EF_INC,   ES_INC,   S1_INC,   H1_INC,   S2_INC,   H2_INC,   BR_INC,   ______,   ______,   ______,   ______,   ______,   ______, \
        ______,   EF_DEC,   ES_DEC,   S1_DEC,   H1_DEC,   S2_DEC,   H2_DEC,   BR_DEC,   ______,   ______,   ______,   ______,          FN_CONFIG, \
        ______,   KC_ACL0,  KC_ACL1,  KC_ACL2,  ______,   ______,   ______,   ______,   ______,   ______,   ______,                       ______, \
        ______,   ______,   ______,                       ______,                                           ______,   ______,   ______,   ______ \
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
    case C_CLSEXT:
      if (record->event.pressed) {
        layer_off(L_EXTENDED_LOCK);
        layer_off(L_EXTENDED);
      }
      return false;
    case C_AACUTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_QUOTE))));
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;
    case C_AGRAVE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_BSLASH))));
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;
    case C_TILDE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_SLASH))));
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;
    default:
      return true;
  }
}
