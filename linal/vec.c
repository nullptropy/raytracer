#include "vec.h"

#include <math.h>

Vec3 vec3_new(float x, float y, float z) {
    return (Vec3){ x, y, z };
}

Vec3 vec3_mul(Vec3 a, float k) {
    return (Vec3){ a.x * k, a.y * k, a.z * k };
}

Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){ a.x + b.x, a.y + b.y, a.z + b.z };
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){ a.x - b.x, a.y - b.y, a.z - b.z };
}

float vec3_len(Vec3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 vec3_norm(Vec3 v) {
    float l = vec3_len(v);
    return (Vec3){ v.x / l, v.y / l, v.z / l };
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    return (Vec3){ a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x };
}

float vec3_dot(Vec3 a, Vec3 b) {
    return (float)(a.x * b.x + a.y * b.y + a.z * b.z);
}
