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

**The BITMAPFILEHEADER**:

| size | name     | default | description                                                             |
|------|----------|---------|-------------------------------------------------------------------------|
| 2    | type     | 'BM'    | must always be set to 'BM' to declare that this is a bmp file           |
| 4    | size     | ?       | specifies the size of the file in bytes.                                |
| 2    | reserved | 0       | must always be set to zero.                                             |
| 2    | reserved | 0       | must always be set to zero.                                             |
| 4    | offset   | 0x28    | specifies the offset from the beginning of the file to the bitmap data. |


**The BITMAPINFOHEADER**:

| size | name            | default | description                                                                                                                       |
|------|-----------------|---------|-----------------------------------------------------------------------------------------------------------------------------------|
| 4    | size            | 40      | specifies the size of the BITMAPINFOHEADER structure, in bytes.                                                                   |
| 4    | width           | 100     | specifies the width of the image, in pixels.                                                                                      |
| 4    | height          | 100     | specifies the height of the image, in pixels.                                                                                     |
| 2    | planes          | 1       | specifies the number of planes of the target device                                                                               |
| 2    | bit_count       | 24      | specifies the number of bits per pixel.                                                                                           |
| 4    | compression     | 0       | Specifies the type of compression, usually set to zero (no compression).                                                          |
| 4    | size_image      | 0       | specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.               |
| 4    | dumb            | 0       | specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.                               |
| 4    | dumb            | 0       | specifies the the vertical pixels per meter on the designated targer device, usually set to zero.                                 |
| 4    | color_used      | 0       | specifies the number of colors used in the bitmap, if set to zero the number of colors is calculated using the biBitCount member. |
| 4    | color_important | 0       | specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.                      |
