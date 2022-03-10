# Canvas

This document is meant to be interpreted in a programming language agnostic way, that is -- when I talk about `struct`s for example, I don't necessarily mean C structs. We should use some other similar language construct in our choice of programming language.

Ideally, we would want to be able to `export` whatever was rendered onto the `Canvas` to some sort of image file. Since the main goal is learning, we should implement a simple `bmp` encoder that is capable of encoding 24 bit images (RGB without alpha).

# Canvas API

```c
struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
}

struct BMPImage {
    uint32_t w;
    uint32_t h;
    uint8_t *pixel_data; /* flat array of size (w * h * 3) */
}

struct Canvas {
    uint32_t w;
    uint32_t h;
    BMPImage image;
}

Color color_rgb(uint8_t r, uint8_t g, uint8_t b);

BMPImage bmp_new(uint32_t w, uint32_t h);
    void bmp_set_pixel(BMPImage *image, uint32_t x, uint32_t y);
    void bmp_export(BMPImage *image, const char *path);

Canvas canvas_new(uint32_t w, uint32_t h);
  void canvas_set_pixel(Canvas *canvas, int x, int, y, Color color);
  void canvas_line(Canvas *canvas, int x1, int y1, int x2, int y2, Color color);
   int canvas_export(Canvas *canvas, const char *path);
```

# The BMP Format

WIP
