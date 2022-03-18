#ifndef CANVAS_COLOR_H
#define CANVAS_COLOR_H

#include <stdint.h>

typedef struct color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

Color color_rgb(uint8_t r, uint8_t g, uint8_t b);

Color color_add(Color a, Color b);
Color color_addk(Color a, uint8_t k);

Color color_sub(Color a, Color b);
Color color_subk(Color a, uint8_t k);

#endif
