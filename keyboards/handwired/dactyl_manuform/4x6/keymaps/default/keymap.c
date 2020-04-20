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
 * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   k  |   m  |   ,  |   b  |   /  | SHFT |
 * +------+------+------+------+-------------+-------+             +-------+-------------+------+------+------+------+
 *               |      |      | BSCP | ESC  | LOWER |             | LOWER | ENTER| SPC  |      |      |
 *               +------+------+------+------+-------+             +-------+-------------+-------------+
 */

[_BASE] = LAYOUT( \
    KC_TAB,  KC_Q,  KC_W,   KC_F,   KC_P,    KC_G,                       KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_MINS,   \
    KC_LCTL, KC_A,  KC_R,   KC_S,   KC_T,    KC_D,                       KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,   \
    KC_LSFT, KC_Z,  KC_X,   KC_C,   KC_V,    KC_B,                       KC_K,   KC_M,   KC_COMM,KC_B,   KC_SLSH,KC_BSLASH, \
                    KC_LBRC,KC_RBRC,KC_BSPC, KC_ESC, _LOWER,    _LOWER,  KC_ENT, KC_SPC, KC_PLUS,KC_EQL                     \
),

[_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,KC_LBRC,                    KC_RBRC, KC_P7, KC_P8,  KC_P9,  RESET,  KC_PLUS,   \
    _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                    KC_RPRN, KC_P4, KC_P5,  KC_P6,  KC_MINS,KC_PIPE,   \
    _______,_______,_______,_______,_______,_______,                    _______,KC_P1,  KC_P2,  KC_P3,  KC_EQL, KC_UNDS,   \
                    KC_LBRC,KC_RBRC,_LOWER, KC_ESC, KC_BSPC,   _LOWER,  KC_ENT, KC_SPC, KC_PLUS,KC_EQL                    \
),

[_RAISE] = LAYOUT(
    _______,RESET,  _______,_______,_______,KC_LBRC,                    KC_RBRC,_______,KC_NLCK,KC_INS, KC_SLCK,KC_MUTE,   \
    _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                    KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,   \
    _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,KC_VOLD,   \
                    KC_LBRC,KC_RBRC,_LOWER, KC_ESC, KC_BSPC,   _LOWER,  KC_ENT, KC_SPC, KC_PLUS,KC_EQL                    \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
