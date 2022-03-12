#include "canvas.h"
#include <stdint.h>

Color color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    Color c = { r, g, b };
    return c;
}

BMPImage bmp_new(uint32_t w, uint32_t h) {
    BMPImage bmp = { w, h };
    bmp.pixel_data = calloc(sizeof(Color), w * h);

    return bmp;
}

void bmp_set_pixel(BMPImage *image, uint32_t x, uint32_t y, Color color) {
    if (x < image->w && y < image->h) {
        image->pixel_data[image->w*y + x] = color;
    }
}

void bmp_free(BMPImage *image) {
    free(image->pixel_data);

    image->w = 0;
    image->h = 0;
    image->pixel_data = NULL;
}

Canvas canvas_new(uint32_t w, uint32_t h) {
    BMPImage bmp = bmp_new(w, h);
    Canvas c = { w, h, bmp };

    return c;
}

void canvas_set_pixel(Canvas *canvas, int x, int y, Color color) {
    uint32_t newx = canvas->w / 2 + x;
    uint32_t newy = canvas->h / 2 - y;

    bmp_set_pixel(&canvas->image, newx, newy, color);
}

void canvas_free(Canvas *canvas) {
    canvas->w = 0;
    canvas->h = 0;
    bmp_free(&canvas->image);
}
