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
    printf("  hw: %d\n", c->hw);
    printf("  hh: %d\n", c->hh);
    printf("  BMPImage:\n");
    printf("    w: %d\n", c->image.w);
    printf("    h: %d\n", c->image.h);

    canvas_clear(c, color_rgb(0x64, 0x95, 0xed));

    /* testing color_add */
    canvas_draw_rectangle(
        c, -70, 0, 70, 70,
        color_add(color_rgb(0xff, 0x00, 0xff), color_rgb(0x00, 0x55, 0xff)));

    canvas_draw_rectangle(c, 0, 0, 70, 70, color_rgb(0xff, 0xff, 0xff));

    for (int i = -c->hw; i < c->hw; i++) {
        canvas_set_pixel(c, i, 0, color_rgb(0x00, 0x00, 0x00));
        canvas_set_pixel(c, 0, i, color_rgb(0x00, 0x00, 0x00));
    }

    canvas_export(c, "canvas_test.bmp");
}

int main() {
    Canvas c = canvas_new(400, 400);

    debug_canvas(&c);
    canvas_free(&c);
    return 0;
}
