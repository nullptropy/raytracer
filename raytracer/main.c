#include "canvas/canvas.h"
#include "linal/vec.h"

#include "array.h"
#include "camera.h"
#include "scene.h"
#include "sphere.h"

int main(void) {
    Canvas canvas = canvas_new(400, 400);
    Scene scene = scene_new(camera_new(0, 0, 0), viewport_new(1, 1, 1),
                            color_rgb(0x6495ed));

    scene_add_object(
        &scene, sphere_new(1, vec3_new(0x00, -0x1, 3), color_rgb(0xff0000)));
    scene_add_object(
        &scene, sphere_new(1, vec3_new(-0x2, 0x00, 4), color_rgb(0x00ff00)));
    scene_add_object(
        &scene, sphere_new(1, vec3_new(0x02, 0x00, 4), color_rgb(0x0000ff)));

    scene_render(&scene, &canvas);

    for (int i = -canvas.hw; i <= canvas.hw; i++) {
        canvas_set_pixel(&canvas, i, 0, color_rgb(0x000000));
        canvas_set_pixel(&canvas, 0, i, color_rgb(0x000000));
    }

    canvas_export(&canvas, "raytraced.bmp");

    array_free(&scene.objects);
    canvas_free(&canvas);
    return 0;
}
