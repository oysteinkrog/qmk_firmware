#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2

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
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (colemak)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | TAB  |   q  |   w  |   f  |   p  |   g  |                             |   j  |   l  |   u  |   y  |   ;  |  |   |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | LCTL |   a  |   r  |   s  |   t  |   d  |                             |   h  |   n  |   e  |   i  |   o  | RCTRL|
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   k  |   m  |   ,  |   .  |   /  | SHFT |
 * +------+------+------+------+-------------+-------+             +-------+-------------+------+------+------+------+
 *               |      | LALT | BSCP |ESC|RS| LOWER |             |  DEL  | ENTER| SPC  | RALT |   =  |
 *               +------+------+------+------+-------+             +-------+-------------+-------------+
 */

[_BASE] = LAYOUT( \
    KC_TAB,  KC_Q,  KC_W,   KC_F,   KC_P,    KC_G,                              KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLS,   \
    KC_LCTL, KC_A,  KC_R,   KC_S,   KC_T,    KC_D,                              KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_RCTL,   \
    KC_LSFT, KC_Z,  KC_X,   KC_C,   KC_V,    KC_B,                              KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT, \
                    KC_LBRC,KC_LALT,KC_BSPC, LT(_RAISE,KC_ESC),    MO(_LOWER),KC_DEL, KC_ENT,   KC_SPC, KC_RALT,KC_EQL                     \
),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |                              |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                     KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                    _______, _______, _______, KC_SCLN, KC_EQL,                    KC_EQL,  KC_SCLN, _______, _______, _______
),
/*
[_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,KC_LBRC,                    KC_RBRC, KC_P7, KC_P8,  KC_P9,  RESET,  KC_PLUS,   \
    _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                    KC_RPRN, KC_P4, KC_P5,  KC_P6,  KC_MINS,KC_PIPE,   \
    _______,_______,_______,_______,_______,_______,                    _______,KC_P1,  KC_P2,  KC_P3,  KC_EQL, KC_UNDS,   \
                    KC_LBRC,KC_RBRC,_LOWER, KC_ESC, KC_BSPC,   _LOWER,  KC_ENT, KC_SPC, KC_PLUS,KC_EQL                    \
),
*/
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
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  ×----------------------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      RESET,
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, KC_MUTE, KC_VOLD,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
                    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______
),

/*
[_RAISE] = LAYOUT(
    _______,RESET,  _______,KC_UP  ,_______,KC_LBRC,                    KC_RBRC,_______,KC_NLCK,KC_INS, KC_SLCK,KC_MUTE,   \
    _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,END    ,                    KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,   \
    _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,KC_VOLD,   \
                    KC_LBRC,KC_RBRC,_LOWER, KC_ESC, KC_BSPC,   _LOWER,  KC_ENT, KC_SPC, KC_PLUS,KC_EQL                    \
)
*/

};

const uint16_t PROGMEM test_combo[] = {KC_A, KC_B, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
