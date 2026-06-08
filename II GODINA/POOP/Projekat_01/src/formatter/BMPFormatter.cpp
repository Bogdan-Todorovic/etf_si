#include "../../include/formatter/BMPFormatter.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/utils.hpp"
#include "../../include/core/Pixel.hpp"
#include <fstream>
#include <iostream>

Layer BMPFormatter::load(const std::string& path) {
    std::ifstream bmpFile(path, std::ios::binary);
    if (!bmpFile)
        throw std::runtime_error("Unable to open file: " + path);

    // Read signature
    char b = read<char>(bmpFile, Offset::SIGNATURE);
    char m = read<char>(bmpFile);

    if (!bmpFile)
        throw std::runtime_error("Failed to read BMP signature.");

    if (b != 'B' || m != 'M')
        throw std::runtime_error("Invalid BMP file.");

    // Read offset where the pixel array (bitmap data) can be found
    auto offset = read<uint32_t>(bmpFile, Offset::PIXEL_OFFSET);

    if (offset > 54)
        throw std::runtime_error("Invalid offset value.");

    // Read width and height
    auto width = read<uint32_t>(bmpFile, Offset::WIDTH);
    auto height = read<uint32_t>(bmpFile, Offset::HEIGHT);

    if (width <= 0 || height <= 0)
        throw std::runtime_error("Invalid width or height.");

    // Read planes, bits per pixel and compression
    auto planes = read<uint16_t>(bmpFile, Offset::PLANES);
    auto bitPerPixel = read<uint16_t>(bmpFile, Offset::BITS_PER_PIXEL);
    auto compression = read<uint32_t>(bmpFile, Offset::COMPRESSION);

    if (planes != 1 || bitPerPixel != 24 || compression != 0)
        throw std::runtime_error("Invalid BMP format.");

    Layer layer(width, height, 100, path);
    bmpFile.seekg(offset, std::ios::beg);

    // Calculating how many bytes are needed for row to be divisible by 4
    uint8_t padding = (4 - (width*3) % 4) % 4;

    for (int y = static_cast<int>(height) - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            auto blue = read<uint8_t>(bmpFile);
            auto green = read<uint8_t>(bmpFile);
            auto red = read<uint8_t>(bmpFile);
            layer.getPixel(x, y) = Pixel(red, green, blue);
        }
        bmpFile.ignore(padding);
    }

    return layer;
}

void BMPFormatter::save(Layer &layer, const std::string& path) {
    std::ofstream bmpFile(path, std::ios::binary);
    BMPFormatHeader header;
    // Padding is number of bytes that need to be added
    // so that the width is divisible by 4
    uint8_t padding = (4 - (layer.getWidth()*3) % 4) % 4;
    size_t rowWidth = layer.getWidth() * 3 + padding;

    header.width = layer.getWidth();
    header.height = layer.getHeight();
    header.rawBitMapSize = rowWidth * layer.getHeight();
    header.size = 54 + header.rawBitMapSize;
    // Should not happen ever, just in case
    static_assert(sizeof(BMPFormatHeader) == 54);

    write(bmpFile, header);

    uint8_t zero = 0;
    for (int y = static_cast<int>(layer.getHeight()) - 1; y >= 0; y--) {
        for (size_t x = 0; x < layer.getWidth(); x++) {
            write(bmpFile, layer.getPixel(x, y).blue);
            write(bmpFile, layer.getPixel(x, y).green);
            write(bmpFile, layer.getPixel(x, y).red);
        }

        // Adding padding
        for (int i = 0; i < padding; i++) {
            write(bmpFile, zero);
        }
    }
}