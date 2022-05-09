#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "canvas/color.h"
#include "linal/vec.h"

#include "camera.h"

typedef struct sphere {
    float rad;
    Vec3 pos;
    Color color;
    float specular;
    float reflective;
} Sphere;

typedef struct sphere_array {
    Sphere *values;
    int num;
    int cap;
} SphereArray;

Sphere sphere_new(float rad, Vec3 pos, Color color, float specular, float reflective);
int sphere_intersect_ray(Sphere *s, Vec3 o, Vec3 d, float *r);

#endif
