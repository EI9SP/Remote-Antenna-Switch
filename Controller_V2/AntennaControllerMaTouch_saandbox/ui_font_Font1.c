/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:\Mac\Home\Documents\SquareLine\assets\TelidonRg Italic.ttf -o C:\Mac\Home\Documents\SquareLine\assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x28, 0x24, 0x0, 0x80,

    /* U+0022 "\"" */
    0x90, 0x9a,

    /* U+0023 "#" */
    0x18, 0x60, 0x1b, 0x32, 0xc0, 0x14, 0x60,

    /* U+0024 "$" */
    0x13, 0x41, 0xb, 0x0, 0x1c, 0x40,

    /* U+0025 "%" */
    0x52, 0xa8, 0x0, 0x41, 0x4, 0x0, 0x2c, 0xa8,

    /* U+0026 "&" */
    0x11, 0x80, 0x45, 0xc8, 0x12, 0xb0,

    /* U+0027 "'" */
    0x4a,

    /* U+0028 "(" */
    0x28, 0x49, 0x4, 0x80,

    /* U+0029 ")" */
    0x22, 0x1, 0x22, 0x4, 0x80,

    /* U+002A "*" */
    0x4a, 0xba, 0x6, 0x50,

    /* U+002B "+" */
    0x2b, 0x0,

    /* U+002C "," */
    0x2a, 0x0,

    /* U+002D "-" */
    0xb0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x2, 0x8, 0x0, 0x41, 0x4, 0x0, 0x20, 0x80,

    /* U+0030 "0" */
    0x18, 0x90, 0x11, 0x46, 0x0, 0x14, 0x60,

    /* U+0031 "1" */
    0x38, 0x24, 0x4, 0x80,

    /* U+0032 "2" */
    0x2d, 0x10, 0x1, 0x8, 0x0, 0x10, 0xe8,

    /* U+0033 "3" */
    0x5a, 0x8, 0x0, 0x40, 0x81, 0x0, 0x48, 0x60,

    /* U+0034 "4" */
    0x4, 0x50, 0xa, 0x4a, 0xc0, 0x4, 0x10,

    /* U+0035 "5" */
    0x5a, 0x80, 0x3, 0x40, 0x80, 0x0, 0x8, 0xe0,

    /* U+0036 "6" */
    0x8, 0x80, 0x45, 0xc0, 0x11, 0xb0,

    /* U+0037 "7" */
    0xb4, 0x20, 0x4, 0x21, 0x0, 0x20, 0x80,

    /* U+0038 "8" */
    0x2d, 0x10, 0xa, 0x5a, 0x0, 0x22, 0xb0,

    /* U+0039 "9" */
    0x5c, 0x41, 0x1b, 0x10, 0x8, 0x80,

    /* U+003A ":" */
    0x50, 0xa0,

    /* U+003B ";" */
    0x11, 0x0, 0x24, 0x80,

    /* U+003C "<" */
    0x4, 0x40, 0x10, 0x81, 0x0, 0x8, 0x10,

    /* U+003D "=" */
    0x70, 0x9,

    /* U+003E ">" */
    0x40, 0x40, 0x2, 0x4, 0x40, 0x10, 0x80,

    /* U+003F "?" */
    0x5c, 0x40, 0x22, 0x0, 0x0, 0x40,

    /* U+0040 "@" */
    0x2d, 0x10, 0x13, 0x56, 0x40, 0x20, 0xb0,

    /* U+0041 "A" */
    0x8, 0x60, 0xa, 0x46, 0xc0, 0x22, 0x88,

    /* U+0042 "B" */
    0x58, 0x90, 0x9, 0x59, 0x0, 0x12, 0xe0,

    /* U+0043 "C" */
    0x2d, 0x10, 0x10, 0x42, 0x0, 0x22, 0xb0,

    /* U+0044 "D" */
    0x58, 0x90, 0x9, 0x45, 0x0, 0x14, 0xe0,

    /* U+0045 "E" */
    0x5a, 0x80, 0x2, 0x7, 0x10, 0x0, 0x40, 0xe8,

    /* U+0046 "F" */
    0x5a, 0x80, 0x2, 0x7, 0x10, 0x0, 0x40, 0x80,

    /* U+0047 "G" */
    0x2d, 0x10, 0x10, 0x56, 0x0, 0x22, 0xb0,

    /* U+0048 "H" */
    0x42, 0x88, 0x2, 0x27, 0x50, 0x0, 0x44, 0x88,

    /* U+0049 "I" */
    0x59, 0x0, 0x42, 0x0, 0x8, 0xe0,

    /* U+004A "J" */
    0x2, 0x8, 0x0, 0x20, 0x40, 0x0, 0x44, 0x60,

    /* U+004B "K" */
    0x45, 0x20, 0x14, 0x62, 0x0, 0x24, 0x90,

    /* U+004C "L" */
    0x42, 0x0, 0x84, 0x40, 0x10, 0xe8,

    /* U+004D "M" */
    0x42, 0x48, 0x3, 0x65, 0x50, 0x0, 0x44, 0x88,

    /* U+004E "N" */
    0x42, 0x48, 0x3, 0x25, 0x52, 0x0, 0x48, 0x88,

    /* U+004F "O" */
    0x2d, 0x10, 0x11, 0x46, 0x0, 0x22, 0xb0,

    /* U+0050 "P" */
    0x59, 0x10, 0x11, 0x72, 0x0, 0x20, 0x80,

    /* U+0051 "Q" */
    0x2d, 0x10, 0x11, 0x46, 0x0, 0x24, 0xa8,

    /* U+0052 "R" */
    0x59, 0x10, 0x11, 0x72, 0x40, 0x24, 0x88,

    /* U+0053 "S" */
    0x2d, 0x10, 0x10, 0x58, 0x0, 0x22, 0xb0,

    /* U+0054 "T" */
    0xea, 0x0, 0x84, 0x0, 0x10, 0x80,

    /* U+0055 "U" */
    0x42, 0x88, 0x2, 0x24, 0x50, 0x0, 0x44, 0xb0,

    /* U+0056 "V" */
    0x86, 0x20, 0x22, 0x8a, 0x40, 0x28, 0x40,

    /* U+0057 "W" */
    0x42, 0x88, 0x2, 0x25, 0x50, 0x0, 0x6c, 0x90,

    /* U+0058 "X" */
    0x42, 0x48, 0x1, 0x41, 0x6, 0x0, 0x28, 0x88,

    /* U+0059 "Y" */
    0x8c, 0x81, 0x44, 0x0, 0x10, 0x80,

    /* U+005A "Z" */
    0x5a, 0x8, 0x0, 0x41, 0x4, 0x0, 0x20, 0xe8,

    /* U+005B "[" */
    0x30, 0x24, 0x40, 0x48, 0x80, 0x8c,

    /* U+005C "\\" */
    0x80, 0x84, 0x40, 0x2, 0x20, 0x22,

    /* U+005D "]" */
    0x28, 0x4, 0x21, 0x0, 0x4, 0x20, 0x11, 0x80,

    /* U+005E "^" */
    0x21, 0xd0,

    /* U+005F "_" */
    0xb8,

    /* U+0060 "`" */
    0xc0,

    /* U+0061 "a" */
    0x68, 0x5a, 0x9, 0x54,

    /* U+0062 "b" */
    0x41, 0x0, 0x1a, 0x46, 0x0, 0x22, 0xe0,

    /* U+0063 "c" */
    0x3a, 0x20, 0x8, 0x58,

    /* U+0064 "d" */
    0x2, 0x8, 0x1, 0x64, 0x50, 0x0, 0x44, 0x68,

    /* U+0065 "e" */
    0x39, 0x1b, 0x0, 0x82, 0xc0,

    /* U+0066 "f" */
    0x19, 0x1, 0xa4, 0x20, 0x10, 0x80,

    /* U+0067 "g" */
    0x2d, 0x10, 0x20, 0x89, 0xa0, 0x4, 0xd0,

    /* U+0068 "h" */
    0x41, 0x0, 0x1a, 0x46, 0x0, 0x22, 0x88,

    /* U+0069 "i" */
    0x10, 0x6, 0x20, 0x4, 0xe0,

    /* U+006A "j" */
    0x4, 0x0, 0x6, 0x8, 0x0, 0x4, 0x10, 0x2,
    0x28,

    /* U+006B "k" */
    0x41, 0x0, 0x11, 0x52, 0x80, 0x24, 0x88,

    /* U+006C "l" */
    0x52, 0x2, 0x20, 0x4, 0xe0,

    /* U+006D "m" */
    0x39, 0x58, 0x0, 0xaa, 0xa0,

    /* U+006E "n" */
    0xb4, 0x60, 0x9, 0x48,

    /* U+006F "o" */
    0x39, 0x18, 0x0, 0x8a, 0xc0,

    /* U+0070 "p" */
    0x34, 0x44, 0x2, 0x4, 0x4e, 0x0, 0x40, 0x80,

    /* U+0071 "q" */
    0x2d, 0x10, 0x20, 0x89, 0xa0, 0x4, 0x10,

    /* U+0072 "r" */
    0xd4, 0x60, 0x8, 0x40,

    /* U+0073 "s" */
    0x78, 0x90, 0x1e,

    /* U+0074 "t" */
    0x28, 0x74, 0x4, 0xa0,

    /* U+0075 "u" */
    0x4a, 0x62, 0x9, 0x54,

    /* U+0076 "v" */
    0x8c, 0x64, 0xa, 0x20,

    /* U+0077 "w" */
    0x45, 0x18, 0x0, 0xaa, 0x40,

    /* U+0078 "x" */
    0x45, 0x20, 0x0, 0x52, 0x20,

    /* U+0079 "y" */
    0x45, 0x10, 0x20, 0x49, 0xa0, 0x4, 0xd0,

    /* U+007A "z" */
    0x6c, 0x42, 0x0, 0x43, 0xa0,

    /* U+007B "{" */
    0x14, 0x2, 0x8, 0x20, 0x8, 0x10, 0x40, 0x8,
    0x18,

    /* U+007C "|" */
    0x10, 0x22, 0x20, 0x4, 0x40, 0x88,

    /* U+007D "}" */
    0x28, 0x0, 0x82, 0x8, 0x0, 0x44, 0x10, 0x2,
    0x28,

    /* U+007E "~" */
    0x26, 0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 106, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 106, .box_w = 3, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 106, .box_w = 4, .box_h = 4, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 7, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 106, .box_w = 2, .box_h = 4, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 35, .adv_w = 106, .box_w = 3, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 106, .box_w = 4, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 48, .adv_w = 106, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 50, .adv_w = 106, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 52, .adv_w = 106, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 53, .adv_w = 106, .box_w = 1, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 106, .box_w = 3, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 106, .box_w = 2, .box_h = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 106, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 135, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 106, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 144, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 106, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 358, .adv_w = 106, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 364, .adv_w = 106, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 372, .adv_w = 106, .box_w = 3, .box_h = 4, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 374, .adv_w = 106, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 375, .adv_w = 106, .box_w = 1, .box_h = 2, .ofs_x = 5, .ofs_y = 8},
    {.bitmap_index = 376, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 106, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 417, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 106, .box_w = 4, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 106, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 438, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 106, .box_w = 4, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 455, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 464, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 472, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 479, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 106, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 106, .box_w = 3, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 106, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 106, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 515, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 106, .box_w = 6, .box_h = 12, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 529, .adv_w = 106, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 535, .adv_w = 106, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 544, .adv_w = 106, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 2}
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
    .kern_dsc = NULL,
    .kern_scale = 0,
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
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONT1*/

