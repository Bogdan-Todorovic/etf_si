#ifndef IMAGEFORGE_PIXEL_HPP
#define IMAGEFORGE_PIXEL_HPP
#include <algorithm>
#include <cstdint>

// Only represents data structure that holds information about one pixel, as simple as possible.
class Pixel {
public:
    explicit Pixel(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255);
    static Pixel merge(const Pixel &bottom, const Pixel &top, double opacity);
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;

    // Template function for transforming pixels
    template <typename F>
    void transform (F f) {
        red = static_cast<uint8_t>(std::clamp(f(red),0 ,255));
        green = static_cast<uint8_t> (std::clamp(f(green),0 ,255));
        blue = static_cast<uint8_t> (std::clamp(f(blue),0 ,255));
    }
};


#endif //IMAGEFORGE_PIXEL_HPP