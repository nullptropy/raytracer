#include <stdio.h>

#include "canvas/canvas.h"
#include "linal/vec.h"

#include "array.h"
#include "camera.h"
#include "scene.h"
#include "sphere.h"

int main(void) {
    float camera_hview = 1.0;
    float aspect_ratio = 4.0 / 3.0;
    float canvas_width = 1024;

    Canvas canvas = canvas_new(canvas_width, canvas_width / aspect_ratio);
    Scene scene =
        scene_new(camera_new(0, 0, 0),
                  viewport_new(camera_hview * aspect_ratio, camera_hview, 1),
                  color_rgb(0x000000));

    scene_add_light(&scene, light_new_ambient(0.2));
    scene_add_light(&scene, light_new_directional(0.4, vec3_new(1, 4, 4)));
    scene_add_light(&scene, light_new_point(0.8, vec3_new(2, 1, 0)));

    scene_add_object(
        &scene, sphere_new(1, vec3_new(0, -1, 3), color_rgb(0xff0000), 500));
    scene_add_object(
        &scene, sphere_new(1, vec3_new(-2, 0, 4), color_rgb(0x00ff00), 10));
    scene_add_object(
        &scene, sphere_new(1, vec3_new(2, 0, 4), color_rgb(0x0000ff), 500));
    scene_add_object(
        &scene, sphere_new(5000, vec3_new(0, -5001, 0), color_rgb(0x6495ed), 500));

    scene_render(&scene, &canvas);
    canvas_export(&canvas, "raytraced.bmp");

    scene_free(&scene);
    canvas_free(&canvas);

    return 0;
}
