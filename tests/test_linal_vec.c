#include "vec.h"
#include <stdio.h>

/*
 * calling UFMT(vec3_add(v1, v1)) will result in the following code
 * ```c
 * vec3_add(v1, v2).y, vec3_add(v1, v2).y, vec3_add(v1, v2).z
 * ```
 * which does the addition _3_ times and therefore is bad. it should be avoided
 * unless performance is not a concern.
 */
#define UFMT(v) (v).x, (v).y, (v).z
#define VFMT "[%.2f, %.2f, %.2f]"

int main(void) {
    Vec3 v1 = vec3_new(0, 3, 4);
    Vec3 v2 = vec3_new(3, 4, 0);

    /* clang-format off */
    printf(
        "v1: " VFMT "\n"
        "v2: " VFMT "\n"
        "\n"
        "v1_len: %.2f\n"
        "v2_len: %.2f\n"
        "\n"
        "v1 . v2: %.2f\n"
        "v1 x v2: " VFMT "\n"
        "\n"
        "v1 + v2: " VFMT "\n"
        "v1 - v2: " VFMT "\n"
        "v1 * 10: " VFMT "\n",
            UFMT(v1),
            UFMT(v2),
            vec3_len(v1),
            vec3_len(v2),
            vec3_dot(v1, v2),
            UFMT(vec3_cross(v1, v2)),
            UFMT(vec3_add(v1, v2)),
            UFMT(vec3_sub(v1, v2)),
            UFMT(vec3_mul(v1, 10))
    );
    /* clang-format on */

    return 0;
}
