#include "vec.h"
#include <stdio.h>

int main(void) {
    Vec3 v1 = vec3_new(0, 3, 4);
    Vec3 v2 = vec3_new(3, 4, 0);

    float dot = vec3_dot(v1, v2);
    Vec3 cross = vec3_cross(v1, v2);

    printf(
        "v1: [%.2f, %.2f, %.2f]\n"
        "v2: [%.2f, %.2f, %.2f]\n"
        "\n"
        /* "v1_len: %.2f\n" */
        /* "v2_len: %.2f\n", */
        /* "\n", */
        "v1 . v2: %.2f\n"
        "v1 x v2: [%.2f, %.2f, %.2f]\n",
            v1.x, v1.y, v1.z,
            v2.x, v2.y, v2.z,
            /* vec3_len(v1), */
            /* vec3_len(v1), */
            dot,
            cross.x, cross.y, cross.z
    );

    return 0;
}
