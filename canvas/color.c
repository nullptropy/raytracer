#include "color.h"

#define safe_add(a, b) UINT8_MAX - (a) < (b) ? 0xff : (a) + (b)
#define safe_sub(a, b) (a) < (b) ? 0 : (a) - (b)
#define safe_mul(a, b) (b)<0 ? 0x0 : (b)> 1 ? 0xff : (a) * (b)

Color color_rgb(uint32_t rgb) {
    return (Color){ rgb >> 16, rgb >> 8, rgb };
}

Color color_add(Color a, Color b) {
    return (Color){ safe_add(a.r, b.r), safe_add(a.g, b.g),
                    safe_add(a.b, b.b) };
}

Color color_addk(Color a, uint8_t k) {
    return (Color){ safe_add(a.r, k), safe_add(a.g, k), safe_add(a.b, k) };
}

Color color_sub(Color a, Color b) {
    return (Color){ safe_sub(a.r, b.r), safe_sub(a.g, b.g),
                    safe_sub(a.b, b.b) };
}

Color color_subk(Color a, uint8_t k) {
    return (Color){ safe_sub(a.r, k), safe_sub(a.g, k), safe_sub(a.b, k) };
}

Color color_mul(Color a, float k) {
    return (Color){ safe_mul(a.r, k), safe_mul(a.g, k), safe_mul(a.b, k) };
}
