#include <stdio.h>

#include "canvas.h"

void debug_canvas(struct Canvas c)
{
    printf("Canvas:\n");
    printf(" w: %d\n", c.w);
    printf(" h: %d\n", c.h);
    printf(" BMPImage:\n");
    printf("  w: %d\n", c.image.w);
    printf("  h: %d\n", c.image.h);
    printf("  pixel_data:\n");
    printf("   ");
    for (int i = 0; i < c.w; i++) {
        for (int j = 0; j < c.h; j++)
            printf("%d", c.image.pixel_data[i*c.h+j]);
        printf("\n   ");
    }
    printf("\n");
}


int main()
{
    struct Canvas c = canvas_new(4, 4);
    c.image.pixel_data[c.w*c.h-c.w] = 4;
    debug_canvas(c);
        
    free(c.image.pixel_data);
    return 0;
}
