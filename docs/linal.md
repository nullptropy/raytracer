# Linear Algebra Library

This document should be considered WIP until we finish the book. More features will be added as we need them.

```c
// linal/vec.h

typedef struct vec3 {
    float x;
    float y;
    float z;
} Vec3;

Vec3 vec3_new(float x, float y, float z);

Vec3 vec3_mul(Vec3 a, float k);
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);

Vec3 vec3_norm(Vec3 vec);
float vec3_len(Vec3 vec);

Vec3 vec3_cross(Vec3 a, Vec3 b);
float vec3_dot(Vec3 a, Vec3 b);
```
