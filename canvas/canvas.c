#include "canvas.h"

Canvas canvas_new(uint32_t w, uint32_t h) {
    return (Canvas){ w, h, bmp_new(w, h) };
}

void canvas_set_pixel(Canvas *canvas, int x, int y, Color color) {
    uint32_t newx = canvas->w / 2 + x;
    uint32_t newy = canvas->h / 2 - y;

    bmp_set_pixel(&canvas->image, newx, newy, color);
}

void canvas_export(Canvas *canvas, const char *path) {
    bmp_export(&canvas->image, path);
}

void canvas_free(Canvas *canvas) {
    canvas->w = 0;
    canvas->h = 0;
    bmp_free(&canvas->image);
}
