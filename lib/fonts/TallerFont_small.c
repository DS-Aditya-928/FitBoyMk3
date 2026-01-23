/*******************************************************************************
 * Size: 40 px
 * Bpp: 1
 * Opts: --bpp 1 --size 40 --no-compress --stride 1 --align 1 --font taller_evolution_rev.ttf --symbols MTWFSONUEDHRIATUNY   --range 48-57 --format lvgl -o TallerFont_small.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef TALLERFONT_SMALL
#define TALLERFONT_SMALL 1
#endif

#if TALLERFONT_SMALL

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0030 "0" */
    0x69, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x96,

    /* U+0031 "1" */
    0x6c, 0x92, 0x49, 0x24, 0x92, 0x49, 0x24, 0x92,
    0x49, 0x24, 0x92, 0x49, 0x24,

    /* U+0032 "2" */
    0x69, 0x11, 0x11, 0x11, 0x32, 0x22, 0x22, 0x22,
    0x26, 0x44, 0x44, 0x44, 0x44, 0xc8, 0x88, 0x88,
    0x8f,

    /* U+0033 "3" */
    0x69, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x96,

    /* U+0034 "4" */
    0x10, 0x84, 0x23, 0x18, 0xc6, 0x31, 0x8c, 0x67,
    0x39, 0xca, 0x52, 0x94, 0xad, 0x6b, 0x5a, 0xf8,
    0x84, 0x21, 0x8, 0x42, 0x10, 0x80,

    /* U+0035 "5" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8e,
    0xd1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x96,

    /* U+0036 "6" */
    0x69, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8e,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x96,

    /* U+0037 "7" */
    0xf1, 0x13, 0x33, 0x32, 0x22, 0x22, 0x22, 0x26,
    0x66, 0x64, 0x44, 0x44, 0x44, 0x4c, 0xcc, 0x88,
    0x88,

    /* U+0038 "8" */
    0x69, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0xf9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x96,

    /* U+0039 "9" */
    0x69, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x71, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x96,

    /* U+0041 "A" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xee, 0xee,
    0xee, 0xee, 0xaa, 0xab, 0xbb, 0xbb, 0xbb, 0xfb,
    0xbb,

    /* U+0044 "D" */
    0xe9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x9e,

    /* U+0045 "E" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0x24, 0x9a, 0x49,
    0x24, 0x92, 0x49, 0x24, 0x9c,

    /* U+0046 "F" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0x24, 0x9a, 0x49,
    0x24, 0x92, 0x49, 0x24, 0x90,

    /* U+0048 "H" */
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x9f, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004D "M" */
    0x86, 0x18, 0x61, 0x87, 0x1c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xfb, 0xfe,
    0xdb, 0x6d, 0xb6, 0xdb, 0x6d, 0xb6, 0xdb, 0x6d,
    0xb6, 0x90,

    /* U+004E "N" */
    0x99, 0x99, 0x9d, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd,
    0xdb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0x99, 0x99,
    0x99,

    /* U+004F "O" */
    0x69, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x96,

    /* U+0052 "R" */
    0xe9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x9e, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99,

    /* U+0053 "S" */
    0x69, 0x88, 0x88, 0x88, 0xc4, 0x44, 0x44, 0x44,
    0x46, 0x22, 0x22, 0x22, 0x21, 0x11, 0x11, 0x19,
    0x96,

    /* U+0054 "T" */
    0xf2, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22,

    /* U+0055 "U" */
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x96,

    /* U+0057 "W" */
    0x93, 0x26, 0x4c, 0x99, 0x32, 0x74, 0xed, 0xdb,
    0xbf, 0xff, 0xff, 0xff, 0xdb, 0xb7, 0x6e, 0xdd,
    0xb3, 0x66, 0xcd, 0x9b, 0x36, 0x6c, 0xd9, 0xb3,
    0x66, 0xcd, 0x9b, 0x36, 0x6c, 0xd8,

    /* U+0059 "Y" */
    0xb6, 0xdb, 0x6d, 0xbb, 0x6d, 0x92, 0x49, 0x24,
    0x92, 0x49, 0x24, 0x92, 0x48
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 43, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 108, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 72, .box_w = 3, .box_h = 34, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 84, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 90, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 90, .box_w = 5, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 89, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 99, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 78, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 107, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 100, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 92, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 108, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 76, .box_w = 3, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 75, .box_w = 3, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 108, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 68, .box_w = 1, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 146, .box_w = 6, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 113, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 108, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 108, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 85, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 75, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 108, .box_w = 4, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 146, .box_w = 7, .box_h = 34, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 86, .box_w = 3, .box_h = 34, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x19, 0x21, 0x24, 0x25, 0x26, 0x28,
    0x29, 0x2d, 0x2e, 0x2f, 0x32, 0x33, 0x34, 0x35,
    0x37, 0x39
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 58, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 26, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    6, 6,
    6, 11,
    9, 6,
    9, 7,
    12, 20,
    12, 23,
    12, 24,
    12, 25,
    12, 26,
    13, 12,
    13, 25,
    13, 26,
    15, 12,
    19, 12,
    20, 12,
    20, 23,
    20, 25,
    20, 26,
    21, 20,
    21, 23,
    21, 24,
    21, 25,
    23, 12,
    23, 20,
    24, 12,
    25, 12,
    25, 20,
    26, 12,
    26, 20
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    6, -6, -21, 7, -12, -10, -12, -19,
    -14, -14, -17, -12, -5, -13, -14, -9,
    -17, -12, -23, -9, -23, -17, -11, -7,
    -14, -20, -16, -15, -11
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 29,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
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
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t TallerFont_small = {
#else
lv_font_t TallerFont_small = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 34,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 2,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if TALLERFONT_SMALL*/
