#include "color.h"

Color color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    return (Color){ r, g, b };
}

Color color_add(Color a, Color b) {
    Color tmp = { 0, 0, 0 };

    if (UINT8_MAX - a.r < b.r) {
        tmp.r = 0xff;
    } else {
        tmp.r = a.r + b.r;
    }

    if (UINT8_MAX - a.g < b.g) {
        tmp.g = 0xff;
    } else {
        tmp.g = a.g + b.g;
    }

    if (UINT8_MAX - a.b < b.b) {
        tmp.b = 0xff;
    } else {
        tmp.b = a.b + b.b;
    }

    return tmp;
}

Color color_addk(Color a, uint8_t k) {
    Color tmp = { 0, 0, 0 };

    if (UINT8_MAX - a.r < k) {
        tmp.r = 0xff;
    } else {
        tmp.r = a.r + k;
    }

    if (UINT8_MAX - a.g < k) {
        tmp.g = 0xff;
    } else {
        tmp.g = a.g + k;
    }

    if (UINT8_MAX - a.b < k) {
        tmp.b = 0xff;
    } else {
        tmp.b = a.b + k;
    }

    return tmp;
}

Color color_sub(Color a, Color b) {
    Color tmp = { 0, 0, 0 };
    if (a.r < b.r) {
        tmp.r = 0x00;
    } else {
        tmp.r = a.r - b.r;
    }

    if (a.g < b.b) {
        tmp.g = 0x00;
    } else {
        tmp.g = a.g - b.g;
    }

    if (a.b < b.b) {
        tmp.b = 0x00;
    } else {
        tmp.b = a.b - b.b;
    }

    return tmp;
}

Color color_subk(Color a, uint8_t k) {
    Color tmp = { 0, 0, 0 };

    if (a.r < k) {
        tmp.r = 0x00;
    } else {
        tmp.r = a.r - k;
    }

    if (a.g < k) {
        tmp.g = 0x00;
    } else {
        tmp.g = a.g - k;
    }

    if (a.b < k) {
        tmp.b = 0x00;
    } else {
        tmp.b = a.b - k;
    }

    return tmp;
}
