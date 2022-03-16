#include "vec.h"

Vec3 vec3_new(float x, float y, float z) {
    Vec3 v = { x, y, z };
    return v;
}

Vec3 vec3_mul(Vec3 a, float k) {
    Vec3 v = { a.x * k, a.y * k, a.z * k };
    return v;
}

Vec3 vec3_add(Vec3 a, Vec3 b) {
    Vec3 v = { a.x + b.x, a.y + b.y, a.z + b.z };
    return v;
}

Vec3 vec3_sub(Vec3 a, Vec3 b) {
    Vec3 v = { a.x - b.x, a.y - b.y, a.z - b.z };
    return v;
}

Vec3 vec3_cross(Vec3 a, Vec3 b) {
    Vec3 v = { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x };
    return v;
}

float vec3_dot(Vec3 a, Vec3 b) {
    float d = a.x * b.x + a.y * b.y + a.z * b.z;
    return d;
}
