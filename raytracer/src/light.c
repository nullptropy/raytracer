#include <light.h>
#include <vec.h>

Light light_new_point(float intensity, Vec3 position) {
    return (Light){ Point, intensity, position, vec3_new(0, 0, 0) };
}

Light light_new_ambient(float intensity) {
    return (Light){ Ambient, intensity, vec3_new(0, 0, 0), vec3_new(0, 0, 0) };
}

Light light_new_directional(float intensity, Vec3 direction) {
    return (Light){ Directional, intensity, vec3_new(0, 0, 0), direction };
}
