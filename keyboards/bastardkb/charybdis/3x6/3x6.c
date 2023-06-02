/*
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
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

#include "3x6.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
/**
 * \brief LEDs index.
 *
 #  0,0  14  28  42  56  70  84  98    126 140 154 168 182 196 210 224,0
 #  0,0  15  30  45  60  75  90 105    119 134 149 164 179 194 209 224,0
 * ╭────────────────────────╮                 ╭────────────────────────╮
 *    0   5   6  11  12  15                     36  33  32  27  26  21
 * ├────────────────────────┤                 ├────────────────────────┤
 *    1   4   7  10  13  16                     37  34  31  28  25  22
 * ├────────────────────────┤                 ├────────────────────────┤
 *    2   3   8   9  14  17                     38  35  30  29  24  23
 * ╰────────────────────────╯                 ╰────────────────────────╯ old
 *                       18  19  20     39  40  XX
 *                     ╰────────────╯ ╰────────────╯
 * 
 * ╭────────────────────────╮                 ╭────────────────────────╮
 *   20  19  18  17  16  15                     35  36  37  38  39  40
 * ├────────────────────────┤                 ├────────────────────────┤
 *    9  10  11  12  13  14                     34  33  32  31  30  29
 * ├────────────────────────┤                 ├────────────────────────┤
 *    8   7   6   5   4   3                     23  24  25  26  27  28
 * ╰────────────────────────╯                 ╰────────────────────────╯  my wiring lol
 *                        0   1   2     22  21  XX
 *                     ╰────────────╯ ╰────────────╯
 *
 * Note: the LED config simulates 42 LEDs instead of the actual 41 to prevent
 * confusion when testing LEDs during assembly when handedness is not set
 * correctly.  Those fake LEDs are bound to the physical top-left corner.
 */
led_config_t g_led_config = { {
    /* Key Matrix to LED index. */
    // Left split.
    {     20,     19,     18,     17,     16,     15 }, // Top row
    {      9,     10,     11,     12,     13,     14 }, // Middle row
    {      8,      7,      6,      5,      4,      3 }, // Bottom row
    { NO_LED, NO_LED, NO_LED,      0,      1,      2 }, // Thumb cluster
    // Right split.
    {     35,     36,     37,     38,     39,     40 }, // Top row
    {     34,     33,     32,     31,     30,     29 }, // Middle row
    {     23,     24,     25,     26,     27,     28 }, // Bottom row
    {     22,     21, NO_LED, NO_LED, NO_LED, NO_LED }, // Thumb cluster
}, {
    /* LED index to physical position. */
    // Left split.
    /* index=0  */ {  75,  64 }, {  90,  64 }, { 105,  64 }, // row 4 (bottom)
    /* index=3  */ {  75,  42 }, {  60,  42 }, {  45,  42 }, {  30,  42 }, {  15,  42 }, {  0,  42 }, //row 3
    /* index=9  */ {   0,  21 }, {  15,  21 }, {  30,  21 }, {  45,  21 }, {  60,  21 }, {  75, 21 }, //row 2
    /* index=15 */ {  75,   0 }, {  60,   0 }, {  45,   0 }, {  30,   0 }, {  15,   0 }, {  0,   0 }, //row 1
    // Right split.
    /* index=21 */ { 136,  64 }, { 119,  64 }, // row 4 (bottom)
    /* index=23 */ { 149,  42 }, { 164,  42 }, { 179,  42 }, { 194,  42 }, { 209,  42 }, { 224, 42 }, //row 3
    /* index=29 */ { 224,  21 }, { 209,  21 }, { 194,  21 }, { 179,  21 }, { 164,  21 }, { 149, 21 }, //row 2
    /* index=35 */ { 149,   0 }, { 179,   0 }, { 194,   0 }, { 209,   0 }, { 224,  0 },  { 164,  0 }, //row 1
}, {
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 1
    /* index=3  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 2
    /* index=6  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=9  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=12 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=15 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=18 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // Thumb cluster
    // Right split.
    /* index=21 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 10
    /* index=24 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 9
    /* index=27 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=30 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=33 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=36 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=39 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // Thumb cluster
} };
#endif
// clang-format on
