# Linear Algebra Library

This document should be considered WIP until we finish the book. More features will be added as we need them.

```c
// linal/vec.h

struct Vec3 {
    float x;
    float y;
    float z;
};

Vec3 vec3d_new(float x, float y, float z);

Vec3 vec3d_mul(Vec3 a, float k);
Vec3 vec3d_add(Vec3 a, Vec3 b);
Vec3 vec3d_sub(Vec3 a, Vec3 b);

Vec3 vec3d_norm(Vec3 vec);
float vec3d_len(Vec3 vec);

Vec3 vec3d_cross(Vec3 a, Vec3 b);
float vec3d_dot(Vec3 a, Vec3 b);
```
