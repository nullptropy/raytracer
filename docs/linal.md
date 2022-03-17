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

> returns a new instance of `Vec3`

- [x] `Vec3 vec3_mul(Vec3 a, float k)`;

> returns a new `Vec3`, where each element is `a`s elements multiplied by `k`

- [x] `Vec3 vec3_add(Vec3 a, Vec3 b)`;

> returns element wise addition of `a` and `b` in a new `Vec3`

- [x] `Vec3 vec3_sub(Vec3 a, Vec3 b)`;

> returns element wise substraction of `a` and `b` in a new `Vec3`

- [ ] `float vec3_len(Vec3 v)`;

> returns the magnitude of `v`, which is equal to `sqrt(x^2 + y^2 + z^2)`

- [ ] `Vec3 vec3_norm(Vec3 v)`;

> returns `v` in its normalized form, that is each element is divided by `v`s length

- [x] `Vec3 vec3_cross(Vec3 a, Vec3 b)`;

> returns the cross product `a x b`

- [x] `float vec3_dot(Vec3 a, Vec3 b)`;

> returns the dot product `a.b`
