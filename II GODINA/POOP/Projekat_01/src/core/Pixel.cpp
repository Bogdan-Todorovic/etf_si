#include "../../include/core/Pixel.hpp"
#include <cmath>

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : red(r), blue(b), green(g), alpha(a){}

Pixel Pixel::merge(const Pixel &bottom, const Pixel &top, const double opacity) {
    Pixel mergedPixel;
    // Formula for calculating final color, affected by opacity
    mergedPixel.red = static_cast<uint8_t> (std::round(bottom.red * (1 - opacity) + top.red * opacity));
    mergedPixel.green = static_cast<uint8_t> (std::round(bottom.green * (1 - opacity) + top.green * opacity));
    mergedPixel.blue = static_cast<uint8_t> (std::round(bottom.blue * (1 - opacity) + top.blue * opacity));

    return mergedPixel;
}
