#include QMK_KEYBOARD_H

char wpm_str[10];
uint16_t wpm_graph_timer = 0;

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
#define L3_INS  LT(_L3,    KC_INS)
#define L1_ENT  LT(_L1,    KC_ENT)
#define L2_ENT  LT(_L2,    KC_ENT)
#define L1_SPC  LT(_L1,    KC_SPC)
#define L2_SPC  LT(_L2,    KC_SPC)
#define ALT_DEL LT(KC_LALT,KC_DEL)

// Implement Super-alt↯tab
// See https://docs.qmk.fm/#/feature_macros?id=super-alt↯tab
/*bool is_alt_tab_active = false;*/
/*uint16_t alt_tab_timer = 0;*/

// Defining all the custom keycodes.
/*enum custom_keycodes {*/
  /*ALT_TAB = SAFE_RANGE,*/
/*};*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* L0: Colemak
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |  TAB  |   q   |   w   |   f   |   p   |   g   |                     |   j   |   l   |   u   |   y   |   ;   |   |   |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |  LCTL |   a   |   r   |   s   |   t   |   d   |                     |   h   |   n   |   e   |   i   |   o   | RCTRL |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |  SHFT |   z   |   x   |   c   |   v   |   b   |                     |   k   |   m   |   ,   |   .   |   /   |  SHFT |
 * `-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------'
 *                 |   L3  |  LALT |L1_BSPC| L2_ESC|   L3  |     |   L3  | L2_SPC| L1_ENT|  RALT |   L3  |
 *                 `-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------'
 *                                         |  LGUI |  INS  |     |  DEL  | RALT  |
 *                                         `-------+-------'     `-------+-------'
 */

[_L0] = LAYOUT( \
     KC_TAB,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                         KC_J,   KC_L,   KC_U,   KC_Y,KC_SCLN,KC_BSLS,
     KC_LCTL , KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                         KC_H,   KC_N,   KC_E,   KC_I,   KC_O,KC_RCTL,
     KC_LSFT , KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                         KC_K,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
                         L3,KC_LALT,L1_BSPC, L2_ESC,     L3,         L3  , L2_SPC, L1_ENT, KC_RALT,     L3,
                                            KC_LALT,  KC_INS,      KC_DEL,KC_RALT
),
/*
 * L1: Symbols
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |       |   !   |   @   |   {   |   }   |   |   |                     |       |       |       |       |       |  | \  |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |   #   |   $   |   (   |   )   |   `   |                     |   '"  |   +   |   -   |   /   |   *   |   %   |
 * |-------+-------+-------+-------+-------+-------+                     +-------+-------+-------+-------+-------+-------|
 * |       |   %   |   ^   |   [   |   ]   |   ~   |                     |   -_  |   &   |   =   |   ,   |   .   |  / ?  |
 * `-----------------------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------'
 *                 |       |       |       |       |       |     |       |       |       |       |       |
 *                 `-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------'
 *                                         |       |       |     |       |       |
 *                                         `-------+-------'     `-------+-------'
 */
[_L1] = LAYOUT(
    _______,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,                      _______,_______,_______,_______,_______,KC_BSLS,
    _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN, KC_GRV,                      KC_QUOT,KC_PLUS,KC_MINS,KC_SLSH,KC_ASTR,KC_PERC,
    _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                      KC_MINS,KC_AMPR,KC_EQL, KC_COMM, KC_DOT,KC_SLSH,
                    _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                            _______,_______,      _______,_______
),
/*
 * L2: Numbers and FN
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |ALT_TAB|       |  F7   |  F8   |  F9   |  F10  |                     |   =   |   7   |   8   |   9   |   +   |       |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |  F4   |  F5   |  F6   |  F11  |                     |   0   |   4   |   5   |   6   |   -   |       |
 * |-------+-------+-------+-------+-------+-------+                     +-------+-------+-------+-------+-------+-------|
 * |       |       |  F1   |  F2   |  F3   |  F12  |                     |   .   |   1   |   2   |   3   |   ,   |       |
 * `-----------------------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------'
 *                 |       |       |       |       |       |     |       |       |       |       |       |
 *                 `-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------'
 *                                         | RESET |       |     |       | RESET |
 *                                         `-------+-------'     `-------+-------'
 */
[_L2] = LAYOUT(
    _______,_______,  KC_F7,  KC_F8,  KC_F9, KC_F10,                       KC_EQL,   KC_7,   KC_8,   KC_9,KC_PLUS,_______,
    _______,_______,  KC_F4,  KC_F5,  KC_F6, KC_F11,                         KC_0,   KC_4,   KC_5,   KC_6,KC_MINS,_______,
    _______,_______,  KC_F1,  KC_F2,  KC_F3, KC_F12,                       KC_DOT,   KC_1,   KC_2,   KC_3,KC_COMM,_______,
                    _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                              RESET,_______,      _______,  RESET
),
/*
 * L3: Utilties
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |       |       |  MWU  |  MUP  |  MWD  |       |                     |       | PGPU  |  UP   | PGDN  |       | VOLUP |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       | MLEFT | MDOWN | MRIGHT|       |                     |  HOME | LEFT  | DOWN  | RIGHT |  END  | VOLDN |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                     |       |       |       |       |       |  MUTE |
 * `-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------'
 *                 | RESET |       |       |       |       |     |       |       |       |       | RESET |
 *                 `-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------'
 *                                         | RESET |       |     |       | RESET |
 *                                         `-------+-------`     `-------+-------'
 */
[_L3] = LAYOUT(
    _______,_______, KC_MWU,  KC_MU, KC_MWD,_______,                      _______,KC_PGUP,KC_UP  ,KC_PGDN,_______,KC_VOLU,
    _______,_______,  KC_ML,  KC_MD,  KC_MR, KC_MB1,                      KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END,KC_VOLD,
    _______,_______,_______,_______,_______, KC_MB2,                      _______,_______,_______,KC_MS_R,_______,KC_MUTE,
                      RESET,_______,_______,_______,_______,      _______,_______,_______,_______, RESET,
                                              RESET,_______,      _______,  RESET
),

};

/*const uint16_t progmem test_combo[] = {kc_a, kc_b, combo_end};*/
/*combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};*/

/*void persistent_default_layer_set(uint16_t default_layer) {*/
  /*eeconfig_update_default_layer(default_layer);*/
  /*default_layer_set(default_layer);*/
/*}*/

/*// Processing all the key pressed.*/
/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {*/

  /*// Depending keycodes…*/
  /*switch (keycode) { // This will do most of the grunt work with the keycodes.*/
    /*case ALT_TAB:*/
      /*if (record->event.pressed) {*/
        /*if (!is_alt_tab_active) {*/
          /*is_alt_tab_active = true;*/
          /*register_code(KC_LALT);*/
        /*}*/
        /*alt_tab_timer = timer_read();*/
        /*register_code(KC_TAB);*/
      /*} else {*/
        /*unregister_code(KC_TAB);*/
      /*}*/
      /*break;*/
  /*}*/
  /*return true;*/
/*}*/

/*void matrix_scan_user(void) {     // The very important timer.*/
  /*if (is_alt_tab_active) {*/
    /*if (timer_elapsed(alt_tab_timer) > 1000) {*/
      /*unregister_code(KC_LALT);*/
      /*is_alt_tab_active = false;*/
    /*}*/
  /*}*/
/*}*/

/*
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * |       |       |       |       |       |       |                     |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                     |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                     |       |       |       |       |       |       |
 * `-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------'
 *                 |       |       |       |       |       |     |       |       |       |       |       |
 *                 `-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------'
 *                                         |       |       |     |       |       |
 *                                         `-------+-------'     `-------+-------,
 */


#ifdef OLED_DRIVER_ENABLE
/*oled_rotation_t oled_init_user(oled_rotation_t rotation) {*/
    /*return OLED_ROTATION_180;*/
/*}*/

void matrix_init_user(void) { // Runs boot tasks for keyboard
    rgblight_enable();
    rgblight_sethsv(100,255,255);
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
};

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _L0:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _L1:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _L2:
            oled_write_P(PSTR("Numbers/FN\n"), false);
            break;
        case _L3:
            oled_write_P(PSTR("Utility\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

#ifdef WPM_ENABLE
    // Write WPM
    /*sprintf(wpm_str, "WPM: %03d", get_current_wpm());*/
    oled_write_P(PSTR("\n"), false);
    oled_write(wpm_str, false);
#endif
}

static uint8_t zero_bar_count = 0;
static uint8_t bar_count = 0;

static void render_wpm_graph(void) {
    uint8_t bar_height = 0;
    uint8_t bar_segment = 0;

    if (wpm_graph_timer == 0) {
        render_qmk_logo();

        wpm_graph_timer = timer_read();
        return;
    }
    if(timer_elapsed(wpm_graph_timer) > 500) {
        wpm_graph_timer = timer_read();

        if(OLED_DISPLAY_HEIGHT == 64)
            bar_height = get_current_wpm() / 2;
        if(OLED_DISPLAY_HEIGHT == 32)
            bar_height = get_current_wpm() / 4;
        if(bar_height > OLED_DISPLAY_HEIGHT)
            bar_height = OLED_DISPLAY_HEIGHT;

        if(bar_height == 0) {
            // keep track of how many zero bars we have drawn.  If
            // there is a whole screen worth, turn the display off and
            // wait until there is something to do
            if (zero_bar_count > OLED_DISPLAY_WIDTH) {
                oled_off();
                return;
            }
            zero_bar_count++;
        } else
            zero_bar_count=0;

        oled_pan(false);
        bar_count++;
        for (uint8_t i = (OLED_DISPLAY_HEIGHT / 8); i > 0; i--) {
            if (bar_height > 7) {
                if (i % 2 == 1 && bar_count % 3 == 0)
                    bar_segment = 254;
                else
                    bar_segment = 255;
                bar_height -= 8;
            } else {
                switch (bar_height) {
                    case 0:
                        bar_segment = 0;
                        break;

                    case 1:
                        bar_segment = 128;
                        break;

                    case 2:
                        bar_segment = 192;
                        break;

                    case 3:
                        bar_segment = 224;
                        break;

                    case 4:
                        bar_segment = 240;
                        break;

                    case 5:
                        bar_segment = 248;
                        break;

                    case 6:
                        bar_segment = 252;
                        break;

                    case 7:
                        bar_segment = 254;
                        break;
                }
                bar_height = 0;

                if (i % 2 == 1 && bar_count % 3 == 0)
                    bar_segment++;
            }
            oled_write_raw_byte(bar_segment, (i-1) * OLED_DISPLAY_WIDTH);
        }
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_wpm_graph();
    }
}
#endif

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            tap_code16(KC_TAB);
        } else {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code16(C(A(KC_RIGHT)));
        } else {
            tap_code16(C(A(KC_LEFT)));
        }
    }
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 700) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

