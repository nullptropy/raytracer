#include <stdio.h>

#include "canvas.h"

void debug_canvas(Canvas c) {
    printf("Canvas:\n");
    printf(" w: %d\n", c.w);
    printf(" h: %d\n", c.h);
    printf(" BMPImage:\n");
    printf("  w: %d\n", c.image.w);
    printf("  h: %d\n", c.image.h);
    printf("  pixel_data:\n");

    // TODO: broken rn since we're using an array of `Colors`
    printf("   ");
    for (int y = 0; y < c.h; y++) {
        for (int x = 0; x < c.w; x++) {
            printf("(%d,", c.image.pixel_data[c.w*y+x].r);
            printf("%d,", c.image.pixel_data[c.w*y+x].g);
            printf("%d) ", c.image.pixel_data[c.w*y+x].b);
        }
        printf("\n   ");
    }
    printf("\b\b\b");
}


int main() {
    Canvas c = canvas_new(10, 10);
    Color color = { 0, 255, 0 };
    canvas_set_pixel(&c, 0, 5, color);
    debug_canvas(c);
        
    canvas_free(&c);
    return 0;
}
