#include <stdlib.h>
#include <stdint.h>

typedef struct bmp {
    uint32_t w;
    uint32_t h;
    uint8_t *pixel_data; /* flat array of size (w * h * 3) */
} BMPImage;

typedef struct canvas {
    uint32_t w;
    uint32_t h;
    BMPImage image;
} Canvas;

BMPImage bmp_new(uint32_t w, uint32_t h);

Canvas canvas_new(uint32_t w, uint32_t h);
