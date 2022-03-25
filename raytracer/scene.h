#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "canvas/canvas.h"
#include "linal/vec.h"

#include "camera.h"
#include "sphere.h"

typedef struct viewport {
    int w;
    int h;
    int d;
} ViewPort;

typedef struct scene {
    Camera cam;
    ViewPort viewport;
    SphereArray objects;
} Scene;

ViewPort viewport_new(int w, int h, int d);
Vec3 viewport_coords(ViewPort *self, int x, int y, Canvas *canvas);

Scene scene_new(Camera cam, ViewPort viewport);
void scene_render(Scene *scene, Canvas *canvas);
void scene_add_object(Scene *scene, Sphere sphere);

#endif
