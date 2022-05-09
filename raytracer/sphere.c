#include <math.h>

#include "canvas/color.h"
#include "linal/vec.h"

#include "camera.h"
#include "sphere.h"

Sphere sphere_new(float rad, Vec3 pos, Color color, float specular, float reflective) {
    return (Sphere){ rad, pos, color, specular, reflective };
}

int sphere_intersect_ray(Sphere *s, Vec3 o, Vec3 d, float *r) {
    Vec3 co = vec3_sub(o, s->pos);

    float a = vec3_dot(d, d);
    float b = vec3_dot(co, d) * 2.0;
    float c = vec3_dot(co, co) - s->rad * s->rad;

    float delta2 = b * b - 4 * a * c;
    if (delta2 >= 0) {
        float delta = sqrtf(delta2);
        r[0] = (-b + delta) / (2.0 * a);
        r[1] = (-b - delta) / (2.0 * a);

        return 0;
    }

    return 1;
}
