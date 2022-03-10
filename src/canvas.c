#include "canvas.h"

BMPImage bmp_new(uint32_t w, uint32_t h) {
    BMPImage bmp = { w, h };
    bmp.pixel_data = malloc(w * h * 3);

    return bmp;
}

Canvas canvas_new(uint32_t w, uint32_t h) {
    BMPImage bmp = bmp_new(w, h);
    Canvas c = { w, h, bmp };

    return c;
}
