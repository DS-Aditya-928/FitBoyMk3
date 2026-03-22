/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --no-compress --stride 1 --align 1 --font Oswald-VariableFont_wght.ttf --range 0-256 --font FontAwesome5-Solid+Brands+Regular.woff --range 61512-61521 --format lvgl -o Oswald_12.c
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



#ifndef OSWALD_12
#define OSWALD_12 1
#endif

#if OSWALD_12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+000D "\r" */
    0x0,

    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfe, 0x40,

    /* U+0022 "\"" */
    0xfb, 0x0,

    /* U+0023 "#" */
    0x29, 0x5b, 0xf4, 0xaf, 0xea, 0x56, 0x80,

    /* U+0024 "$" */
    0x23, 0xa7, 0x1c, 0x30, 0xc3, 0x8e, 0x5c, 0x0,

    /* U+0025 "%" */
    0x62, 0x25, 0x9, 0x42, 0x50, 0x64, 0x2, 0x70,
    0xa4, 0x29, 0xa, 0x44, 0x60,

    /* U+0026 "&" */
    0x71, 0x45, 0x14, 0x61, 0x8e, 0xe6, 0x99, 0xb0,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x6a, 0xaa, 0xa9,

    /* U+0029 ")" */
    0x95, 0x55, 0x56,

    /* U+002A "*" */
    0x4e, 0x4a,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0xc0,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x11, 0x22, 0x22, 0x44, 0x4c,

    /* U+0030 "0" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x8b, 0x80,

    /* U+0031 "1" */
    0x3c, 0x92, 0x49, 0x24,

    /* U+0032 "2" */
    0x74, 0x62, 0x11, 0x8, 0x88, 0xc7, 0xc0,

    /* U+0033 "3" */
    0x74, 0x62, 0x13, 0x4, 0x31, 0x8b, 0x80,

    /* U+0034 "4" */
    0x30, 0xc3, 0x14, 0x53, 0x4f, 0xc4, 0x10, 0x40,

    /* U+0035 "5" */
    0xfc, 0x21, 0xf, 0x44, 0x31, 0x8b, 0x80,

    /* U+0036 "6" */
    0x74, 0x61, 0xf, 0x46, 0x31, 0x8b, 0x80,

    /* U+0037 "7" */
    0xf1, 0x32, 0x22, 0x26, 0x44,

    /* U+0038 "8" */
    0x74, 0x63, 0x17, 0x46, 0x31, 0x8b, 0x80,

    /* U+0039 "9" */
    0x74, 0x63, 0x18, 0xbc, 0x31, 0x8b, 0x80,

    /* U+003A ":" */
    0x88,

    /* U+003B ";" */
    0x8e,

    /* U+003C "<" */
    0x3c, 0xc3,

    /* U+003D "=" */
    0xe3, 0x80,

    /* U+003E ">" */
    0xc7, 0x7c,

    /* U+003F "?" */
    0x72, 0x52, 0x11, 0x88, 0x84, 0x1, 0x0,

    /* U+0040 "@" */
    0x1f, 0x8, 0x64, 0xf, 0x3d, 0x8a, 0x64, 0x99,
    0x26, 0x4a, 0x9f, 0x10, 0x6, 0x0, 0x7c,

    /* U+0041 "A" */
    0x30, 0xc3, 0xc, 0x79, 0x24, 0x9e, 0x4b, 0x30,

    /* U+0042 "B" */
    0xf4, 0x63, 0x1f, 0x4e, 0x31, 0x8f, 0x80,

    /* U+0043 "C" */
    0x74, 0x63, 0x18, 0x42, 0x31, 0x8b, 0x80,

    /* U+0044 "D" */
    0xf4, 0x63, 0x18, 0xc6, 0x31, 0x8f, 0x80,

    /* U+0045 "E" */
    0xf2, 0x49, 0xe4, 0x9c,

    /* U+0046 "F" */
    0xf2, 0x4f, 0x24, 0x90,

    /* U+0047 "G" */
    0x74, 0x63, 0x8, 0x4e, 0x31, 0x8b, 0xc0,

    /* U+0048 "H" */
    0x8c, 0x63, 0x1f, 0xc6, 0x31, 0x8c, 0x40,

    /* U+0049 "I" */
    0xff, 0xc0,

    /* U+004A "J" */
    0x55, 0x55, 0x70,

    /* U+004B "K" */
    0x94, 0xa9, 0x4e, 0x72, 0x96, 0x94, 0xc0,

    /* U+004C "L" */
    0x92, 0x49, 0x24, 0x9c,

    /* U+004D "M" */
    0x87, 0x3c, 0xf3, 0xcf, 0x5b, 0x6d, 0xb6, 0x50,

    /* U+004E "N" */
    0x8e, 0x73, 0x9a, 0xd6, 0x73, 0x8c, 0x40,

    /* U+004F "O" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x8b, 0x80,

    /* U+0050 "P" */
    0xf4, 0x63, 0x18, 0xfa, 0x10, 0x84, 0x0,

    /* U+0051 "Q" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x8b, 0x84, 0x10,

    /* U+0052 "R" */
    0xf4, 0x63, 0x1f, 0x4a, 0x53, 0x8c, 0x40,

    /* U+0053 "S" */
    0x74, 0x63, 0x86, 0x18, 0x71, 0xcb, 0x80,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x21, 0x0,

    /* U+0055 "U" */
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8b, 0x80,

    /* U+0056 "V" */
    0xcd, 0x24, 0x92, 0x49, 0xe3, 0xc, 0x30, 0xc0,

    /* U+0057 "W" */
    0x49, 0x49, 0x59, 0x55, 0x55, 0x56, 0x76, 0x36,
    0x26, 0x22,

    /* U+0058 "X" */
    0xc9, 0x27, 0x8c, 0x30, 0xc7, 0x16, 0x4b, 0x20,

    /* U+0059 "Y" */
    0x8e, 0xd4, 0xa5, 0x10, 0x84, 0x21, 0x0,

    /* U+005A "Z" */
    0xf8, 0x8c, 0x42, 0x31, 0x8, 0xc7, 0xc0,

    /* U+005B "[" */
    0xea, 0xaa, 0xab,

    /* U+005C "\\" */
    0xc4, 0x44, 0x22, 0x22, 0x11,

    /* U+005D "]" */
    0xd5, 0x55, 0x57,

    /* U+005E "^" */
    0x32, 0x94, 0x90,

    /* U+005F "_" */
    0xf0,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0x79, 0x17, 0x99, 0xf0,

    /* U+0062 "b" */
    0x88, 0x8e, 0x99, 0x99, 0x9e,

    /* U+0063 "c" */
    0x79, 0x98, 0x99, 0x70,

    /* U+0064 "d" */
    0x11, 0x17, 0x99, 0x99, 0x97,

    /* U+0065 "e" */
    0x69, 0x9f, 0x89, 0x70,

    /* U+0066 "f" */
    0x69, 0x74, 0x92, 0x48,

    /* U+0067 "g" */
    0x35, 0x24, 0x92, 0x31, 0x3, 0x92, 0x78,

    /* U+0068 "h" */
    0x88, 0x8f, 0x99, 0x99, 0x99,

    /* U+0069 "i" */
    0x9f, 0xc0,

    /* U+006A "j" */
    0x41, 0x55, 0x57,

    /* U+006B "k" */
    0x88, 0x89, 0xae, 0xea, 0xb9,

    /* U+006C "l" */
    0xff, 0xc0,

    /* U+006D "m" */
    0xff, 0x26, 0x4c, 0x99, 0x32, 0x64, 0x80,

    /* U+006E "n" */
    0xf9, 0x99, 0x99, 0x90,

    /* U+006F "o" */
    0x69, 0x99, 0x99, 0x60,

    /* U+0070 "p" */
    0xe9, 0x99, 0x99, 0xe8, 0x80,

    /* U+0071 "q" */
    0x79, 0x99, 0x99, 0x71, 0x10,

    /* U+0072 "r" */
    0xf2, 0x49, 0x20,

    /* U+0073 "s" */
    0x6d, 0x42, 0x1d, 0x70,

    /* U+0074 "t" */
    0x4b, 0xa4, 0x92, 0x60,

    /* U+0075 "u" */
    0x99, 0x99, 0x99, 0xf0,

    /* U+0076 "v" */
    0xdd, 0x55, 0x76, 0x60,

    /* U+0077 "w" */
    0x92, 0xa9, 0xd3, 0x66, 0xcd, 0x9b, 0x0,

    /* U+0078 "x" */
    0xd2, 0x98, 0x46, 0x2b, 0x40,

    /* U+0079 "y" */
    0xd6, 0x94, 0xa5, 0x30, 0x84, 0x40,

    /* U+007A "z" */
    0xf2, 0x64, 0x4c, 0xe0,

    /* U+007B "{" */
    0x69, 0x25, 0x12, 0x49, 0x30,

    /* U+007C "|" */
    0xff, 0xf0,

    /* U+007D "}" */
    0xc9, 0x24, 0x52, 0x49, 0x60,

    /* U+007E "~" */
    0x68, 0x80,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0x9f, 0xc0,

    /* U+00A2 "¢" */
    0x4f, 0x99, 0x89, 0x97, 0x40,

    /* U+00A3 "£" */
    0x32, 0x92, 0x84, 0x71, 0x8, 0x47, 0x80,

    /* U+00A4 "¤" */
    0xae, 0xa3, 0x2e, 0x80,

    /* U+00A5 "¥" */
    0x8e, 0xd4, 0xa5, 0x11, 0xc4, 0x71, 0x0,

    /* U+00A6 "¦" */
    0xf9, 0xf0,

    /* U+00A7 "§" */
    0xe9, 0xce, 0x9d, 0x63, 0x96,

    /* U+00A8 "¨" */
    0xa0,

    /* U+00A9 "©" */
    0x1e, 0x1b, 0xe5, 0x2a, 0x49, 0x90, 0x64, 0x99,
    0x25, 0x3a, 0x61, 0x87, 0x80,

    /* U+00AA "ª" */
    0x74, 0xfb, 0xc0,

    /* U+00AB "«" */
    0xa, 0x75, 0x65, 0x24, 0x20,

    /* U+00AC "¬" */
    0xf1, 0x10,

    /* U+00AE "®" */
    0x1e, 0x18, 0x65, 0xea, 0x49, 0x92, 0x67, 0x19,
    0x45, 0x4a, 0x61, 0x87, 0x80,

    /* U+00AF "¯" */
    0xc0,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B1 "±" */
    0x21, 0x9, 0xf2, 0x7c,

    /* U+00B2 "²" */
    0xea, 0x26, 0x4f,

    /* U+00B3 "³" */
    0xf4, 0xab, 0xc0,

    /* U+00B4 "´" */
    0xe8,

    /* U+00B5 "µ" */
    0x99, 0x99, 0x99, 0xf8, 0x80,

    /* U+00B6 "¶" */
    0x7f, 0x7a, 0xd2, 0x94, 0xa5, 0x29, 0x4a,

    /* U+00B7 "·" */
    0x80,

    /* U+00B8 "¸" */
    0x9c,

    /* U+00B9 "¹" */
    0x75, 0x50,

    /* U+00BA "º" */
    0xe9, 0x99, 0x9e,

    /* U+00BB "»" */
    0x25, 0x34, 0x99, 0x50, 0x80,

    /* U+00BC "¼" */
    0xc2, 0x22, 0x11, 0x9, 0x4, 0x90, 0x98, 0x54,
    0x4f, 0x21, 0x0,

    /* U+00BD "½" */
    0xc2, 0x11, 0x4, 0x41, 0x20, 0x4b, 0x86, 0xa1,
    0x8, 0x46, 0x21, 0x8, 0xf0,

    /* U+00BE "¾" */
    0x71, 0x34, 0x81, 0x20, 0x88, 0x14, 0x1d, 0x20,
    0xd8, 0x2a, 0xb, 0xc4, 0x20,

    /* U+00BF "¿" */
    0x20, 0x8, 0x44, 0x62, 0x13, 0x8b, 0x80,

    /* U+00C0 "À" */
    0x60, 0x80, 0xc, 0x30, 0xc3, 0x1e, 0x49, 0x27,
    0x92, 0xcc,

    /* U+00C1 "Á" */
    0x18, 0x40, 0xc, 0x30, 0xc3, 0x1e, 0x49, 0x27,
    0x92, 0xcc,

    /* U+00C2 "Â" */
    0x30, 0xc4, 0x8c, 0x30, 0xc3, 0x1e, 0x49, 0x27,
    0x92, 0xcc,

    /* U+00C3 "Ã" */
    0x69, 0x60, 0xc, 0x30, 0xc3, 0x1e, 0x49, 0x27,
    0x92, 0xcc,

    /* U+00C4 "Ä" */
    0x50, 0x8, 0xc5, 0x29, 0x4a, 0x57, 0xe3, 0x10,

    /* U+00C5 "Å" */
    0x72, 0x9c, 0x42, 0x29, 0x4a, 0x56, 0xff, 0x18,
    0x80,

    /* U+00C6 "Æ" */
    0xe, 0x30, 0x60, 0xc2, 0xe5, 0x1a, 0x3c, 0xc9,
    0x1c,

    /* U+00C7 "Ç" */
    0x74, 0x63, 0x18, 0x42, 0x31, 0x8b, 0x88, 0x23,
    0x0,

    /* U+00C8 "È" */
    0x89, 0x79, 0x24, 0xf2, 0x4e,

    /* U+00C9 "É" */
    0x25, 0x79, 0x24, 0xf2, 0x4e,

    /* U+00CA "Ê" */
    0x56, 0xf9, 0x24, 0xf2, 0x4e,

    /* U+00CB "Ë" */
    0xa3, 0xc9, 0x27, 0x92, 0x70,

    /* U+00CC "Ì" */
    0xa5, 0x55, 0x55, 0x40,

    /* U+00CD "Í" */
    0x6a, 0xaa, 0xaa, 0x80,

    /* U+00CE "Î" */
    0x56, 0xa4, 0x92, 0x49, 0x24,

    /* U+00CF "Ï" */
    0xa1, 0x24, 0x92, 0x49, 0x20,

    /* U+00D0 "Ð" */
    0x79, 0x14, 0x51, 0xe5, 0x14, 0x51, 0x45, 0xe0,

    /* U+00D1 "Ñ" */
    0x74, 0x81, 0x1c, 0xe7, 0x35, 0xac, 0xe7, 0x18,
    0x80,

    /* U+00D2 "Ò" */
    0x43, 0x8, 0xe8, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00D3 "Ó" */
    0x10, 0x88, 0xe8, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00D4 "Ô" */
    0x22, 0x94, 0xe8, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00D5 "Õ" */
    0x75, 0x80, 0xe8, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00D6 "Ö" */
    0x50, 0x1d, 0x18, 0xc6, 0x31, 0x8c, 0x62, 0xe0,

    /* U+00D7 "×" */
    0x1f, 0x50,

    /* U+00D8 "Ø" */
    0x3, 0xa7, 0x5a, 0xd6, 0xb9, 0xce, 0x5c, 0x0,

    /* U+00D9 "Ù" */
    0x42, 0x9, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00DA "Ú" */
    0x10, 0x89, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00DB "Û" */
    0x22, 0x95, 0x18, 0xc6, 0x31, 0x8c, 0x63, 0x17,
    0x0,

    /* U+00DC "Ü" */
    0x50, 0x23, 0x18, 0xc6, 0x31, 0x8c, 0x62, 0xe0,

    /* U+00DD "Ý" */
    0x11, 0x9, 0x1d, 0xa9, 0x4a, 0x21, 0x8, 0x42,
    0x0,

    /* U+00DE "Þ" */
    0x84, 0x3d, 0x18, 0xc7, 0xd0, 0x84, 0x0,

    /* U+00DF "ß" */
    0x64, 0xa5, 0x2b, 0x4e, 0x31, 0x8d, 0x80,

    /* U+00E0 "à" */
    0x44, 0x7, 0x91, 0x79, 0x9f,

    /* U+00E1 "á" */
    0x32, 0x7, 0x91, 0x79, 0x9f,

    /* U+00E2 "â" */
    0x65, 0x7, 0x91, 0x79, 0x9f,

    /* U+00E3 "ã" */
    0x5b, 0x7, 0x91, 0x79, 0x9f,

    /* U+00E4 "ä" */
    0x50, 0x7, 0x91, 0x79, 0x9f,

    /* U+00E5 "å" */
    0x75, 0x77, 0xd1, 0x7d, 0xdf,

    /* U+00E6 "æ" */
    0x6f, 0xa4, 0x49, 0xed, 0x3a, 0x7b, 0x0,

    /* U+00E7 "ç" */
    0x79, 0x98, 0x99, 0x74, 0x36,

    /* U+00E8 "è" */
    0x44, 0x6, 0x99, 0xf8, 0x97,

    /* U+00E9 "é" */
    0x22, 0x6, 0x99, 0xf8, 0x97,

    /* U+00EA "ê" */
    0x66, 0x6, 0x99, 0xf8, 0x97,

    /* U+00EB "ë" */
    0x90, 0x6, 0x99, 0xf8, 0x97,

    /* U+00EC "ì" */
    0x91, 0x55, 0x50,

    /* U+00ED "í" */
    0x62, 0xaa, 0xa0,

    /* U+00EE "î" */
    0x54, 0x24, 0x92, 0x48,

    /* U+00EF "ï" */
    0xa0, 0x24, 0x92, 0x48,

    /* U+00F0 "ð" */
    0xc3, 0x57, 0x99, 0x99, 0x96,

    /* U+00F1 "ñ" */
    0xdb, 0xf, 0x99, 0x99, 0x99,

    /* U+00F2 "ò" */
    0x44, 0x6, 0x99, 0x99, 0x96,

    /* U+00F3 "ó" */
    0x22, 0x6, 0x99, 0x99, 0x96,

    /* U+00F4 "ô" */
    0x66, 0x6, 0x99, 0x99, 0x96,

    /* U+00F5 "õ" */
    0xdb, 0x6, 0x99, 0x99, 0x96,

    /* U+00F6 "ö" */
    0x90, 0x6, 0x99, 0x99, 0x96,

    /* U+00F7 "÷" */
    0x43, 0x84,

    /* U+00F8 "ø" */
    0x16, 0x9b, 0xdd, 0xd6, 0x80,

    /* U+00F9 "ù" */
    0x44, 0x9, 0x99, 0x99, 0x9f,

    /* U+00FA "ú" */
    0x22, 0x9, 0x99, 0x99, 0x9f,

    /* U+00FB "û" */
    0x65, 0x9, 0x99, 0x99, 0x9f,

    /* U+00FC "ü" */
    0x50, 0x9, 0x99, 0x99, 0x9f,

    /* U+00FD "ý" */
    0x11, 0x1, 0xad, 0x29, 0x4a, 0x61, 0x8, 0x80,

    /* U+00FE "þ" */
    0x88, 0x8e, 0x99, 0x99, 0x9e, 0x88,

    /* U+00FF "ÿ" */
    0x50, 0x0, 0xa5, 0x29, 0x4a, 0x21, 0x8, 0xc0,

    /* U+0100 "Ā" */
    0x30, 0x3, 0xc, 0x30, 0xc7, 0x92, 0x49, 0xe4,
    0xb3,

    /* U+F048 "" */
    0xc3, 0xc7, 0xcf, 0xdf, 0xff, 0xff, 0xdf, 0xcf,
    0xc7, 0xc3,

    /* U+F049 "" */
    0xc2, 0x16, 0x31, 0xf7, 0x9f, 0xfd, 0xff, 0xff,
    0xff, 0x7f, 0x79, 0xf8, 0xc7, 0xc2, 0x10,

    /* U+F04A "" */
    0x6, 0x18, 0x71, 0xcf, 0xbe, 0xff, 0xff, 0xff,
    0xbf, 0xfc, 0xfb, 0xe1, 0xc7, 0x6, 0x18,

    /* U+F04B "" */
    0x0, 0x1c, 0x3, 0xe0, 0x7f, 0xf, 0xf9, 0xff,
    0xbf, 0xff, 0xfe, 0xff, 0x9f, 0xc3, 0xe0, 0x70,
    0x0, 0x0,

    /* U+F04C "" */
    0xfb, 0xff, 0x7f, 0xef, 0xfd, 0xff, 0xbf, 0xf7,
    0xfe, 0xff, 0xdf, 0xfb, 0xff, 0x7c,

    /* U+F04D "" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+F04E "" */
    0xc3, 0x7, 0x1c, 0x3e, 0xf9, 0xff, 0xef, 0xff,
    0xff, 0xfb, 0xef, 0x9c, 0x70, 0xc3, 0x0,

    /* U+F050 "" */
    0x42, 0x1f, 0x18, 0xfc, 0xf7, 0xf7, 0xff, 0xff,
    0xfd, 0xff, 0xcf, 0x7c, 0x63, 0x42, 0x18,

    /* U+F051 "" */
    0xc3, 0xe3, 0xf3, 0xfb, 0xff, 0xff, 0xfb, 0xf3,
    0xe3, 0xc3
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 44, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 44, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 40, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 51, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 93, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 94, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 21, .adv_w = 171, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 116, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 24, .box_w = 1, .box_h = 3, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 43, .adv_w = 57, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 46, .adv_w = 50, .box_w = 2, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 49, .adv_w = 76, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 51, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 55, .adv_w = 36, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 56, .adv_w = 58, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 57, .adv_w = 36, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 99, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 73, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 92, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 92, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 93, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 91, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 97, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 74, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 38, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 130, .adv_w = 41, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 72, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 133, .adv_w = 80, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 135, .adv_w = 72, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 137, .adv_w = 93, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 174, .box_w = 10, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 159, .adv_w = 94, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 101, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 99, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 101, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 78, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 75, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 103, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 108, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 48, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 58, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 95, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 76, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 127, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 101, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 103, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 92, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 104, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 263, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 91, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 79, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 104, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 97, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 140, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 93, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 92, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 80, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 65, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 334, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 60, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 342, .adv_w = 85, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 345, .adv_w = 66, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 346, .adv_w = 53, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 347, .adv_w = 79, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 86, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 79, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 85, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 81, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 55, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 85, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 380, .adv_w = 85, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 44, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 44, .box_w = 2, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 390, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 44, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 131, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 84, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 82, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 86, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 417, .adv_w = 85, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 422, .adv_w = 62, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 72, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 59, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 84, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 74, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 113, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 448, .adv_w = 75, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 75, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 459, .adv_w = 67, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 58, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 468, .adv_w = 46, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 470, .adv_w = 62, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 475, .adv_w = 86, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 477, .adv_w = 44, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 40, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 480, .adv_w = 74, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 485, .adv_w = 76, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 106, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 496, .adv_w = 88, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 41, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 505, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 77, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 511, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 72, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 527, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 74, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 534, .adv_w = 170, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 55, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 548, .adv_w = 87, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 550, .adv_w = 80, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 554, .adv_w = 81, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 557, .adv_w = 82, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 560, .adv_w = 53, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 561, .adv_w = 85, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 566, .adv_w = 94, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 573, .adv_w = 34, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 574, .adv_w = 68, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 575, .adv_w = 65, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 577, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 580, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 585, .adv_w = 181, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 181, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 168, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 92, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 629, .adv_w = 94, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 94, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 649, .adv_w = 94, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 94, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 94, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 94, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 122, .box_w = 7, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 99, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 704, .adv_w = 78, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 78, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 78, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 78, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 724, .adv_w = 48, .box_w = 2, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 728, .adv_w = 48, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 48, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 737, .adv_w = 48, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 742, .adv_w = 99, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 101, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 759, .adv_w = 103, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 768, .adv_w = 103, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 103, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 103, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 795, .adv_w = 103, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 74, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 805, .adv_w = 104, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 813, .adv_w = 104, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 104, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 104, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 104, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 92, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 97, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 99, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 876, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 886, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 891, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 896, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 901, .adv_w = 125, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 913, .adv_w = 81, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 918, .adv_w = 81, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 923, .adv_w = 81, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 928, .adv_w = 81, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 933, .adv_w = 43, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 936, .adv_w = 43, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 939, .adv_w = 43, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 943, .adv_w = 43, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 90, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 952, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 962, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 967, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 972, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 82, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 982, .adv_w = 66, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 984, .adv_w = 81, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 989, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 994, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 999, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1004, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 75, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1017, .adv_w = 86, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1023, .adv_w = 75, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1031, .adv_w = 94, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1040, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1050, .adv_w = 192, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1065, .adv_w = 192, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1080, .adv_w = 168, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1098, .adv_w = 168, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1112, .adv_w = 168, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1126, .adv_w = 192, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1141, .adv_w = 192, .box_w = 13, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1156, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_4[] = {
    0, 1, 2, 3, 4, 5, 6, 0,
    7, 8
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 13, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 13, .glyph_id_start = 97,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 174, .range_length = 83, .glyph_id_start = 110,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 61512, .range_length = 10, .glyph_id_start = 193,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_4, .list_length = 10, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 1, 0, 0, 0,
    2, 1, 0, 0, 3, 0, 4, 5,
    4, 6, 7, 8, 9, 0, 10, 11,
    12, 13, 14, 8, 15, 15, 0, 0,
    0, 0, 0, 16, 17, 18, 19, 20,
    21, 22, 0, 0, 23, 24, 25, 26,
    0, 19, 27, 19, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 0, 37, 0,
    0, 0, 0, 38, 39, 40, 41, 42,
    43, 44, 45, 0, 0, 46, 0, 45,
    45, 47, 39, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 58, 59, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 60, 0, 0, 0, 61,
    16, 16, 16, 16, 16, 62, 0, 18,
    20, 20, 20, 20, 0, 0, 0, 0,
    19, 0, 19, 19, 19, 19, 19, 0,
    19, 31, 31, 31, 31, 35, 0, 63,
    38, 38, 38, 38, 38, 38, 42, 40,
    64, 42, 42, 42, 0, 0, 0, 0,
    0, 45, 47, 47, 47, 47, 47, 0,
    47, 52, 52, 52, 52, 56, 47, 56,
    62, 0, 0, 0, 0, 0, 0, 0,
    0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 0, 1, 0, 0, 0,
    2, 1, 0, 0, 3, 0, 4, 5,
    6, 7, 8, 9, 10, 0, 11, 0,
    12, 13, 12, 14, 15, 15, 0, 0,
    0, 0, 0, 16, 17, 18, 17, 17,
    17, 18, 17, 17, 19, 17, 17, 20,
    17, 18, 17, 21, 17, 22, 23, 24,
    25, 26, 27, 28, 29, 0, 30, 0,
    0, 0, 0, 31, 0, 32, 32, 32,
    33, 34, 0, 35, 36, 0, 0, 37,
    37, 32, 38, 39, 37, 40, 41, 42,
    43, 44, 45, 46, 47, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 48, 49, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 50,
    0, 0, 48, 51, 0, 0, 0, 52,
    16, 16, 16, 16, 16, 16, 53, 54,
    17, 17, 17, 17, 17, 17, 17, 17,
    0, 17, 18, 18, 18, 18, 18, 0,
    18, 24, 24, 24, 24, 28, 17, 55,
    56, 31, 31, 31, 31, 31, 31, 57,
    32, 32, 32, 32, 0, 35, 35, 35,
    32, 37, 58, 32, 32, 32, 32, 0,
    32, 42, 42, 42, 42, 46, 0, 46,
    16, 0, 0, 0, 0, 0, 0, 0,
    0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -12,
    0, -1, -6, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -4,
    0, -6, 0, 0, 0, 0, -4, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -15, -1, 0, -2,
    -4, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, 0, -1, 0, -10, -1, -8, -7,
    0, -13, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, -1, 0, -2, 0,
    -3, -1, 0, -2, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    -5, -1, -1, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, -1, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, -4, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, 0, -2, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, -1, -2, 0, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, -1, -8, -1, -7, -5,
    0, -8, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    -1, -3, 0, -3, 0, -12, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, -1, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, 0,
    -5, 0, -4, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, -1, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, -1,
    0, -1, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, -1, 0, 0, -1, 0,
    0, 0, -1, 0, -1, 0, -1, -1,
    -1, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, -1,
    0, 0, 0, 0, -1, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    -1, 0, 0, -12, 0, -12, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -7,
    0, 0, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -4, -3,
    0, -2, 0, 0, 0, 0, -3, -3,
    0, 0, 0, 0, -2, -2, -2, 0,
    0, 0, 0, 0, -8, 0, 0, -1,
    -1, -3, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, -1, 0, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, -2, -1, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -2, 0, -1,
    0, 0, 0, 0, -2, -1, -1, 0,
    -1, -2, 0, -5, 0, -6, 0, 0,
    0, 0, 0, -3, 0, -1, -2, -2,
    -6, 0, -8, 0, -3, 0, 0, 0,
    -2, 0, 0, 0, -1, 0, 0, 0,
    0, -1, 0, 0, -2, -1, -15, -2,
    -14, -9, 0, -17, 0, -6, 0, -1,
    -2, -1, 0, 0, 0, 0, -1, -1,
    -2, 0, 0, -6, 0, -9, 0, -17,
    0, -6, 0, 0, 0, -1, 0, 0,
    -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    -2, 0, -1, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -20,
    -17, -21, -10, 0, 0, 0, -5, 0,
    -1, 0, 0, -9, 0, 0, -4, 0,
    0, -1, 0, 0, 0, 0, -2, 0,
    -5, -2, -5, -4, 0, -3, 0, 0,
    -1, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, -17,
    -17, 0, 0, -5, -4, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, -1, 0, -3, 0, -1, -1,
    0, -3, 0, -2, -2, -2, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, -1, 0, -1, -1, 0, 0, 0,
    0, 0, 0, -1, 0, -2, -2, -2,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, -1, 0, -1, 0, 0,
    -1, 0, -1, -1, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, -10, -3, -10,
    -4, 0, 0, 0, 0, 0, 0, 0,
    -12, -8, 0, -1, -4, -2, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -12, -12, -6, -12, 0, -2, -11, -11,
    0, -12, -3, -9, 0, -12, -10, -12,
    -10, -6, -3, 0, 0, -2, -13, -1,
    -2, -5, -12, -12, 0, 0, 0, -1,
    0, -1, -2, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, -9, -5, -9, -1, 0, 0, 0,
    0, 0, 0, 0, -2, -7, 0, -1,
    -4, -1, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -12, -8, 0, -9,
    0, 0, -4, -6, -6, -8, -2, -5,
    -4, -4, -4, -6, -8, -4, 0, 0,
    0, 0, 0, -1, 0, -12, -8, -8,
    0, 0, 0, -7, -1, -7, -2, 0,
    0, 0, 0, 0, 0, 0, -2, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -7, -5,
    -1, -4, 0, 0, -2, -2, 0, -3,
    0, 0, -2, -2, -2, 0, -2, -3,
    0, 0, 0, 0, -8, 0, 0, -7,
    -5, -5, 0, 0, -2, 0, -1, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, -1, -1,
    0, 0, 0, 0, 0, 0, 0, -1,
    -2, -2, -4, -2, 0, 0, 0, 0,
    -2, -4, -4, 0, -4, -6, 0, -6,
    0, -8, 0, 0, 0, 0, 0, -1,
    0, -2, -2, -2, 0, 0, 0, -13,
    -3, -13, -3, -1, 0, 0, -2, -1,
    0, 0, -9, -8, 0, -1, -4, -1,
    -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, -13, -12, -5, -11, 0, 0,
    -9, -8, -3, -9, 0, -8, 0, -7,
    -8, -6, -5, -3, 0, 0, -1, 0,
    -12, -1, -4, -13, -12, -12, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -1, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, 0, 0, -1, 0, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, -1, -2, -4, -2,
    -4, -3, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, 0, -9, -6, 0, -13, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -1, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, -1,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, -8, -5, 0, -12,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, 0, 0, 0,
    0, -8, 0, 0, 0, -1, 0, 0,
    0, -1, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 6, 0,
    2, 2, 0, 4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -12, 0, -6, -2, 0, -10, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, -1, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, -4, -6, 0, -2, -2,
    0, 0, -4, 0, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -7, 0, -2, 0,
    -4, -2, -1, 0, 0, -1, 0, -2,
    0, 2, 0, 0, -1, 0, 1, 0,
    0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, -1, -2,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -11, 0,
    -6, -2, 0, -9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, -1, 0, -5, 0, 0,
    0, -1, 0, -1, 0, 0, 0, 0,
    -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, -1, -4, 0, 0, -1,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, -8, -5, 0, -12,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -10, 0, -4, 0,
    0, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -14, 0, -14, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, -2, 0, 0, 0, -10, 0,
    0, 0, -4, -3, -4, 0, -2, -1,
    0, -1, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -1, -1, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -12, 0, -8, -1, -2, -11, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, -2, 0, 0, -2,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, 0, -4, -1,
    0, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, -2, 0, 0, 0, -13, 0,
    -4, -2, -4, -6, -4, 0, -1, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, -3, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -6, 0, 0, 0,
    -12, 0, -4, -2, -6, -6, -1, 0,
    -1, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -10, 0, -4, -2, 0, -8,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, -1, 0, 0,
    0, -6, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    -2, 0, 0, 0, -13, 0, -4, -2,
    -4, -6, -4, 0, -1, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -10, 0,
    -3, -1, 0, -5, 0, 0, 0, -2,
    0, -1, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, -1,
    -8, -1, -7, -5, 0, -8, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -1, -3, 0, -3,
    0, -12, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, -7, -5, -4, -8,
    -4, 0, 0, -2, 0, 0, 0, 0,
    0, 0, -2, -3, -5, -2, -5, -6,
    -4, -5, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -2, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -12, 0, -6, -2,
    0, -10, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 64,
    .right_class_cnt     = 58,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 5,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t Oswald_12 = {
#else
lv_font_t Oswald_12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if OSWALD_12*/
