#include "color.h"

static inline uint8_t safe_add(uint8_t a, uint8_t b) {
    if (UINT8_MAX - a < b)
        return 0xff;

    return a + b;
}

static inline uint8_t safe_sub(uint8_t a, uint8_t b) {
    if (a < b)
        return 0;

    return a - b;
}

Color color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    return (Color){ r, g, b };
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
