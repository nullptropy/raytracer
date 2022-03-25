#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "canvas/color.h"
#include "linal/vec.h"

#include "camera.h"

typedef struct sphere {
    float rad;
    Vec3 pos;
    Color color;
} Sphere;

typedef struct sphere_array {
    Sphere *values;
    int num;
    int cap;
} SphereArray;

Sphere sphere_new(float rad, Vec3 pos, Color color);
int sphere_intersect_ray(Sphere *s, Camera *cam, Vec3 d, float *r);

#endif
