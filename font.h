#ifndef __BASE_FONT_H__
#define __BASE_FONT_H__

#include<stdint.h>
#define FONT_WIDTH  6
#define FONT_HEIGHT 10

/* Font information:
 name: 6x10
 facename: -Misc-Fixed-Medium-R-Normal--10-100-75-75-C-60-ISO8859-1
 w x h: 6x10
 size: 256
 ascent: 8
 descent: 2
 first char: 0 (0x00)
 last char: 255 (0xff)
 default char: 0 (0x00)
 proportional: no
 Public domain terminal emulator font.  Share and enjoy.
 */

/* Font character bitmap data. */
//static uint16_t font_bits[2230] =
extern uint8_t font_bits[2230];


#endif

