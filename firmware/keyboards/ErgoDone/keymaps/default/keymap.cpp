/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"



#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_1,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_Y,
        KC_2,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_H,
        KC_3,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_N,
        KC_4,  KC_5,    KC_6,    KC_7,    KC_8,    KC_9,  KC_0
    ));

void setupKeymap() {

   // no layers for SINGLE keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
#endif


#if KEYBOARD_SIDE == LEFT

/* Qwerty
 * ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  L1  |
 * |--------+------+------+------+------+-------------|
 * | '      |   Q  |   W  |   E  |   R  |   T  | TAB  |
 * |--------+------+------+------+------+------|      |
 * | "      |   A  |   S  |   D  |   F  |   G  |------|
 * |--------+------+------+------+------+------|LShift|
 * | `      |   Z  |   X  |   C  |   V  |   B  |      |
 * `--------+------+------+------+------+-------------'
 *   |  #   |  *   |  :   |   ;  | ~    |
 *   `----------------------------------'
 *                                        ,-------------.
 *                                        |  (   |   )  |
 *                                 ,------|------|------|
 *                                 |      |      |  Alt |
 *                                 | Space| Ctrl |------|
 *                                 |      |      | LGui |
 *                                 `--------------------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  LAYER_1,
        KC_QUOTE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,
        KC_DQUO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT,
           KC_HASH, KC_ASTR, KC_COLN, KC_SCLN, KC_TILD,
                                      KC_LPRN, KC_RPRN,
                                               KC_LALT,
                             KC_SPC, KC_LCTRL, KC_LGUI
    )};

void setupKeymap() {

/* Layer 1 (Raise)
 * ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  L0  |
 * |--------+------+------+------+------+-------------|
 * | '      |   Q  |   W  |   E  |   R  |   T  | TAB  |
 * |--------+------+------+------+------+------|      |
 * | "      |   A  |   S  |   D  |   F  |   G  |------|
 * |--------+------+------+------+------+------|LShift|
 * | `      |   Z  |   X  |   C  |   V  |   B  |      |
 * `--------+------+------+------+------+-------------'
 *   |  #   |  *   |  :   |   ;  | ~    |
 *   `----------------------------------'
 *                                        ,-------------.
 *                                        |  (   |   )  |
 *                                 ,------|------|------|
 *                                 |      |      |  Alt |
 *                                 | Space| Ctrl |------|
 *                                 |      |      | LGui |
 *                                 `--------------------'
 */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
RESET,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  LAYER_0,\
UF2_DFU, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,\
SERIAL_DFU,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,\
KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT,\
BLEPROFILE_1, BLEPROFILE_2, BLEPROFILE_3, KC_SCLN, KC_TILD,\
                            KC_LPRN, KC_RPRN,\
                                    KC_LALT,\
                    KC_SPC, KC_LCTRL, KC_LGUI\
);

    /* Layer 2 (lower)
 * ,------------------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |
 * |------+------+------+------+------+-------------|
 * | Del  |  F1  | F2   |  F3  | F4   |  F5  |  (   |
 * |------+------+------+------+------+------|------|
 * | Shift|  F7  | F8   |  F9  |  F10 | F11  |Space |
 * |------+------+------+------+------+------+------'
 * | Ctrl | GUI  | Alt  | L(3) | L(1) |Space |
 * `-----------------------------------------'
 */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  LAYER_1,\
KC_QUOTE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,\
KC_DQUO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,\
KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT,\
KC_HASH, KC_ASTR, KC_COLN, KC_SCLN, KC_TILD,\
                            KC_LPRN, KC_RPRN,\
                                    KC_LALT,\
                    KC_SPC, KC_LCTRL, KC_LGUI\
);

    /* Layer 3
 * ,------------------------------------------------.
 * |  `   |   F1 | F2   |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+-------------|
 * |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------|
 * | Shift|      |      |      |      |      |Space |
 * |------+------+------+------+------+------+------'
 * | Ctrl | GUI  | Alt  | L(3) | L(1) |Space |
 * `-----------------------------------------'
 */
    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  LAYER_1,\
KC_QUOTE, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,\
KC_DQUO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,\
KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT,\
KC_HASH, KC_ASTR, KC_COLN, KC_SCLN, KC_TILD,\
                            KC_LPRN, KC_RPRN,\
                                    KC_LALT,\
                    KC_SPC, KC_LCTRL, KC_LGUI\
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, layer3[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}

#endif  // left



#if KEYBOARD_SIDE == RIGHT

/* Qwerty
 *   ,--------------------------------------------------.
 *   |  L2  |   6  |   7  |   8  |   9  |   0  |  BSPC  |
 *   |------+------+------+------+------+------+--------|
 *   |  P   |   Y  |   U  |   I  |   O  |   P  |   -    |
 *   |  Up  |------+------+------+------+------+--------|
 *   |------|   H  |   J  |   K  |   L  |  @   |   +    |
 *   |  P   |------+------+------+------+------+--------|
 *   | Down |   N  |   M  |   Ø  |   Æ  |  å   |   =    |
 *   `-------------+------+------+------+------+--------'
 *                 |  ,   |  .   |   /  |   \  |  |   |
 *                 `----------------------------------'
 * ,-------------.
 * |  <-  |  ->  |
 * |------+------+------.
 * |  Up  |      |      |
 * |------| Ctrl |Enter |
 * | Down |      |      |
 * `----------------------'
 */
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
            LAYER_2,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPACE,
            KC_PGUP,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINUS,
                      KC_H,    KC_J,    KC_K,    KC_L,    KC_AT,     KC_PLUS,
            KC_PGDN,  KC_N,    KC_M,    KC_OE,   KC_AE,   KC_AA,     KC_EQUAL,
                               KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH, KC_PIPE,
        KC_LEFT, KC_RIGHT,
        KC_UP,
        KC_DOWN, KC_RCTRL, KC_ENTER
    )};

void setupKeymap() {

/* Layer 1 (Raise)
 *   ,--------------------------------------------------.
 *   |  L2  |   6  |   7  |   8  |   9  |   0  |  BSPC  |
 *   |------+------+------+------+------+------+--------|
 *   |  P   |   Y  |   U  |   I  |   O  |   P  |   -    |
 *   |  Up  |------+------+------+------+------+--------|
 *   |------|   H  |   J  |   K  |   L  |  @   |   +    |
 *   |  P   |------+------+------+------+------+--------|
 *   | Down |   N  |   M  |   Ø  |   Æ  |  å   |   =    |
 *   `-------------+------+------+------+------+--------'
 *                 |  ,   |  .   |   /  |   \  |  |   |
 *                 `----------------------------------'
 * ,-------------.
 * |  <-  |   ->   |
 * |------+--------+------.
 * |  Up  |        |      |
 * |------|  Ctrl  |Enter |
 * | Down |        |      |
 * `----------------------'
 */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    LAYER_0,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,KC_DELETE,\
    KC_PGUP,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      RESET,\
                KC_H,    KC_J,    KC_K,    KC_L,    KC_AT,   UF2_DFU,\
    KC_PGDN,  KC_N,    KC_M,    KC_OE,   KC_AE,   KC_AA,     SERIAL_DFU,\
                        PRINT_BATTERY, PRINT_INFO, PRINT_BLE, KC_BSLASH, KC_PIPE,\
KC_LEFT, KC_RIGHT,\
KC_UP,\
KC_DOWN, KC_RCTRL, KC_ENTER \
);

    /* Layer 2 (lower)
 * ,------------------------------------------------.
 * |   =  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------|
 * |   [  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------|
 * | Space| F12  |ISO ~ |ISO | |      |      |      |
 * `------+------+------+------+------+------+------|
 *        | Space| L(2) | Left | Down |  Up  |Right |
 *        `-----------------------------------------'
 */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    LAYER_2,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPACE,\
    KC_PGUP,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINUS,\
                KC_H,    KC_J,    KC_K,    KC_L,    KC_AT,     KC_PLUS,\
    KC_PGDN,  KC_N,    KC_M,    KC_OE,   KC_AE,   KC_AA,     KC_EQUAL,\
                        KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH, KC_PIPE,\
KC_LEFT, KC_RIGHT,\
KC_UP,\
KC_DOWN, KC_RCTRL, KC_ENTER \
);

    /* Layer 3
 * ,------------------------------------------------.
 * |   =  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------|
 * |   [  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------|
 * | Space| F12  |ISO ~ |ISO | |      |      |      |
 * `------+------+------+------+------+------+------|
 *        | Space| L(2) | Left | Down |  Up  |Right |
 *        `-----------------------------------------'
 */
    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
    LAYER_2,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPACE,\
    KC_PGUP,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINUS,\
                KC_H,    KC_J,    KC_K,    KC_L,    KC_AT,     KC_PLUS,\
    KC_PGDN,  KC_N,    KC_M,    KC_OE,   KC_AE,   KC_AA,     KC_EQUAL,\
                        KC_COMMA, KC_DOT, KC_SLASH, KC_BSLASH, KC_PIPE,\
KC_LEFT, KC_RIGHT,\
KC_UP,\
KC_DOWN, KC_RCTRL, KC_ENTER \
);

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, layer3[row][col]);
        }
    }

}


#endif




