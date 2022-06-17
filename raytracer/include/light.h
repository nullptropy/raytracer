#include <vec.h>

typedef enum light_type {
    Point,
    Ambient,
    Directional,
} LightType;

typedef struct light {
    LightType type;
    float intensity;

    Vec3 position;  // this field is only valid for point lights
    Vec3 direction; // this field is only valid for directional lights
} Light;

typedef struct light_array {
    Light *values;
    int num;
    int cap;
} LightArray;

Light light_new_point(float intensity, Vec3 position);
Light light_new_ambient(float intensity);
Light light_new_directional(float intensity, Vec3 direction);
