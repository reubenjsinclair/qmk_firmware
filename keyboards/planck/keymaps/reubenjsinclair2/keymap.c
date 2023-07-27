/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "print.h"

enum planck_layers {
    _COLEMAK,
    _QWERTY,
    _SUDOKU,
    _LOWER,
    _RAISE,
    _PLOVER,
    _ADJUST,
    _NUM,
    _NAV,
    _EXTEND,
    _FUN,
    _GAMES,
    _SETTINGS

};

enum tap_dance_codes { dance_q, dance_w, dance_f, dance_p, dance_b, dance_j, dance_l, dance_u, dance_y, dance_a, dance_r, dance_s, dance_t, dance_g, dance_m, dance_n, dance_e, dance_i, dance_o, dance_z, dance_x, dance_c, dance_d, dance_v, dance_k, dance_h, dance_backspace };
enum planck_keycodes { COLEMAK = SAFE_RANGE, QWERTY, SUDOKU, GAMES, PLOVER, BACKLIT, EXT_PLV, OPEN_CLOSE_QUOTE, OPEN_CLOSE_DBL_QUOTE, OPEN_CLOSE_PAREN, OPEN_CLOSE_BRACE, OPEN_CLOSE_BRACK };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FUN MO(_FUN)
// #define SUDOKU MO(_SUDOKU)
// #define GAMES MO(_GAMES)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(                                                                              //
        LT(_EXTEND, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                //
        LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,                  //
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,                     //
        KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, MO(_SETTINGS) //
        ),

    [_SUDOKU] = LAYOUT_planck_grid(                                                                            //
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_7, KC_8, KC_9, KC_P, KC_BSPC,                           //
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_4, KC_5, KC_6, KC_SCLN, KC_QUOT,                        //
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_1, KC_2, KC_3, KC_SLSH, KC_ENT,                        //
        KC_LCTL, KC_LALT, KC_LGUI, KC_NO, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, MO(_SETTINGS) //
        ),
    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  | _Num |Space |_Raise| _Nav |Space | Left | Down |_Lower|_Fun  |
     * `-----------------------------------------------------------------------------------'
     */
    // [_COLEMAK] = LAYOUT_planck_grid(                                                                                     //
    //     LT(_EXTEND, KC_ESC), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,                     //
    //     LCTL_T(KC_TAB), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, LALT_T(KC_ENT),                      //
    //     KC_LSPO, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,                            //
    //     KC_LCTL, KC_LGUI, KC_LALT, NUM, LT(_LOWER, KC_SPC), KC_SPC, KC_SPC, LT(_RAISE, KC_SPC), KC_NO, KC_NO, KC_NO, FUN //

    //     ),
    [_COLEMAK] = LAYOUT_planck_grid(                                                                                                                                    //
        KC_ESCAPE, TD(dance_q), TD(dance_w), TD(dance_f), TD(dance_p), TD(dance_b), TD(dance_j), TD(dance_l), TD(dance_u), TD(dance_y), KC_SCOLON, TD(dance_backspace), //
        LT(_EXTEND,KC_TAB), TD(dance_a), TD(dance_r), TD(dance_s), TD(dance_t), TD(dance_g), TD(dance_m), TD(dance_n), TD(dance_e), TD(dance_i), TD(dance_o), KC_ENTER,             //
        KC_LSPO, TD(dance_z), TD(dance_x), TD(dance_c), TD(dance_d), TD(dance_v), TD(dance_k), TD(dance_h), KC_COMMA, KC_DOT, KC_SLASH, KC_RSPC,                        //
        KC_LCTRL, KC_LCTRL, KC_TRANSPARENT, KC_LGUI, LOWER, KC_SPACE, KC_SPACE, RAISE, KC_LALT, KC_NO, KC_TRANSPARENT, MO(_SETTINGS)                                    //
        ),

    [_GAMES] = LAYOUT_planck_grid(                                                                            //
        KC_GRV, KC_1, KC_UP, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, OSM(MOD_LGUI),                   //
        KC_LGUI, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC, KC_F5, KC_H, KC_4, KC_5, KC_6, KC_F, KC_ENT,            //
        COLEMAK, G(KC_LCTL), KC_F8, KC_F9, KC_F10, KC_F11, KC_SLSH, KC_1, KC_2, KC_3, KC_MINUS, _______,      //
        COLEMAK, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_EQL, MO(_SETTINGS) //
        ),
    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |   [  |   ]  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(                                                                                                                       //
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,                                                                     //
        KC_DEL, OPEN_CLOSE_BRACE, OPEN_CLOSE_PAREN, OPEN_CLOSE_DBL_QUOTE, OPEN_CLOSE_QUOTE, KC_F5, KC_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_DOT, KC_ENTER, //
        _______, OPEN_CLOSE_BRACK, KC_F8, KC_F9, KC_F10, CK_TOGG, KC_MINUS, KC_KP_1, KC_KP_2, KC_KP_3, KC_ASTR, KC_EQL,                                  //
            _______, _______, _______, _______, LOWER, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY                                        //
        ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(                                                                               //
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC, //
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,            //
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,       //
        _______, _______, _______, _______, _______, _______, _______, RAISE, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY //
        ),

    /* Nav
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  Del | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   *  |   4  |   5  |   6  |   +  |  Ent |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |   /  |   1  |   2  |   3  |   -  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |   0  |   .  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(                                                                                       //
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,                                   //
        OSM(MOD_LGUI), KC_LGUI, C(KC_Y), C(KC_Z), KC_AMPR, KC_F5, KC_H, KC_J, KC_K, KC_L, KC_F, KC_ENT,                //
        OSM(MOD_LGUI | MOD_LCTL), G(KC_LCTL), KC_F8, KC_F9, KC_F10, KC_F11, KC_SLSH, KC_Q, KC_2, KC_3, KC_MINUS,       //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_EQL, _______ //
        ),

    [_FUN] = LAYOUT_planck_grid(                                                                                   //
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC,   //
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MUTE, KC_VOLD, KC_VOLU, KC_RCBR, KC_QUOT,             //
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_NUHS), S(KC_NUBS), KC_LPRN, KC_RPRN, KC_EQL,    //
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY //
        ),

    /* Num
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  Del | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   *  |   4  |   5  |   6  |   +  |  Ent |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |   /  |   1  |   2  |   3  |   -  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |   0  |   .  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(                                                                              //
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,                          //
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_ENT,                //
        _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_SLSH, KC_1, KC_2, KC_3, KC_MINUS, _______,           //
        _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_EQL, _______ //
        ),

    /* Extend
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  Del | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   *  |   4  |   5  |   6  |   +  |  Ent |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |   /  |   1  |   2  |   3  |   -  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |   0  |   .  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_EXTEND] = LAYOUT_planck_grid(                                                                             //
        KC_GRV, KC_1, KC_UP, KC_3, KC_4, KC_5, KC_LOCK, KC_7, KC_8, KC_9, KC_DEL, KC_BSPC,                      //
        KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, C(KC_V), KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BSPC, KC_ESC, //
        _______, KC_F7, KC_F8, C(KC_C), C(KC_V), KC_F11, KC_SLSH, KC_1, KC_2, KC_3, KC_MINUS, _______,          //
        _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_EQL, _______   //
        ),

    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_PLOVER] = LAYOUT_planck_grid(                                                              //
        KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,                  //
        XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,            //
        XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         //
        EXT_PLV, XXXXXXX, XXXXXXX, KC_C, KC_C, KC_V, KC_N, KC_M, KC_M, XXXXXXX, XXXXXXX, XXXXXXX //
        ),

    /* Adjust (Lower + Raise)
     *                      v------------------------RGB CONTROL--------------------v
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Sudoku|Plover|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_SETTINGS] = LAYOUT_planck_grid(                                                                      //
        RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                //
        _______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, COLEMAK, SUDOKU, PLOVER, GAMES, //
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                //
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO                 //
        ),
    [_ADJUST]   = LAYOUT_planck_grid(                                                                                                    //
        _______, KC_MS_WH_DOWN, KC_MS_UP, KC_MS_WH_UP, RGB_MOD, RGB_HUI, RGB_HUD, KC_KB_MUTE, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, RGB_VAD, KC_DEL, //
        _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, AU_OFF, AG_NORM, AG_SWAP, KC_MS_BTN1, KC_MS_BTN2, SUDOKU, PLOVER, GAMES,         //
        MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______, _______,                           //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______                     //
        )

};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_DQUO);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_GOLD} // Light 4 LEDs, starting with LED
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_CYAN});
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_sudoku_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_PURPLE});
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 9, HSV_GREEN});
const rgblight_segment_t PROGMEM my_bspc_layer[]  = RGBLIGHT_LAYER_SEGMENTS({2, 3, HSV_RED});
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( my_qwerty_layer, my_colemak_layer, my_sudoku_layer, my_shift_layer, my_bspc_layer);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, _COLEMAK);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uprintf("%s state", state);
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SUDOKU));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                layer_off(_COLEMAK);
                layer_off(_SUDOKU);
                layer_off(_GAMES);
                layer_on(_QWERTY);
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                layer_on(_COLEMAK);
                layer_off(_SUDOKU);
                layer_off(_GAMES);
                layer_off(_QWERTY);
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case GAMES:
            if (record->event.pressed) {
                layer_off(_COLEMAK);
                layer_off(_SUDOKU);
                layer_on(_GAMES);
                layer_off(_QWERTY);
                set_single_persistent_default_layer(_GAMES);
            }
            return false;
            break;
        case SUDOKU:
            layer_off(_COLEMAK);
            layer_on(_SUDOKU);
            layer_off(_GAMES);
            layer_off(_QWERTY);
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SUDOKU);
            }
            return false;
            break;
        case KC_BSPC:
            if (record->event.pressed) {
                rgblight_set_layer_state(4, true);
            } else {
                rgblight_set_layer_state(4, false);
            }
            return true;
            break;
        case KC_LSPO:
            if (record->event.pressed) {
                rgblight_set_layer_state(3, true);
            } else {
                rgblight_set_layer_state(3, false);
            }
            return true;
            break;
        case KC_RSPC:
            if (record->event.pressed) {
                rgblight_set_layer_state(3, true);
            } else {
                rgblight_set_layer_state(3, false);
            }
            return true;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
        case OPEN_CLOSE_QUOTE:
            if (record->event.pressed) {
                SEND_STRING("''" SS_TAP(X_LEFT));
            }
            break;
        case OPEN_CLOSE_DBL_QUOTE:
            if (record->event.pressed) {
                SEND_STRING("@@" SS_TAP(X_LEFT));
            }
            break;
        case OPEN_CLOSE_PAREN:
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case OPEN_CLOSE_BRACE:
            if (record->event.pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            break;
        case OPEN_CLOSE_BRACK:
            if (record->event.pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
    }
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[29];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_q(qk_tap_dance_state_t *state, void *user_data);
void dance_q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_q_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_q(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if (state->count > 3) {
        tap_code16(KC_Q);
    }
}

void dance_q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_Q);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_Q));
            break;
        case DOUBLE_TAP:
            register_code16(KC_Q);
            register_code16(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_Q);
            register_code16(KC_Q);
    }
}

void dance_q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_Q);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_Q));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Q);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Q);
            break;
    }
    dance_state[0].step = 0;
}
void on_dance_w(qk_tap_dance_state_t *state, void *user_data);
void dance_w_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_w_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_w(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_W);
        tap_code16(KC_W);
        tap_code16(KC_W);
    }
    if (state->count > 3) {
        tap_code16(KC_W);
    }
}

void dance_w_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_W);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_W));
            break;
        case DOUBLE_TAP:
            register_code16(KC_W);
            register_code16(KC_W);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_W);
            register_code16(KC_W);
    }
}

void dance_w_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_W);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_W));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_W);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_W);
            break;
    }
    dance_state[1].step = 0;
}
void on_dance_f(qk_tap_dance_state_t *state, void *user_data);
void dance_f_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_f(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if (state->count > 3) {
        tap_code16(KC_F);
    }
}

void dance_f_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(KC_F);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F);
            register_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F);
            register_code16(KC_F);
    }
}

void dance_f_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F);
            break;
    }
    dance_state[2].step = 0;
}
void on_dance_p(qk_tap_dance_state_t *state, void *user_data);
void dance_p_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_p_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_p(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if (state->count > 3) {
        tap_code16(KC_P);
    }
}

void dance_p_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(KC_P);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_P));
            break;
        case DOUBLE_TAP:
            register_code16(KC_P);
            register_code16(KC_P);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_P);
            register_code16(KC_P);
    }
}

void dance_p_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(KC_P);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_P));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_P);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_P);
            break;
    }
    dance_state[3].step = 0;
}
void on_dance_b(qk_tap_dance_state_t *state, void *user_data);
void dance_b_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_b_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_b(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if (state->count > 3) {
        tap_code16(KC_B);
    }
}

void dance_b_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(KC_B);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_B));
            break;
        case DOUBLE_TAP:
            register_code16(KC_B);
            register_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_B);
            register_code16(KC_B);
    }
}

void dance_b_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(KC_B);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_B));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_B);
            break;
    }
    dance_state[4].step = 0;
}
void on_dance_j(qk_tap_dance_state_t *state, void *user_data);
void dance_j_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_j_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_j(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if (state->count > 3) {
        tap_code16(KC_J);
    }
}

void dance_j_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            register_code16(KC_J);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_J));
            break;
        case DOUBLE_TAP:
            register_code16(KC_J);
            register_code16(KC_J);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_J);
            register_code16(KC_J);
    }
}

void dance_j_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            unregister_code16(KC_J);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_J));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_J);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_J);
            break;
    }
    dance_state[5].step = 0;
}
void on_dance_l(qk_tap_dance_state_t *state, void *user_data);
void dance_l_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_l_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_l(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if (state->count > 3) {
        tap_code16(KC_L);
    }
}

void dance_l_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            register_code16(KC_L);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_L));
            break;
        case DOUBLE_TAP:
            register_code16(KC_L);
            register_code16(KC_L);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_L);
            register_code16(KC_L);
    }
}

void dance_l_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            unregister_code16(KC_L);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_L));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_L);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_L);
            break;
    }
    dance_state[6].step = 0;
}
void on_dance_u(qk_tap_dance_state_t *state, void *user_data);
void dance_u_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_u_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_u(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if (state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_u_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            register_code16(KC_U);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_U));
            break;
        case DOUBLE_TAP:
            register_code16(KC_U);
            register_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_U);
            register_code16(KC_U);
    }
}

void dance_u_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            unregister_code16(KC_U);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_U));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_U);
            break;
    }
    dance_state[7].step = 0;
}
void on_dance_y(qk_tap_dance_state_t *state, void *user_data);
void dance_y_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_y_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_y(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_Y);
        tap_code16(KC_Y);
        tap_code16(KC_Y);
    }
    if (state->count > 3) {
        tap_code16(KC_Y);
    }
}

void dance_y_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_Y);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_Y));
            break;
        case DOUBLE_TAP:
            register_code16(KC_Y);
            register_code16(KC_Y);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_Y);
            register_code16(KC_Y);
    }
}

void dance_y_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(KC_Y);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_Y));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Y);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Y);
            break;
    }
    dance_state[8].step = 0;
}
void on_dance_backspace(qk_tap_dance_state_t *state, void *user_data);
void dance_backspace_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_backspace_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_backspace(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_BSPACE);
        tap_code16(KC_BSPACE);
        tap_code16(KC_BSPACE);
    }
    if (state->count > 3) {
        tap_code16(KC_BSPACE);
    }
}

void dance_backspace_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            register_code16(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_BSPACE));
            break;
        case DOUBLE_TAP:
            register_code16(KC_BSPACE);
            register_code16(KC_BSPACE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_BSPACE);
            register_code16(KC_BSPACE);
    }
}

void dance_backspace_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            unregister_code16(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_BSPACE));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_BSPACE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_BSPACE);
            break;
    }
    dance_state[9].step = 0;
}
void on_dance_a(qk_tap_dance_state_t *state, void *user_data);
void dance_a_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_a_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_a(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if (state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_a_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            register_code16(KC_A);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_A));
            break;
        case DOUBLE_TAP:
            register_code16(KC_A);
            register_code16(KC_A);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_A);
            register_code16(KC_A);
    }
}

void dance_a_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            unregister_code16(KC_A);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_A));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_A);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_A);
            break;
    }
    dance_state[10].step = 0;
}
void on_dance_r(qk_tap_dance_state_t *state, void *user_data);
void dance_r_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_r_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_r(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_R);
        tap_code16(KC_R);
        tap_code16(KC_R);
    }
    if (state->count > 3) {
        tap_code16(KC_R);
    }
}

void dance_r_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            register_code16(KC_R);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_R));
            break;
        case DOUBLE_TAP:
            register_code16(KC_R);
            register_code16(KC_R);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_R);
            register_code16(KC_R);
    }
}

void dance_r_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            unregister_code16(KC_R);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_R));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_R);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_R);
            break;
    }
    dance_state[11].step = 0;
}
void on_dance_s(qk_tap_dance_state_t *state, void *user_data);
void dance_s_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_s_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_s(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if (state->count > 3) {
        tap_code16(KC_S);
    }
}

void dance_s_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            register_code16(KC_S);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_S));
            break;
        case DOUBLE_TAP:
            register_code16(KC_S);
            register_code16(KC_S);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_S);
            register_code16(KC_S);
    }
}

void dance_s_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            unregister_code16(KC_S);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_S));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_S);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_S);
            break;
    }
    dance_state[12].step = 0;
}
void on_dance_t(qk_tap_dance_state_t *state, void *user_data);
void dance_t_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_t_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_t(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_T);
        tap_code16(KC_T);
        tap_code16(KC_T);
    }
    if (state->count > 3) {
        tap_code16(KC_T);
    }
}

void dance_t_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            register_code16(KC_T);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_T));
            break;
        case DOUBLE_TAP:
            register_code16(KC_T);
            register_code16(KC_T);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_T);
            register_code16(KC_T);
    }
}

void dance_t_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            unregister_code16(KC_T);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_T));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_T);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_T);
            break;
    }
    dance_state[13].step = 0;
}
void on_dance_g(qk_tap_dance_state_t *state, void *user_data);
void dance_g_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_g_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_g(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_G);
        tap_code16(KC_G);
        tap_code16(KC_G);
    }
    if (state->count > 3) {
        tap_code16(KC_G);
    }
}

void dance_g_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP:
            register_code16(KC_G);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_G));
            break;
        case DOUBLE_TAP:
            register_code16(KC_G);
            register_code16(KC_G);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_G);
            register_code16(KC_G);
    }
}

void dance_g_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP:
            unregister_code16(KC_G);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_G));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_G);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_G);
            break;
    }
    dance_state[14].step = 0;
}
void on_dance_m(qk_tap_dance_state_t *state, void *user_data);
void dance_m_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_m_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_m(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_M);
        tap_code16(KC_M);
        tap_code16(KC_M);
    }
    if (state->count > 3) {
        tap_code16(KC_M);
    }
}

void dance_m_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP:
            register_code16(KC_M);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_M));
            break;
        case DOUBLE_TAP:
            register_code16(KC_M);
            register_code16(KC_M);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_M);
            register_code16(KC_M);
    }
}

void dance_m_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP:
            unregister_code16(KC_M);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_M));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_M);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_M);
            break;
    }
    dance_state[15].step = 0;
}
void on_dance_n(qk_tap_dance_state_t *state, void *user_data);
void dance_n_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_n(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if (state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP:
            register_code16(KC_N);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_N));
            break;
        case DOUBLE_TAP:
            register_code16(KC_N);
            register_code16(KC_N);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_N);
            register_code16(KC_N);
    }
}

void dance_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP:
            unregister_code16(KC_N);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_N));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_N);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_N);
            break;
    }
    dance_state[16].step = 0;
}
void on_dance_e(qk_tap_dance_state_t *state, void *user_data);
void dance_e_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_e_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_e(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_E);
        tap_code16(KC_E);
        tap_code16(KC_E);
    }
    if (state->count > 3) {
        tap_code16(KC_E);
    }
}

void dance_e_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            register_code16(KC_E);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_E));
            break;
        case DOUBLE_TAP:
            register_code16(KC_E);
            register_code16(KC_E);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_E);
            register_code16(KC_E);
    }
}

void dance_e_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            unregister_code16(KC_E);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_E));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_E);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_E);
            break;
    }
    dance_state[17].step = 0;
}
void on_dance_i(qk_tap_dance_state_t *state, void *user_data);
void dance_i_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_i_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_i(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if (state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_i_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            register_code16(KC_I);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_I));
            break;
        case DOUBLE_TAP:
            register_code16(KC_I);
            register_code16(KC_I);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_I);
            register_code16(KC_I);
    }
}

void dance_i_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            unregister_code16(KC_I);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_I));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_I);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_I);
            break;
    }
    dance_state[18].step = 0;
}
void on_dance_o(qk_tap_dance_state_t *state, void *user_data);
void dance_o_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_o_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_o(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if (state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_o_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            register_code16(KC_O);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_O));
            break;
        case DOUBLE_TAP:
            register_code16(KC_O);
            register_code16(KC_O);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_O);
            register_code16(KC_O);
    }
}

void dance_o_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            unregister_code16(KC_O);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_O));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_O);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_O);
            break;
    }
    dance_state[19].step = 0;
}
void on_dance_f0(qk_tap_dance_state_t *state, void *user_data);
void dance_f0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_f0(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if (state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_f0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LPRN);
            register_code16(KC_LPRN);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_LPRN);
            register_code16(KC_LPRN);
    }
}

void dance_f0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LSHIFT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
    }
    dance_state[20].step = 0;
}
void on_dance_z(qk_tap_dance_state_t *state, void *user_data);
void dance_z_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_z(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if (state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            register_code16(KC_Z);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_Z));
            break;
        case DOUBLE_TAP:
            register_code16(KC_Z);
            register_code16(KC_Z);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_Z);
            register_code16(KC_Z);
    }
}

void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            unregister_code16(KC_Z);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_Z));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Z);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Z);
            break;
    }
    dance_state[21].step = 0;
}
void on_dance_x(qk_tap_dance_state_t *state, void *user_data);
void dance_x_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_x_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_x(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if (state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_x_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            register_code16(KC_X);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_X));
            break;
        case DOUBLE_TAP:
            register_code16(KC_X);
            register_code16(KC_X);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_X);
            register_code16(KC_X);
    }
}

void dance_x_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            unregister_code16(KC_X);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_X));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_X);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_X);
            break;
    }
    dance_state[22].step = 0;
}
void on_dance_c(qk_tap_dance_state_t *state, void *user_data);
void dance_c_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_c_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_c(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if (state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_c_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            register_code16(KC_C);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_C));
            break;
        case DOUBLE_TAP:
            register_code16(KC_C);
            register_code16(KC_C);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_C);
            register_code16(KC_C);
    }
}

void dance_c_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            unregister_code16(KC_C);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_C));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_C);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_C);
            break;
    }
    dance_state[23].step = 0;
}
void on_dance_d(qk_tap_dance_state_t *state, void *user_data);
void dance_d_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_d_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_d(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_D);
        tap_code16(KC_D);
        tap_code16(KC_D);
    }
    if (state->count > 3) {
        tap_code16(KC_D);
    }
}

void dance_d_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            register_code16(KC_D);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_D));
            break;
        case DOUBLE_TAP:
            register_code16(KC_D);
            register_code16(KC_D);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_D);
            register_code16(KC_D);
    }
}

void dance_d_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            unregister_code16(KC_D);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_D));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_D);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_D);
            break;
    }
    dance_state[24].step = 0;
}
void on_dance_v(qk_tap_dance_state_t *state, void *user_data);
void dance_v_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_v_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_v(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if (state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            register_code16(KC_V);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_V));
            break;
        case DOUBLE_TAP:
            register_code16(KC_V);
            register_code16(KC_V);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_V);
            register_code16(KC_V);
    }
}

void dance_v_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            unregister_code16(KC_V);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_V));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_V);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_V);
            break;
    }
    dance_state[25].step = 0;
}
void on_dance_k(qk_tap_dance_state_t *state, void *user_data);
void dance_k_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_k_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_k(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if (state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            register_code16(KC_K);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_K));
            break;
        case DOUBLE_TAP:
            register_code16(KC_K);
            register_code16(KC_K);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_K);
            register_code16(KC_K);
    }
}

void dance_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            unregister_code16(KC_K);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_K));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_K);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_K);
            break;
    }
    dance_state[26].step = 0;
}
void on_dance_h(qk_tap_dance_state_t *state, void *user_data);
void dance_h_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_h_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_h(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if (state->count > 3) {
        tap_code16(KC_H);
    }
}

void dance_h_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            register_code16(KC_H);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_H));
            break;
        case DOUBLE_TAP:
            register_code16(KC_H);
            register_code16(KC_H);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_H);
            register_code16(KC_H);
    }
}

void dance_h_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            unregister_code16(KC_H);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_H));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_H);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_H);
            break;
    }
    dance_state[27].step = 0;
}
void on_dance_f8(qk_tap_dance_state_t *state, void *user_data);
void dance_f8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_f8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_f8(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
    }
    if (state->count > 3) {
        tap_code16(KC_RPRN);
    }
}

void dance_f8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            register_code16(KC_RSHIFT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RPRN);
            register_code16(KC_RPRN);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_RPRN);
            register_code16(KC_RPRN);
    }
}

void dance_f8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_RSHIFT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
    }
    dance_state[28].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [dance_q]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_q, dance_q_finished, dance_q_reset),
    [dance_w]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_w, dance_w_finished, dance_w_reset),
    [dance_f]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f, dance_f_finished, dance_f_reset),
    [dance_p]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_p, dance_p_finished, dance_p_reset),
    [dance_b]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_b, dance_b_finished, dance_b_reset),
    [dance_j]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_j, dance_j_finished, dance_j_reset),
    [dance_l]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_l, dance_l_finished, dance_l_reset),
    [dance_u]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_u, dance_u_finished, dance_u_reset),
    [dance_y]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_y, dance_y_finished, dance_y_reset),
    [dance_backspace] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_backspace, dance_backspace_finished, dance_backspace_reset),
    [dance_a]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_a, dance_a_finished, dance_a_reset),
    [dance_r]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_r, dance_r_finished, dance_r_reset),
    [dance_s]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_s, dance_s_finished, dance_s_reset),
    [dance_t]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_t, dance_t_finished, dance_t_reset),
    [dance_g]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_g, dance_g_finished, dance_g_reset),
    [dance_m]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_m, dance_m_finished, dance_m_reset),
    [dance_n]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_n, dance_n_finished, dance_n_reset),
    [dance_e]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_e, dance_e_finished, dance_e_reset),
    [dance_i]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_i, dance_i_finished, dance_i_reset),
    [dance_o]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_o, dance_o_finished, dance_o_reset),
    // [dance_f0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f0, dance_f0_finished, dance_f0_reset),
    [dance_z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
    [dance_x] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_x, dance_x_finished, dance_x_reset),
    [dance_c] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_c, dance_c_finished, dance_c_reset),
    [dance_d] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_d, dance_d_finished, dance_d_reset),
    [dance_v] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_v, dance_v_finished, dance_v_reset),
    [dance_k] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_k, dance_k_finished, dance_k_reset),
    [dance_h] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_h, dance_h_finished, dance_h_reset),
    // [dance_f8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f8, dance_f8_finished, dance_f8_reset),
};

// const uint16_t PROGMEM test_combo1[] = {KC_Q, KC_N, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(test_combo1, KC_ESC),
// };