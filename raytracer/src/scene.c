#include <math.h>
#include <stdio.h>

#include <vec.h>
#include <canvas.h>

#include <array.h>
#include <camera.h>
#include <color.h>
#include <scene.h>
#include <sphere.h>

typedef struct hit_record {
    float t;
    Sphere *sphere;
} HitRecord;

ViewPort viewport_new(float w, float h, float d) {
    return (ViewPort){ w, h, d };
}

Vec3 viewport_coords(ViewPort *self, int x, int y, Canvas *canvas) {
    return vec3_new((float)x * (float)self->w / canvas->image.w,
                    (float)y * (float)self->h / canvas->image.h,
                    (float)self->d);
}

Scene scene_new(Camera cam, ViewPort viewport, Color bg) {
    SphereArray objects;
    LightArray lights;

    array_init(Sphere, &objects, 8);
    array_init(Light, &lights, 8);

    return (Scene){ bg, cam, viewport, objects, lights };
}

void scene_add_object(Scene *scene, Sphere sphere) {
    array_add(&scene->objects, sphere);
}

void scene_add_light(Scene *scene, Light light) {
    array_add(&scene->lights, light);
}

static HitRecord closest_intersection(Scene *scene, Vec3 o, Vec3 d, float t_min, float t_max) {
    float closest_t = INFINITY;
    Sphere *closest = NULL;
    float result[2] = { 0 };

    for (int i = 0; i < scene->objects.num; i++) {
        Sphere *object = &scene->objects.values[i];
        if (sphere_intersect_ray(object, o, d, result) == 0) {
            for (int n = 0; n < 2; n++) {
                if (result[n] > t_min && result[n] < t_max &&
                    result[n] < closest_t) {
                    closest_t = result[n];
                    closest = object;
                }
            }
        }
    }

    return (HitRecord) { closest_t, closest };
}

static float compute_lighting(Scene *scene, Vec3 P, Vec3 N, Vec3 V, float s) {
    float intensity = 0;

    for (int i = 0; i < scene->lights.num; i++) {
        Light *light = &scene->lights.values[i];

        if (light->type == Ambient) {
            intensity += light->intensity;
            continue;
        }

        Vec3 L = (light->type == Point) ? vec3_sub(light->position, P)
                                        : light->direction;
        float t_max = (light->type == Point) ? 1.0 : INFINITY;

        if (closest_intersection(scene, P, L, 0.001, t_max).sphere != NULL)
            continue;

        float NL = vec3_dot(N, L);
        intensity +=
            (NL < 0) ? 0 : light->intensity * NL / (vec3_len(L) * vec3_len(N));

        if (s != -1) {
            Vec3 R = vec3_sub(vec3_mul(N, 2 * NL), L);
            float RV = vec3_dot(R, V);

            if (RV > 0)
                intensity += light->intensity *
                             powf(RV / (vec3_len(R) * vec3_len(V)), s);
        }
    }

    return intensity;
}

static Color trace_ray(Scene *scene, Vec3 o, Vec3 d, float t_min, float t_max, int recursion_depth) {
    HitRecord hit = closest_intersection(scene, o, d, t_min, t_max);

    Sphere *closest = hit.sphere;
    float closest_t = hit.t;

    if (closest == NULL) {
        return scene->bg;
    }

    Vec3 P = vec3_add(o, vec3_mul(d, closest_t));
    Vec3 N = vec3_norm(vec3_sub(P, closest->pos));
    Vec3 R = vec3_mul(d, -1);

    Color local_color = color_mul(
        closest->color,
        compute_lighting(scene, P, N, R, closest->specular));

    float r = closest->reflective;
    if (recursion_depth <= 0 || r <= 0)
        return local_color;

    R = vec3_sub(vec3_mul(N, 2 * vec3_dot(R, N)), R);

    return color_add(
        color_mul(local_color, 1.0 - r),
        color_mul(trace_ray(scene, P, R, 0.1, INFINITY, recursion_depth - 1), r));
}

void scene_render(Scene *scene, Canvas *canvas, int recursion_limit) {
    for (int x = -canvas->hw; x < canvas->hw; x++) {
        for (int y = canvas->hh; y > -canvas->hh; y--) {
            Color color = trace_ray(
                scene, scene->cam.pos,
                viewport_coords(&scene->viewport, x, y, canvas), 1.0, INFINITY, recursion_limit);

            canvas_set_pixel(canvas, x, y, color);
        }
    }
}

void scene_free(Scene *scene) {
    array_free(&scene->lights);
    array_free(&scene->objects);
}
