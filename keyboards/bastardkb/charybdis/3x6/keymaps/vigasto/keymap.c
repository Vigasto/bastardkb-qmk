/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM,
    LAYER_NAVIGATION,
    LAYER_NAVMACRO

    //TODO: adjust layer, gaming layer
};

#define NAV MO(LAYER_NAVIGATION)
#define NUM MO(LAYER_NUM)
#define NAVMACRO MO(LAYER_NAVMACRO)

#define WPUP LGUI(LCTL(KC_UP))
#define WPLEFT LGUI(LCTL(KC_LEFT))
#define WPRIGHT LGUI(LCTL(KC_RIGHT))
#define WPDOWN LGUI(LCTL(KC_DOWN))

#define SNIPMOD SNIPING_MODE
#define DRAGMOD DRAGSCROLL_MODE
#define SNIPTOG SNIPING_MODE_TOGGLE
#define DRAGTOG DRAGSCROLL_MODE_TOGGLE

// clang-format off
/* Base Layer: QWERTY
 * I did some GACS on different layouts, so miryoku hold style make sense
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   GUI  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Alt  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      |Shift | Ctrl |  Alt | GUI  |        |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
 *                                      |  Tab | Space| Bksp |  |  NUM |      | Touchpad
 *                                      |  NAV | Shift|      |  |      |      | 
 *                                      `--------------------'  `-------------'
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────╮     ╭──────────────────────────────────────────────────────────────────────────────────╮
       KC_LGUI,            KC_Q,            KC_W,            KC_E,            KC_R,    KC_T,       KC_Y,            KC_U,            KC_I,            KC_O,            KC_P, KC_ESCAPE,
  // ├──────────────────────────────────────────────────────────────────────────────────────┤     ├──────────────────────────────────────────────────────────────────────────────────┤
       KC_LALT,    LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,       KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOTE,
  // ├──────────────────────────────────────────────────────────────────────────────────────┤     ├──────────────────────────────────────────────────────────────────────────────────┤
       XXXXXXX,            KC_Z,            KC_X,            KC_C,            KC_V,    KC_B,       KC_N,            KC_M,         KC_COMM,          KC_DOT,         KC_SLSH, XXXXXXX,
  // ╰──────────────────────────────────────────────────────────────────────────────────────┤     ├──────────────────────────────────────────────────────────────────────────────────╯
                                                  LT(NAV, KC_TAB),  LSFT_T(KC_SPC), KC_BSPC,        NUM,  KC_LSFT
  //                                             ╰──────────────────────────────────────────╯     ╰──────────────────╯
  ),

/* NUM-SYMBOL : added extra 1 if somehow left pinky is busy
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   `~   |   1! |  2@  |  3#  |  4$  |  5%  |                              |  6^  |  7&  |  8*  |  9(  |  0)  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |  1!  |  -_  |  +=  |  [{  | }]   | Enter  |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |  \|  |   Fn   |
 * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
 *                                      |      |      |  Del |  |      |      | Touchpad
 *                                      |      |      |      |  |      |      |
 *                                      `--------------------'  `-------------'
*/

  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______,KC_MINUS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_BSLS, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  /* NAV, on click, not on hold
 *                                   ,--> Alt Shift drag, vscode
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |RowTxt|Sniper|                              |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      | But2 | But1 |DragSc|                              |      | Left |Bottom|Right |      |        |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
 *                                      |      |      |      |  |NAVMac|      | Touchpad 
 *                                      |      |      |      |  |      |      |
 *                                      `--------------------'  `-------------'
*/

  [LAYER_NAVIGATION] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(LALT(KC_BTN1)),   SNIPTOG,    XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2,             KC_BTN1,   DRAGMOD,    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,             _______,   XXXXXXX,   NAVMACRO, XXXXXXX
  //                            ╰─────────────────────────────────────────╯ ╰──────────────────╯
  ),

  /* NAVMacro -> arrow= GUI + Ctrl
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |WpUp  |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |WpLeft|WpBot |WpRigh|      |        |
 * |--------+------+------+------+------+------+                              +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
 *                                      |      |      |      |  |      |      | Touchpad
 *                                      |      |      |      |  |      |      |
 *                                      `--------------------'  `-------------'
*/

  [LAYER_NAVMACRO] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,    WPUP, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,   XXXXXXX,    XXXXXXX,  WPLEFT,  WPDOWN, WPRIGHT, XXXXXXX, XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______,             _______,   XXXXXXX,    _______, XXXXXXX
  //                            ╰─────────────────────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
