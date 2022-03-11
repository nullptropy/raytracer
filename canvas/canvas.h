#include <stdlib.h>
#include <stdint.h>

typedef struct color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

typedef struct bmp {
    uint32_t w;
    uint32_t h;
    Color *pixel_data; /* flat array of size (w * h) */
} BMPImage;

typedef struct canvas {
    uint32_t w;
    uint32_t h;
    BMPImage image;
} Canvas;

Color color_rgb(uint8_t r, uint8_t g, uint8_t b);

BMPImage bmp_new(uint32_t w, uint32_t h);
void bmp_set_pixel(BMPImage *image, uint32_t x, uint32_t y, Color color);
void bmp_export(BMPImage *image, const char *path);
void bmp_free(BMPImage *image);

Canvas canvas_new(uint32_t w, uint32_t h);
void canvas_set_pixel(Canvas *canvas, int x, int y, Color color);
void canvas_export(Canvas *canvas, const char *path);
void canvas_free(Canvas *canvas);
