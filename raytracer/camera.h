#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "linal/vec.h"

typedef struct camera {
    Vec3 pos;
} Camera;

Camera camera_new(float x, float y, float z);

#endif
