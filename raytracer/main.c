#include "canvas/canvas.h"
#include "linal/vec.h"

#include "array.h"
#include "camera.h"
#include "scene.h"
#include "sphere.h"

int main(void) {
    Canvas canvas = canvas_new(400, 400);
    Scene scene = scene_new(camera_new(0, 0, 0), viewport_new(1, 1, 1),
                            color_rgb(0x000000));

    /* scene_add_light(&scene, light_new_ambient(0.2)); */
    /* scene_add_light(&scene, light_new_point(0.8, vec3_new(1, 1, 1))); */

    /* scene_add_object( */
    /*     &scene, sphere_new(1, vec3_new(-2, 3, 6), color_rgb(0x00ff00), 500)); */
    /* scene_add_object( */
    /*     &scene, sphere_new(1, vec3_new(0, 0, 6), color_rgb(0x58cced), 500)); */
    /* scene_add_object( */
    /*     &scene, sphere_new(1, vec3_new(2, 0, 4), color_rgb(0xff0000), 100)); */

    scene_add_light(&scene, light_new_ambient(0.2));
    scene_add_light(&scene, light_new_point(0.6, vec3_new(2, 1, 0)));
    scene_add_light(&scene, light_new_directional(0.2, vec3_new(1, 4, 4)));

    scene_add_object(
        &scene, sphere_new(1, vec3_new(0x00, -0x1, 3), color_rgb(0xff0000), 500));
    scene_add_object(
        &scene, sphere_new(1, vec3_new(-0x2, 0x00, 4), color_rgb(0x00ff00), 10));
    scene_add_object(
        &scene, sphere_new(1, vec3_new(0x02, 0x00, 4), color_rgb(0x0000ff), 500));

    scene_render(&scene, &canvas);
    canvas_export(&canvas, "raytraced.bmp");

    scene_free(&scene);
    canvas_free(&canvas);

    return 0;
}
