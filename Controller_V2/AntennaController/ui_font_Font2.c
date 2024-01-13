/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:\Mac\Home\Documents\SquareLine\assets\Slipstream LET Plain.1.0.ttf -o C:\Mac\Home\Documents\SquareLine\assets\ui_font_Font2.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT2
#define UI_FONT_FONT2 1
#endif

#if UI_FONT_FONT2

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x3, 0xc0, 0xf8, 0x3f, 0x7, 0xc1, 0xf0, 0x3e,
    0xf, 0x80, 0x0, 0x7c, 0xf, 0x81, 0xe0, 0x0,

    /* U+0022 "\"" */
    0x3f, 0x7f, 0xbf, 0x9d, 0xce, 0xc0,

    /* U+0023 "#" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0024 "$" */
    0x0, 0xf8, 0x3, 0xc0, 0x0, 0x3, 0xff, 0x1f,
    0xf8, 0x7e, 0x1, 0xfe, 0x3, 0xf8, 0x3, 0xf0,
    0xf, 0x87, 0xfe, 0x3f, 0xf0, 0x80, 0x1, 0xfe,
    0x7, 0x80, 0x0,

    /* U+0025 "%" */
    0x3f, 0xf, 0x3f, 0xdf, 0x3f, 0xff, 0x1f, 0xff,
    0x7, 0xff, 0x1, 0xff, 0xf0, 0x3f, 0xfc, 0x3f,
    0xfe, 0x3f, 0xff, 0x3e, 0xff, 0x1e, 0x1f, 0x0,

    /* U+0026 "&" */
    0x3, 0xf8, 0x3f, 0xc1, 0xff, 0x7, 0xc0, 0x1f,
    0xfc, 0xff, 0xe7, 0xff, 0xbf, 0xf8, 0xff, 0xe3,
    0xff, 0x3, 0xfc, 0x0,

    /* U+0027 "'" */
    0xb7, 0xbd, 0xce, 0x0,

    /* U+0028 "(" */
    0x3, 0xe0, 0x78, 0x3e, 0xf, 0x83, 0xe0, 0xf8,
    0x1f, 0x7, 0xc0, 0xf8, 0x1f, 0x3, 0xc0, 0x38,
    0xf, 0x0,

    /* U+0029 ")" */
    0x1, 0xe0, 0x3c, 0x7, 0x81, 0xf0, 0x3e, 0x7,
    0xc1, 0xf0, 0x3e, 0xf, 0x83, 0xe0, 0xf8, 0xe,
    0xf, 0x80,

    /* U+002A "*" */
    0xd, 0xc3, 0xe1, 0xfe, 0x1f, 0xf, 0x70,

    /* U+002B "+" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+002C "," */
    0x1f, 0x1f, 0xe, 0x3c, 0x78, 0xf8,

    /* U+002D "-" */
    0x7f, 0x3e, 0xfe,

    /* U+002E "." */
    0x7d, 0xf7, 0x80,

    /* U+002F "/" */
    0x0, 0x3, 0xc0, 0x0, 0x70, 0x0, 0x3c, 0x0,
    0x1f, 0x0, 0x7, 0xc0, 0x1, 0xf0, 0x0, 0x7c,
    0x0, 0x1e, 0x0, 0xf, 0x80, 0x3, 0xe0, 0x0,
    0xf8, 0x0, 0xe, 0x0, 0xf, 0x80, 0x0,

    /* U+0030 "0" */
    0x1, 0xf8, 0x1f, 0xf8, 0x7f, 0xf1, 0xfb, 0xf7,
    0xe7, 0xcf, 0x8f, 0xbf, 0x3f, 0x7e, 0xfc, 0xff,
    0xf0, 0xff, 0xc0, 0x7e, 0x0,

    /* U+0031 "1" */
    0xf, 0xcf, 0xf3, 0xf8, 0x3e, 0x1f, 0x7, 0xc3,
    0xe0, 0xf8, 0x7c, 0x1f, 0x7, 0x80,

    /* U+0032 "2" */
    0x3, 0xf8, 0x1f, 0xf0, 0xff, 0xc0, 0x3f, 0x1,
    0xf8, 0x1f, 0xc1, 0xfc, 0xf, 0xc0, 0x7f, 0xe1,
    0xff, 0x87, 0xfc, 0x0,

    /* U+0033 "3" */
    0x1, 0xf8, 0x1f, 0xe0, 0x7f, 0xc0, 0x3e, 0x7,
    0xf0, 0x3f, 0x80, 0xff, 0x0, 0xfc, 0x7f, 0xe1,
    0xff, 0x7, 0xf0, 0x0,

    /* U+0034 "4" */
    0x0, 0x7c, 0x7, 0xf0, 0x7f, 0x83, 0xfe, 0x1f,
    0xf0, 0xff, 0xc7, 0xff, 0x9f, 0xfc, 0xff, 0xe0,
    0x3f, 0x0, 0x78, 0x0,

    /* U+0035 "5" */
    0x3, 0xfc, 0x1f, 0xe0, 0xff, 0x87, 0xc0, 0x1f,
    0xe0, 0xff, 0x80, 0x7f, 0x1, 0xf8, 0x7f, 0xe3,
    0xff, 0x7, 0xf0, 0x0,

    /* U+0036 "6" */
    0x1, 0xf0, 0x7e, 0xf, 0x81, 0xfe, 0x3f, 0xe7,
    0xff, 0x7f, 0xff, 0xfe, 0xff, 0xe7, 0xfc, 0x1f,
    0x0,

    /* U+0037 "7" */
    0x7, 0xfc, 0x7f, 0xe1, 0xff, 0x0, 0xf8, 0x7,
    0xc0, 0x3e, 0x1, 0xf0, 0xf, 0x80, 0x3e, 0x1,
    0xf0, 0x7, 0xc0, 0x0,

    /* U+0038 "8" */
    0x1, 0xf8, 0x1f, 0xf0, 0xff, 0xc3, 0xfe, 0xf,
    0xf0, 0xff, 0xc7, 0xff, 0x1f, 0x7c, 0x7f, 0xe1,
    0xff, 0x1, 0xf8, 0x0,

    /* U+0039 "9" */
    0xf, 0xc7, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf3, 0xfc, 0x3f, 0xf, 0xc1, 0xf0, 0x0,

    /* U+003A ":" */
    0x1f, 0x1f, 0x3e, 0x0, 0x7c, 0x7c, 0x78,

    /* U+003B ";" */
    0x7, 0xc1, 0xf0, 0xf8, 0x0, 0x1f, 0x7, 0xc0,
    0xe0, 0x70, 0x78, 0x3e, 0x0,

    /* U+003C "<" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+003D "=" */
    0x0, 0x7, 0x0, 0xf, 0x0, 0xf, 0x0, 0x1f,
    0x0, 0x1f, 0x0, 0x1f, 0x0, 0x1f, 0x0, 0x1f,
    0x0, 0x3e, 0x0, 0x3e, 0x0, 0x1e, 0x0, 0x0,

    /* U+003E ">" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+003F "?" */
    0xf, 0xe3, 0xfc, 0xff, 0x81, 0xf0, 0xfc, 0x3e,
    0xf, 0x80, 0x0, 0x7c, 0x1f, 0x1, 0xe0, 0x0,

    /* U+0040 "@" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0041 "A" */
    0x0, 0x3e, 0x1, 0xfc, 0x7, 0xf8, 0x1f, 0xe0,
    0x7f, 0xc1, 0xff, 0x87, 0xff, 0xf, 0xfe, 0x3e,
    0xfc, 0xf9, 0xf1, 0xe1, 0xe0,

    /* U+0042 "B" */
    0x3, 0xfc, 0x1f, 0xf0, 0xff, 0xc3, 0xff, 0x1f,
    0xf8, 0x7f, 0xc3, 0xff, 0xf, 0xfc, 0x7f, 0xf1,
    0xff, 0x87, 0xfc, 0x0,

    /* U+0043 "C" */
    0x1, 0xf8, 0x3f, 0xe1, 0xff, 0xf, 0xc0, 0x7e,
    0x1, 0xf0, 0xf, 0xc0, 0x3f, 0x0, 0xff, 0x81,
    0xfe, 0x1, 0xf0, 0x0,

    /* U+0044 "D" */
    0x3, 0xfc, 0xf, 0xfc, 0x3f, 0xf8, 0x7d, 0xf1,
    0xf3, 0xe3, 0xef, 0xcf, 0x9f, 0x1f, 0xfe, 0x7f,
    0xf8, 0xff, 0xe1, 0xff, 0x0,

    /* U+0045 "E" */
    0x3, 0xfc, 0xf, 0xf8, 0x3f, 0xe0, 0x7c, 0x1,
    0xff, 0x3, 0xfe, 0xf, 0xf8, 0x1f, 0x0, 0x7f,
    0xc0, 0xff, 0x81, 0xfe, 0x0,

    /* U+0046 "F" */
    0x3, 0xfc, 0x1f, 0xf0, 0xff, 0x83, 0xe0, 0x1f,
    0xf0, 0x7f, 0xc3, 0xfe, 0xf, 0x80, 0x7c, 0x1,
    0xf0, 0x7, 0x80, 0x0,

    /* U+0047 "G" */
    0x1, 0xfe, 0x1f, 0xf8, 0x7f, 0xf1, 0xf8, 0x7,
    0xe0, 0xf, 0x80, 0x3f, 0x7c, 0x7e, 0xf8, 0xff,
    0xe0, 0xff, 0xc0, 0x7f, 0x0,

    /* U+0048 "H" */
    0x3, 0xc7, 0x83, 0xef, 0x83, 0xe7, 0xc1, 0xf7,
    0xc1, 0xff, 0xe0, 0xff, 0xe0, 0xff, 0xe0, 0x7d,
    0xf0, 0x7d, 0xf0, 0x3e, 0xf8, 0x1e, 0x78, 0x0,

    /* U+0049 "I" */
    0x3, 0xc0, 0xf8, 0x3e, 0x7, 0xc1, 0xf0, 0x3e,
    0xf, 0x81, 0xf0, 0x7c, 0xf, 0x81, 0xe0, 0x0,

    /* U+004A "J" */
    0x0, 0xf0, 0xf, 0x80, 0xf8, 0x7, 0xc0, 0x7c,
    0x3, 0xe0, 0x3e, 0x1, 0xf0, 0x7f, 0x7, 0xf8,
    0x1f, 0x80,

    /* U+004B "K" */
    0x3, 0xcf, 0x3, 0xff, 0x3, 0xff, 0x1, 0xff,
    0x1, 0xfe, 0x0, 0xff, 0x0, 0xff, 0x80, 0x7f,
    0xc0, 0x7f, 0xe0, 0x3f, 0xf0, 0x1e, 0x78, 0x0,

    /* U+004C "L" */
    0x3, 0xc0, 0xf8, 0x3e, 0x7, 0xc1, 0xf0, 0x3e,
    0xf, 0x81, 0xf0, 0x7f, 0xcf, 0xf1, 0xfe, 0x0,

    /* U+004D "M" */
    0x3, 0xe3, 0xc1, 0xfb, 0xf0, 0xff, 0xf8, 0x3f,
    0xfe, 0x1f, 0xff, 0x7, 0xff, 0x83, 0xff, 0xe0,
    0xf9, 0xf0, 0x7c, 0x7c, 0x1f, 0x3e, 0x7, 0x87,
    0x80,

    /* U+004E "N" */
    0x3, 0xe7, 0x83, 0xff, 0x83, 0xff, 0xc1, 0xff,
    0xc1, 0xff, 0xe0, 0xff, 0xe0, 0xff, 0xf0, 0x7f,
    0xf0, 0x7d, 0xf8, 0x3e, 0xf8, 0x1e, 0x3c, 0x0,

    /* U+004F "O" */
    0x1, 0xfc, 0x1f, 0xfc, 0x7f, 0xf9, 0xf9, 0xf7,
    0xe3, 0xef, 0x87, 0xff, 0x1f, 0xfe, 0x7e, 0xff,
    0xf8, 0xff, 0xe0, 0x7f, 0x0,

    /* U+0050 "P" */
    0x3, 0xf8, 0x1f, 0xf0, 0xff, 0xc3, 0xff, 0x1f,
    0xf8, 0x7f, 0xe3, 0xfe, 0xf, 0x80, 0x7c, 0x1,
    0xf0, 0x7, 0x80, 0x0,

    /* U+0051 "Q" */
    0x1, 0xfc, 0x1f, 0xfc, 0x7f, 0xf9, 0xf9, 0xf7,
    0xe3, 0xef, 0x87, 0xff, 0x1f, 0x7e, 0x7e, 0xff,
    0xfe, 0xff, 0xf8, 0x7f, 0xe0,

    /* U+0052 "R" */
    0x3, 0xfc, 0xf, 0xf8, 0x3f, 0xf8, 0x7f, 0xe1,
    0xff, 0xc3, 0xff, 0xf, 0xf8, 0x1f, 0xf8, 0x7d,
    0xf0, 0xfb, 0xe1, 0xe1, 0xe0,

    /* U+0053 "S" */
    0x1, 0xfc, 0x1f, 0xf0, 0xff, 0x83, 0xf0, 0xf,
    0xe0, 0x1f, 0xc0, 0x3f, 0x0, 0xfc, 0x7f, 0xf1,
    0xff, 0x87, 0xf8, 0x0,

    /* U+0054 "T" */
    0x1f, 0xf3, 0xff, 0x7f, 0xe1, 0xf0, 0x1f, 0x3,
    0xe0, 0x3e, 0x7, 0xc0, 0x7c, 0xf, 0x80, 0x78,
    0x0,

    /* U+0055 "U" */
    0x7, 0x9e, 0xf, 0xbe, 0x1f, 0x7c, 0x1f, 0x7c,
    0x3e, 0xf8, 0x7e, 0xf8, 0x7d, 0xf0, 0x7d, 0xf0,
    0xff, 0xe0, 0xff, 0xc0, 0x3f, 0x80,

    /* U+0056 "V" */
    0x1e, 0x3c, 0x7d, 0xf8, 0xff, 0xe1, 0xff, 0x87,
    0xfe, 0xf, 0xf8, 0x1f, 0xe0, 0x3f, 0xc0, 0xff,
    0x1, 0xfc, 0x1, 0xf0, 0x0,

    /* U+0057 "W" */
    0x1e, 0x7c, 0xf1, 0xf7, 0xdf, 0xf, 0xff, 0xf8,
    0x7f, 0xff, 0x87, 0xff, 0xf8, 0x3f, 0xff, 0x81,
    0xff, 0xf8, 0xf, 0xff, 0xc0, 0xff, 0xfc, 0x7,
    0xef, 0xc0, 0x1f, 0x7c, 0x0,

    /* U+0058 "X" */
    0x1, 0xe7, 0x80, 0xff, 0xc0, 0x3f, 0xe0, 0xf,
    0xf0, 0x3, 0xf8, 0x1, 0xfc, 0x0, 0xff, 0x0,
    0x7f, 0xe0, 0x3f, 0xf8, 0x1f, 0xfe, 0x7, 0xcf,
    0x80,

    /* U+0059 "Y" */
    0x1e, 0x7c, 0xff, 0xe3, 0xff, 0xf, 0xf8, 0x3f,
    0xc0, 0xfe, 0x3, 0xf0, 0xf, 0x80, 0x7c, 0x1,
    0xf0, 0x7, 0x80, 0x0,

    /* U+005A "Z" */
    0x1, 0xff, 0x3, 0xff, 0x1, 0xff, 0x0, 0x3f,
    0x0, 0x3f, 0x0, 0x3f, 0x0, 0x3f, 0x0, 0x3f,
    0x0, 0x3f, 0xf0, 0x3f, 0xf8, 0x1f, 0xf8, 0x0,

    /* U+005B "[" */
    0x1, 0xfc, 0x3, 0xe0, 0x3f, 0x81, 0xe0, 0x7,
    0x80, 0x3c, 0x0, 0xf0, 0x7, 0x80, 0x3e, 0x0,
    0xf0, 0x7, 0xf8, 0x7, 0xc0, 0xff, 0x0,

    /* U+005C "\\" */
    0xf8, 0x1c, 0x1e, 0xf, 0x87, 0xc1, 0xe0, 0xf8,
    0x3c, 0x1f, 0xf, 0x81, 0xc0, 0xf0, 0xf8,

    /* U+005D "]" */
    0x1, 0xfc, 0x3, 0xe0, 0x3f, 0x80, 0x3c, 0x1,
    0xf0, 0x7, 0x80, 0x3e, 0x0, 0xf0, 0x7, 0xc0,
    0x1e, 0x7, 0xf8, 0x7, 0xc0, 0xff, 0x0,

    /* U+005E "^" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x7f,

    /* U+005F "_" */
    0xff, 0xff, 0xff,

    /* U+0060 "`" */
    0xff, 0xde,

    /* U+0061 "a" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0062 "b" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0063 "c" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0064 "d" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0065 "e" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0066 "f" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0067 "g" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0068 "h" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0069 "i" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+006A "j" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+006B "k" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+006C "l" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+006D "m" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+006E "n" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+006F "o" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0070 "p" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0071 "q" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0072 "r" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0073 "s" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0074 "t" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0075 "u" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0076 "v" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0077 "w" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0078 "x" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0079 "y" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+007A "z" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+007B "{" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+007C "|" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+007D "}" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+007E "~" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x7f
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 82, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 102, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 148, .box_w = 9, .box_h = 5, .ofs_x = 4, .ofs_y = 6},
    {.bitmap_index = 23, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 162, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 280, .box_w = 17, .box_h = 11, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 196, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 85, .box_w = 5, .box_h = 5, .ofs_x = 4, .ofs_y = 6},
    {.bitmap_index = 107, .adv_w = 119, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 125, .adv_w = 119, .box_w = 11, .box_h = 13, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 143, .adv_w = 143, .box_w = 11, .box_h = 5, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 150, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 95, .box_w = 8, .box_h = 6, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 165, .adv_w = 126, .box_w = 8, .box_h = 3, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 168, .adv_w = 95, .box_w = 6, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 193, .box_w = 19, .box_h = 13, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 202, .adv_w = 199, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 110, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 153, .box_w = 14, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 150, .box_w = 14, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 174, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 153, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 166, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 134, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 163, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 163, .box_w = 11, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 97, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 95, .box_w = 10, .box_h = 10, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 410, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 51, .box_w = 17, .box_h = 11, .ofs_x = -7, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 149, .box_w = 11, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 189, .box_w = 15, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 168, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 154, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 538, .adv_w = 192, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 160, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 151, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 186, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 195, .box_w = 17, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 96, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 114, .box_w = 13, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 172, .box_w = 17, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 131, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 219, .box_w = 18, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 198, .box_w = 17, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 768, .adv_w = 214, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 789, .adv_w = 167, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 214, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 830, .adv_w = 182, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 851, .adv_w = 145, .box_w = 14, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 147, .box_w = 12, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 189, .box_w = 16, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 910, .adv_w = 175, .box_w = 15, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 931, .adv_w = 271, .box_w = 21, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 960, .adv_w = 183, .box_w = 18, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 985, .adv_w = 164, .box_w = 14, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1005, .adv_w = 165, .box_w = 17, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1029, .adv_w = 129, .box_w = 14, .box_h = 13, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 1052, .adv_w = 231, .box_w = 9, .box_h = 13, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 1067, .adv_w = 129, .box_w = 14, .box_h = 13, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 1090, .adv_w = 102, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1099, .adv_w = 128, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 1102, .adv_w = 99, .box_w = 5, .box_h = 3, .ofs_x = 7, .ofs_y = 12},
    {.bitmap_index = 1104, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1113, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1122, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1131, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1149, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1158, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1167, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1176, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1185, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1194, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1203, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1212, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1221, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1230, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1239, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1248, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1257, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1266, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1275, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1284, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1293, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1302, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1311, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1320, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1329, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1338, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1347, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1356, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1365, .adv_w = 102, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    14, 34,
    14, 53,
    14, 55,
    14, 56,
    14, 58,
    34, 14,
    34, 36,
    34, 40,
    34, 48,
    34, 50,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 58,
    37, 34,
    37, 55,
    37, 56,
    37, 58,
    39, 13,
    39, 15,
    39, 34,
    40, 58,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    45, 34,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    48, 34,
    48, 53,
    48, 55,
    48, 56,
    48, 57,
    48, 58,
    49, 13,
    49, 15,
    49, 34,
    49, 58,
    50, 54,
    51, 53,
    51, 55,
    51, 56,
    51, 58,
    53, 13,
    53, 14,
    53, 15,
    53, 27,
    53, 28,
    53, 34,
    53, 48,
    55, 13,
    55, 14,
    55, 15,
    55, 27,
    55, 28,
    55, 34,
    55, 48,
    56, 13,
    56, 14,
    56, 15,
    56, 27,
    56, 28,
    56, 34,
    56, 48,
    57, 48,
    58, 13,
    58, 14,
    58, 15,
    58, 27,
    58, 28,
    58, 34,
    58, 36,
    58, 40,
    58, 48
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -3, -21, -10, -10, -24, -8, -8, -8,
    -8, -8, -16, -10, -16, -16, -21, -3,
    -7, -5, -16, -28, -28, -10, -10, -5,
    -5, -5, -5, 13, -16, -13, -13, -26,
    -3, -5, -8, -8, -10, -16, -26, -26,
    -17, -13, 3, -5, -5, -8, -10, -26,
    -21, -26, -18, -18, -16, -3, -24, -8,
    -24, -7, -7, -13, -3, -24, -13, -24,
    -7, -7, -13, -3, -12, -24, -13, -24,
    -16, -16, -21, -3, -3, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 78,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Font2 = {
#else
lv_font_t ui_font_Font2 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT2*/
