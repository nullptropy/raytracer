#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "canvas/canvas.h"
#include "linal/vec.h"

#include "camera.h"
#include "light.h"
#include "sphere.h"

typedef struct viewport {
    float w;
    float h;
    float d;
} ViewPort;

typedef struct scene {
    Color bg;
    Camera cam;
    ViewPort viewport;
    SphereArray objects;
    LightArray lights;
} Scene;

ViewPort viewport_new(float w, float h, float d);
Vec3 viewport_coords(ViewPort *self, int x, int y, Canvas *canvas);

Scene scene_new(Camera cam, ViewPort viewport, Color bg);
void scene_render(Scene *scene, Canvas *canvas, int recursion_limit);
void scene_add_object(Scene *scene, Sphere sphere);
void scene_add_light(Scene *scene, Light light);
void scene_free(Scene *scene);

#endif
