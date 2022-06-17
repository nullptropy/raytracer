#include <vec.h>
#include <camera.h>

Camera camera_new(float x, float y, float z) {
    return (Camera){ vec3_new(x, y, z) };
}
