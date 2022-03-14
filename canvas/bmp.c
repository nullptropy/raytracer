#include "canvas.h"
#include <stdio.h>

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

static void write_file_header(FILE *file, size_t head_size, size_t data_size) {
    size_t h = head_size;
    size_t f = head_size + data_size; // file size

    uint8_t file_header[14] = {
        0x42, 0x4d,
        f, f >> 8, f >> 16, f >> 24,
        0x00, 0x00, 0x00, 0x00,
        h, h >> 8, h >> 16, h >> 24,
    };

    // TODO: error handling
    fwrite(&file_header, sizeof(uint8_t), 14, file);
}

static void write_info_header(FILE *file, size_t data_size, BMPImage *image) {
    size_t d = data_size;
    uint32_t w = image->w;
    uint32_t h = image->h;

    uint8_t info_header[40] = {
        0x28, 0x00, 0x00, 0x00,
        w, w >> 8, w >> 16, w >> 24,
        h, h >> 8, h >> 16, h >> 24,
        0x01, 0x00,
        0x18, 0x00,
        0x00, 0x00, 0x00, 0x00,
        d, d >> 8, d >> 16, d >> 24,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
    };

    // TODO: error handling
    fwrite(&info_header, sizeof(uint8_t), 40, file);
}

static void write_pixel_data(FILE *file, uint32_t padding, BMPImage *image) {
    // TODO: frequent calls to fwrite with small data is not very efficient
    // instead build the output in memory and then pass that data to fwrite

    uint8_t pad[3] = { 0 };
    uint8_t bgr[3] = { 0 };

    for (int y = image->h - 1; y > -1; y--) {
        for (int x = 0; x < image->w; x++) {
            Color color = image->pixel_data[y * image->w + x];

            bgr[0] = color.b;
            bgr[1] = color.g;
            bgr[2] = color.r;

            fwrite(&bgr, sizeof(uint8_t), 3, file);
        }

        for (int i = 0; i < padding; i++)
            fwrite(&pad, sizeof(uint8_t), padding, file);
    }
}

void bmp_export(BMPImage *image, const char *path) {
    uint32_t padding = (4 - (image->w * 3) % 4) % 4;
    size_t head_size = 54;
    size_t data_size = image->w * image->h * 3 + image->h * padding;

    // TODO: error handling
    FILE *output = fopen(path, "wb");

    write_file_header(output, head_size, data_size);
    write_info_header(output, data_size, image);
    write_pixel_data(output, padding, image);

    fclose(output);
}

void bmp_free(BMPImage *image) {
    free(image->pixel_data);

    image->w = 0;
    image->h = 0;
    image->pixel_data = NULL;
}

