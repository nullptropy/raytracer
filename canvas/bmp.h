#include <stdint.h>

#include "color.h"

typedef struct bmp {
    uint32_t w;
    uint32_t h;
    Color *pixel_data; /* flat array of size (w * h) */
} BMPImage;

BMPImage bmp_new(uint32_t w, uint32_t h);
void bmp_set_pixel(BMPImage *image, uint32_t x, uint32_t y, Color color);
void bmp_export(BMPImage *image, const char *path);
void bmp_free(BMPImage *image);
