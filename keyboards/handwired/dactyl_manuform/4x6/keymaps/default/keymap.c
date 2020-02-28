#include QMK_KEYBOARD_H


#define _L0 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _L4 4

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MWU KC_MS_WH_UP
#define KC_MWD KC_MS_WH_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define L1 MO(_L1)
#define L2 MO(_L2)
#define L3 MO(_L3)

#define L1_ESC  LT(_L1,    KC_ESC)
#define L2_ESC  LT(_L2,    KC_ESC)
#define L1_SPC  LT(_L1,    KC_SPC)
#define L1_BSPC LT(_L1,    KC_BSPC)
#define L2_BSPC LT(_L2,    KC_BSPC)
#define L3_DEL  LT(_L3,    KC_DEL)
#define L1_ENT  LT(_L1,    KC_ENT)
#define L2_ENT  LT(_L2,    KC_ENT)
#define ALT_DEL LT(KC_LALT,KC_DEL)

// Implement Super-alt↯tab
// See https://docs.qmk.fm/#/feature_macros?id=super-alt↯tab
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// Defining all the custom keycodes.
enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* L0: Colemak
 * +-----------------------------------------------+                     +-----------------------------------------------+
 * |  TAB  |   q   |   w   |   f   |   p   |   g   |                     |   j   |   l   |   u   |   y   |   ;   |   |   |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |  LCTL |   a   |   r   |   s   |   t   |   d   |                     |   h   |   n   |   e   |   i   |   o   | RCTRL |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |  SHFT |   z   |   x   |   c   |   v   |   b   |                     |   k   |   m   |   ,   |   .   |   /   |  SHFT |
 * +-------+-------+-------+-------+-------+-------+------ +    +--------+-------+-------+-------+-------+-------+-------+
 *                 |   L3  |       |L1_BSPC| L2_ESC|   L3  |    | L3_DEL | L2_EN | L1_SPC|  RALT |   L3  |
 *                 +-------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+
 *                                         |  LGUI |  ALT  |    |   INS  | RALT  |
 *                                         +-------+-------+    +--------+-------+
 */

[_L0] = LAYOUT( \
     KC_TAB,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                         KC_J,   KC_L,   KC_U,   KC_Y,KC_SCLN,KC_BSLS,   \
     KC_LCTL , KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                         KC_H,   KC_N,   KC_E,   KC_I,   KC_O,KC_RCTL,   \
     KC_LSFT , KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                         KC_K,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,   \
                         L3,_______,L1_BSPC,L2_ESC,     L3,      L3_DEL , L2_ENT, L1_SPC,KC_RALT,     L3,                   \
                                            KC_LGUI,KC_LALT,      KC_INS , KC_RALT
),
/*
 * L1: Symbols
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |       |   !   |   @   |   {   |   }   |   |   |                     |       |       |       |       |       |  | \  |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |   #   |   $   |   (   |   )   |   `   |                     |    +  |   -   |   /   |   *   |   %   |  ' "  |
 * |-------+-------+-------+-------+-------+-------+                     +-------+-------+-------+-------+-------+-------|
 * |       |   %   |   ^   |   [   |   ]   |   ~   |                     |    &  |   =   |   ,   |   .   |  / ?  | - _   |
 * `-----------------------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+-------+-------'
 *                 |       |       |       |   ;   |   =   |    |   =    |   ;   |       |       |       |
 *                 +-------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+
 *                                         |       |       |    |        |       |
 *                                         +-------+-------+    +--------+-------+
 */
[_L1] = LAYOUT(
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                   _______,_______,_______,_______,_______,KC_BSLS,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                    KC_PLUS,KC_MINS,KC_SLSH,KC_ASTR,KC_PERC,KC_QUOT,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                   KC_AMPR,KC_EQL, KC_COMM, KC_DOT,KC_SLSH,KC_MINS,
                    _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN,_______,_______,_______,
                                            _______,_______,      _______,_______
),
/*
 * L2: Numbers and FN
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |ALT_TAB|       |  F7   |  F8   |  F9   |  F10  |                     |       |   7   |   8   |   9   |       |       |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |  F4   |  F5   |  F6   |  F11  |                     |       |   4   |   5   |   6   |       |       |
 * |-------+-------+-------+-------+-------+-------+                     +-------+-------+-------+-------+-------+-------|
 * |       |       |  F1   |  F2   |  F3   |  F12  |                     |  RGUI |   1   |   2   |   3   |       |       |
 * `-----------------------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+-------+-------'
 *                 |       |       |       |       |       |    |        |       |       |   0   |   ,   |
 *                 +-------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+
 *                                         |       |       |    |        |       |
 *                                         +-------+-------+    +--------+-------+
 */
[_L2] = LAYOUT(
    _______,_______, KC_F7, KC_F8, KC_F9, KC_F10,                      _______,   KC_7,   KC_8,   KC_9,_______,_______,
    _______,_______, KC_F4, KC_F5, KC_F6, KC_F11,                      _______,   KC_4,   KC_5,   KC_6,_______,_______,
    _______,_______, KC_F1, KC_F2, KC_F3, KC_F12,                      KC_RGUI,   KC_1,   KC_2,   KC_3,_______,_______,
                    _______,_______,_______,_______,_______,      _______,_______,_______,KC_0,KC_COMM,
                                            _______,_______,      _______,_______
),
/*
 * L3: Utilties
 * +-----------------------------------------------+                     +-----------------------------------------------+
 * |       |       |  MWU  |  MUP  |  MWD  |       |                     |       | PGPU  |  UP   | PGDN  |       | VOLUP |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       | MLEFT | MDOWN | MRIGHT|       |                     |  HOME | LEFT  | DOWN  | RIGHT |  END  | VOLDN |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                     |       |       |       |       |       |  MUTE |
 * +-------+-------+-------+-------+-------+-------+------ +    +--------+-------+-------+-------+-------+-------+-------+
 *                 |       |       |       |       |       |    |        |       |       |       | RESET |
 *                 +-------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+
 *                                         |       |       |    |        |       |
 *                                         +-------+-------+    +--------+-------+
 */
[_L3] = LAYOUT(
    _______,_______, KC_MWU,  KC_MU, KC_MWD,_______,                      _______,KC_PGUP,KC_UP  ,KC_PGDN,_______,KC_VOLU,
    _______,_______,  KC_ML,  KC_MD,  KC_MR, KC_MB1,                      KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END,KC_VOLD,
    _______,_______,_______,_______,_______, KC_MB2,                      _______,_______,_______,KC_MS_R,_______,KC_MUTE,
                    _______,_______,_______,_______,_______,      _______,_______,_______,_______, RESET,
                                            _______,_______,      _______,_______
),

/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   1  | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|                              | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------+  +-------------+------+------+------+----------------------'
 *                 |       |       |       |       |       |    |        |       |       |       |       |
 *                 +-------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+
 *                                         |       |       |    |        |       |
 *                                         +-------+-------+    +--------+-------+
 */

/*
[_L1] = LAYOUT(
    _______,RESET,  _______,KC_UP  ,_______,KC_LBRC,                    KC_RBRC,_______,KC_NLCK,KC_INS, KC_SLCK,KC_MUTE,   \
    _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,END    ,                    KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,   \
    _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,KC_VOLD,   \
                    KC_LBRC,KC_RBRC,_L2, KC_ESC, KC_BSPC,   _L2,  KC_ENT, KC_SPC, KC_PLUS,KC_EQL                    \
)
*/

};

const uint16_t PROGMEM test_combo[] = {KC_A, KC_B, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Processing all the key pressed.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Depending keycodes…
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {     // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

/*
 * +-----------------------------------------------+                     +-----------------------------------------------+
 * |       |       |       |       |       |       |                     |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                     |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                     |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+------ +    +--------+-------+-------+-------+-------+-------+-------+
 *                 |       |       |       |       |       |    |        |       |       |       |       |
 *                 +-------+-------+-------+-------+-------+    +--------+-------+-------+-------+-------+
 *                                         |       |       |    |        |       |
 *                                         +-------+-------+    +--------+-------+
 */
