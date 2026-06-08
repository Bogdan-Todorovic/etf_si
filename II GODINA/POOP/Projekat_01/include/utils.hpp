#ifndef IMAGEFORGE_UTILS_HPP
#define IMAGEFORGE_UTILS_HPP
#include "formatter/BMPFormatter.hpp"
#include <fstream>
#include <memory>


// Some helper functions/structs
// mainly used by formatters but can be used by others if needed

// Template function for reading from file
template<typename T>
T read(std::ifstream &file, BMPFormatter::Offset offset = BMPFormatter::Offset::CURRENT_POSITION) {
    T t;
    if (offset != BMPFormatter::Offset::CURRENT_POSITION)
        file.seekg(static_cast<std::streamoff>(offset), std::ios::beg);

    if (!file.read(reinterpret_cast<char*>(&t), sizeof(T)))
        throw std::runtime_error("Unexpected end of file.");
    return t;
}

// Template function for writing to file
template<typename T>
void write(std::ostream &file, T& value) {
    if (!file.write(reinterpret_cast<char*>(&value), sizeof(T)))
        throw std::runtime_error("Failed to write to file.");
}

#pragma pack(push, 1) // Telling compiler not to use alignment

struct BMPFormatHeader {
    uint16_t signature = 0x4D42; // "BM"
    uint32_t size{};
    uint32_t unused = 0;
    uint32_t pixelOffset = 54;
    uint32_t dibHeaderSize = 40;
    uint32_t width{};
    uint32_t height{};
    uint16_t planes = 1;
    uint16_t bitsPerPixel = 24;
    uint32_t compression = 0;
    uint32_t rawBitMapSize{};
    uint32_t resolutionH = 2835;
    uint32_t resolutionV = 2835;
    uint32_t numOfColors = 0;
    uint32_t importantColors = 0;
};

#pragma pack(pop)

static_assert(sizeof(BMPFormatHeader) == 54);

#endif //IMAGEFORGE_UTILS_HPP