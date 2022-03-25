#include "canvas.h"

Canvas canvas_new(uint32_t w, uint32_t h) {
    return (Canvas){ (int)(w / 2), (int)(h / 2), bmp_new(w, h) };
}

void canvas_set_pixel(Canvas *canvas, int x, int y, Color color) {
    uint32_t nx = canvas->hw + x;
    uint32_t ny = canvas->hh - y;

    bmp_set_pixel(&canvas->image, nx, ny, color);
}

void canvas_clear(Canvas *canvas, Color c) {
    for (uint32_t i = 0; i < canvas->image.w * canvas->image.h; i++) {
        canvas->image.pixel_data[i] = c;
    }
}

void canvas_export(Canvas *canvas, const char *path) {
    bmp_export(&canvas->image, path);
}

void canvas_free(Canvas *canvas) {
    canvas->hw = 0;
    canvas->hh = 0;
    bmp_free(&canvas->image);
}
