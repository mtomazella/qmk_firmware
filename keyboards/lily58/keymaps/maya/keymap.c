#include QMK_KEYBOARD_H

// Flash command
// avrdude -v -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -D -U/home/tomazella/qmk_firmware/.build/lily58_r2g_maya.hex

enum custom_keycodes {
    ARROW = SAFE_RANGE
};

enum layer_number { _QWERTY = 0, _NUMBER, _SYMBOL, _MOVEMENT, _MOUSE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Back |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´`  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  ~^  `
     * |------+------+------+------+------+------MOUSE   |    | Enter |------+------+------+------+------+-----~^
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |  ;:  |  /?  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |SYMBL | /NUMBR  /       \Space \  |MOVNT |SYMBL | RSshift |
     *                   |      |      |      |/       /         \      \ |      |      |         |
     *                   `----------------------------'           '------''-----------------------'
     */

    [_QWERTY] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                         KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(_MOUSE),    KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
      KC_LGUI, KC_LALT, MO(_SYMBOL), MO(_NUMBER),           KC_SPC, MO(_MOVEMENT), MO(_SYMBOL), KC_RSFT
    ),

    /* NUMBER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  v   |      |      |      |      |      |                    |      |      |      |      |      | Back |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |  F5  |  F6  |  F7  |  F8  |      |                    |  7   |  8   |  9   |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |  F1  |  F2  |  F3  |  F4  |      |-------.    ,-------|  4   |  5   |  6   |      |      |      |
     * |------+------+------+------+------+------|       |    |   v   |------+------+------+------+------+------|
     * |  v   |  F9  |  F10 |  F11 |  F12 |      |-------|    |-------|  1   |  2   |  3   |      |      | Inst |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |   v  |  v   |      | /  v    /       \   v  \  |  0   |      |   v  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NUMBER] = LAYOUT(
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC,
      KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,                            KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO,
      KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,                            KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO,
      KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,         KC_TRNS, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_INS, 
                          KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,         KC_TRNS, KC_0, KC_NO, KC_TRNS
    ),

    /* SYMBOL
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  v   |      |      |      |      |      |                    |      |      |      |      |      | Back |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |  #   |      |  %   |  $   |      |                    |  !   |  [   |  ]   |  +   |  "   |  #   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |  *   |  @   |  ?   |  :   |  =>  |-------.    ,-------|  &   |  (   |  )   |  =   |  '   |  /   |
     * |------+------+------+------+------+------|       |    |   v   |------+------+------+------+------+------|
     * |  v   |      |      |  <   |  >   |      |-------|    |-------|  |   |  {   |  }   |  -   |  _   |  \   |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |   v  |  v   |  v   | /       /       \   v  \  |      |  v   |   v  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_SYMBOL] = LAYOUT(
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC,
      KC_TRNS, KC_HASH, KC_NO, KC_PERC, KC_DLR, KC_NO,                                        KC_EXLM, KC_RBRC, KC_BSLS, KC_PLUS, KC_TILD, KC_HASH, 
      KC_TRNS, KC_ASTR, KC_AT, LSFT(KC_RCTL), LSFT(KC_SLSH), ARROW,                           KC_AMPR, KC_LPRN, KC_RPRN, KC_EQL, KC_GRV, KC_RCTL,
      KC_TRNS, KC_NO, KC_NO, LSFT(KC_COMM), LSFT(KC_DOT), KC_NO, KC_NO,           KC_TRNS, LSFT(KC_NUBS), KC_RCBR, KC_PIPE, KC_MINS, KC_UNDS, KC_NUBS,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                          KC_TRNS, KC_NO, KC_TRNS, KC_TRNS
    ),

    /* MOVEMENT
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  v   |      |      |      |      |      |                    |      |      |      |      |      | DEL  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |      |      | Prev | Next |      |                    |      | Home | End  |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |      |Pause |  V-  |  V+  |      |-------.    ,-------|  <   |  v   |  ^   |  >   |      |      |
     * |------+------+------+------+------+------|       |    |   v   |------+------+------+------+------+------|
     * |  v   |      |      | Mute |      |      |-------|    |-------|      | PgD  | PgG  |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |   v  |  v   |      | /       /       \   v  \  |  v   |      |   v  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_MOVEMENT] = LAYOUT(
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,
      KC_TRNS, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_NO,                           KC_NO, KC_HOME, KC_END, KC_NO, KC_NO, KC_NO,
      KC_TRNS, KC_NO, KC_MPLY, KC_VOLD, KC_VOLU, KC_NO,                KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
      KC_TRNS, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO,            KC_TRNS, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_NO, KC_NO,
                           KC_TRNS, KC_TRNS, KC_NO, KC_NO,            KC_TRNS, KC_TRNS, KC_NO, KC_TRNS
    ),


    /* MOUSE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  v   |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |      |      |      |      |      |                    |  C<  |  Cv  |  C^  |  C>  |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  v   |      |      |      |      |      |-------.    ,-------|  M<  |  Mv  |  M^  |  M>  |      |      |
     * |------+------+------+------+------+------|   v   |    |   v   |------+------+------+------+------+------|
     * |  v   |      |      |      |      |      |-------|    |-------|  M1  |  M2  |  M3  |  M4  |  M5  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |   v  |  v   |      | /       /       \   v  \  | MA0  | MA1  | MA2  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_MOUSE] = LAYOUT(
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_NO, KC_DEL,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                       MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_NO, KC_NO,
      KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,                     KC_TRNS, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5, KC_NO,
                         KC_TRNS, KC_TRNS, KC_NO, KC_NO,                       KC_TRNS, MS_ACL0, MS_ACL1, MS_ACL2
    )
  };

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NUMBER, _SYMBOL, _MOVEMENT);
// }

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        // oled_write_ln(read_keylog(), false);
        // oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    switch (keycode) {
    case ARROW:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        break;
    }

    return true;
}
