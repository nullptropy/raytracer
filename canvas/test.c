#include <stdio.h>
#include <inttypes.h>

#include "canvas.h"

void debug_canvas(Canvas c) {
    printf("Canvas:\n");
    printf("  w: %d\n", c.w);
    printf("  h: %d\n", c.h);
    printf("  BMPImage:\n");
    printf("    w: %d\n", c.image.w);
    printf("    h: %d\n", c.image.h);
    printf("    pixel_data:");

    for (int y = 0; y < c.h; y++) {
        printf("\n     ");
        for (int x = 0; x < c.w; x++) {
            Color color = c.image.pixel_data[c.w * y + x];
            printf(" #%06" PRIx32,
                   (uint32_t)(color.r << 16 | color.g << 8 | color.b));
        }
    }
    printf("\n");
}

int main() {
    Canvas c = canvas_new(10, 10);
    canvas_set_pixel(&c, 0, 5, color_rgb(0xff, 0xff, 0xff));
    debug_canvas(c);

    canvas_free(&c);
    return 0;
}
