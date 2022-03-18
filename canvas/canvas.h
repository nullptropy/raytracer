#include "bmp.h"
#include "color.h"

#include <stdint.h>

typedef struct canvas {
    uint32_t w;
    uint32_t h;
    BMPImage image;
} Canvas;

Canvas canvas_new(uint32_t w, uint32_t h);
void canvas_set_pixel(Canvas *canvas, int x, int y, Color color);
void canvas_export(Canvas *canvas, const char *path);
void canvas_free(Canvas *canvas);
