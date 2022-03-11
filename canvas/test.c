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
    /* printf("   "); */
    /* for (int x = 0; x < c.w; x++) { */
    /*     for (int y = 0; y < c.h; y++) */
    /*         printf("%d", c.image.pixel_data[y*c.w+x].b); */
    /*     printf("\n   "); */
    /* } */
    /* printf("\b\b\b"); */
}


int main() {
    Canvas c = canvas_new(4, 4);
    debug_canvas(c);
        
    canvas_free(&c);
    return 0;
}