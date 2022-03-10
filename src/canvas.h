#include <stdlib.h>

struct BMPImage {
    uint32_t w;
    uint32_t h;
    uint8_t *pixel_data; /* flat array of size (w * h * 3) */
};

struct Canvas {
    uint32_t w;
    uint32_t h;
    struct BMPImage image;
};


struct BMPImage bmp_new(uint32_t w, uint32_t h);

struct Canvas canvas_new(uint32_t w, uint32_t h);


struct BMPImage bmp_new(uint32_t w, uint32_t h)
{
    struct BMPImage bmp = { w, h };
    bmp.pixel_data = malloc(w * h * 3);
    return bmp;
}

struct Canvas canvas_new(uint32_t w, uint32_t h)
{
    struct BMPImage bmp = bmp_new(w, h);
    struct Canvas c = { w, h, bmp };
    return c;
}
