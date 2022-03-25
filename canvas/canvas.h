#ifndef CANVAS_CANVAS_H
#define CANVAS_CANVAS_H

#include <stdint.h>

#include "bmp.h"
#include "color.h"

typedef struct canvas {
    int hw;
    int hh;
    BMPImage image;
} Canvas;

Canvas canvas_new(uint32_t w, uint32_t h);
void canvas_set_pixel(Canvas *canvas, int x, int y, Color color);
void canvas_clear(Canvas *canvas, Color c);
void canvas_export(Canvas *canvas, const char *path);
void canvas_free(Canvas *canvas);

#endif
