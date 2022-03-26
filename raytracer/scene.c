#include <math.h>

#include "canvas/canvas.h"
#include "linal/vec.h"

#include "array.h"
#include "camera.h"
#include "scene.h"
#include "sphere.h"

ViewPort viewport_new(int w, int h, int d) {
    return (ViewPort){ w, h, d };
}

Vec3 viewport_coords(ViewPort *self, int x, int y, Canvas *canvas) {
    return vec3_new((float)x * (float)self->w / canvas->image.w,
                    (float)y * (float)self->h / canvas->image.h,
                    (float)self->d);
}

Scene scene_new(Camera cam, ViewPort viewport, Color bg) {
    SphereArray objects;
    array_init(Sphere, &objects, 8);

    return (Scene){ bg, cam, viewport, objects };
}

void scene_add_object(Scene *scene, Sphere sphere) {
    array_add(&scene->objects, sphere);
}

static Color trace_ray(Scene *scene, Vec3 d) {
    float closest_t = INFINITY;
    Sphere *closest = NULL;
    float result[2] = { 0 };

    for (int i = 0; i < scene->objects.num; i++) {
        Sphere *object = &scene->objects.values[i];
        if (sphere_intersect_ray(object, &scene->cam, d, result) == 0) {
            for (int n = 0; n < 2; n++) {
                if (result[n] > 1.0 && result[n] < INFINITY &&
                    result[n] < closest_t) {
                    closest_t = result[n];
                    closest = object;
                }
            }
        }
    }

    if (closest != NULL)
        return closest->color;

    return scene->bg;
}

void scene_render(Scene *scene, Canvas *canvas) {
    for (int x = -canvas->hw; x < canvas->hw; x++) {
        for (int y = canvas->hh; y > -canvas->hh; y--)
            canvas_set_pixel(canvas, x, y,
                             trace_ray(scene, viewport_coords(&scene->viewport,
                                                              x, y, canvas)));
    }
}
