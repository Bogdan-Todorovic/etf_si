#ifndef IMAGEFORGE_LAYER_HPP
#define IMAGEFORGE_LAYER_HPP
#include <cstdint>
#include <string>
#include <vector>

// One layer is represented by vector of Pixels.
// Layers are used for modification of BMP images.

class Pixel;

class Layer {
public:
    Layer(size_t width, size_t height, uint8_t opacity = 100, std::string path = "");

    [[nodiscard]] size_t getWidth() const;
    [[nodiscard]] size_t getHeight() const;

    [[nodiscard]] uint8_t getOpacity() const;
    void setOpacity(uint8_t op);

    Pixel& getPixel(size_t x, size_t y);
    [[nodiscard]] const Pixel& getPixel(size_t x, size_t y) const;

    [[nodiscard]] bool getActive() const;
    [[nodiscard]] bool getVisible() const;

    void setActive(bool active);
    void setVisible(bool visible);

    // If image is smaller or bigger than layer
    void resize(size_t newWidth, size_t newHeight);
    static Layer merge(const Layer &bottom, const Layer &top);

    std::vector<Pixel> pixels;
    // Layer can be loaded from .bmp image, need to save for exporting project
    std::string path;
private:
    size_t width, height;
    uint8_t opacity;

    bool isActive, isVisible;
};


#endif //IMAGEFORGE_LAYER_HPP