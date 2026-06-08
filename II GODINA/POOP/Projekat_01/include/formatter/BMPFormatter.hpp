#ifndef IMAGEFORGE_BMPFORMATTER_HPP
#define IMAGEFORGE_BMPFORMATTER_HPP
#include <string>

// Used for transforming .bmp files to layers ---> pixels

class Layer;

class BMPFormatter {
public:
    static Layer load(const std::string& path);
    static void save(Layer &layer, const std::string& path);

    // Documentation defined offsets inside .bmp file
    enum class Offset : std::streamoff {
        CURRENT_POSITION = -1,
        SIGNATURE = 0x00,
        PIXEL_OFFSET = 0x0A,
        WIDTH = 0x12,
        HEIGHT = 0x16,
        PLANES = 0x1A,
        BITS_PER_PIXEL = 0x1C,
        COMPRESSION = 0x1E
    };
};


#endif //IMAGEFORGE_BMPFORMATTER_HPP
