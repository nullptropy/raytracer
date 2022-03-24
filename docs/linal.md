# Linear Algebra Library

This document should be considered WIP until we finish the book. More features will be added as we need them.

```c
typedef struct vec3 {
    float x;
    float y;
    float z;
} Vec3;

Vec3 vec3_new(float x, float y, float z);

Vec3 vec3_mul(Vec3 a, float k);
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);

float vec3_len(Vec3 v);
Vec3 vec3_norm(Vec3 v);

Vec3 vec3_cross(Vec3 a, Vec3 b);
float vec3_dot(Vec3 a, Vec3 b);
```

### Vector API Implementation Status:
- [x] `Vec3 vec3_new(float x, float y, float z);`

> Returns a new instance of `Vec3`.

- [x] `Vec3 vec3_mul(Vec3 a, float k);`

> Returns a new `Vec3`, where each element of `a` is multiplied by `k`.

- [x] `Vec3 vec3_add(Vec3 a, Vec3 b);`

> Returns a new `Vec3`, where each element of `a` is added with the corresponding element of `b`.

- [x] `Vec3 vec3_sub(Vec3 a, Vec3 b);`

> Returns a new `Vec3`, where each element of `a` is subtracted by the corresponding element of `b`.

- [x] `float vec3_len(Vec3 v);`

> Returns a `float`, of the magnitude of `v` (which is equal to `sqrt(x^2 + y^2 + z^2)`).

- [x] `Vec3 vec3_norm(Vec3 v);`

> Returns a new `Vec3`, where `v` in its normalized form, that is each element of `v` is divided by `v`'s length (`vec3_len()` of `v`).

- [x] `Vec3 vec3_cross(Vec3 a, Vec3 b);`

> Returns a new `Vec3`, with the the cross product of `a` and `b` (`a * b`).

- [x] `float vec3_dot(Vec3 a, Vec3 b);`

> Returns a new `Vec3`, with the the dot product of `a` and `b` (`a.b`).
