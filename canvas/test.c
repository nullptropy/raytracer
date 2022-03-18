#include <inttypes.h>
#include <stdio.h>

#include "canvas.h"

static void canvas_draw_rectangle(Canvas *canvas, int x, int y, int w, int h,
                                  Color color) {
    for (int nx = 0; nx < w; nx++) {
        for (int ny = 0; ny < h; ny++) {
            canvas_set_pixel(canvas, x + nx, y + ny, color);
        }
    }
}

static void debug_canvas(Canvas *c) {
    printf("Canvas:\n");
    printf("  w: %d\n", c->w);
    printf("  h: %d\n", c->h);
    printf("  BMPImage:\n");
    printf("    w: %d\n", c->image.w);
    printf("    h: %d\n", c->image.h);

    int hw = c->w / 2;
    int hh = c->w / 2;

    for (int i = -hw; i < hw; i++) {
        canvas_set_pixel(c, i, 0, color_rgb(0x00, 0xff, 0x00));
        canvas_set_pixel(c, 0, i, color_rgb(0xff, 0x00, 0xff));
    }

    /* testing color_add */
    canvas_draw_rectangle(
        c, -100, 0, 100, 100,
        color_add(color_rgb(0xff, 0x00, 0xff), color_rgb(0x00, 0x55, 0xff)));

    canvas_draw_rectangle(c, 0, 0, 100, 100, color_rgb(0xff, 0xff, 0xff));
    canvas_export(c, "canvas_test.bmp");
}

int main() {
    Canvas c = canvas_new(600, 600);

    debug_canvas(&c);
    canvas_free(&c);
    return 0;
}
