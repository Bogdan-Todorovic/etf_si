#include "../../include/core/Layer.hpp"
#include "../../include/core/Pixel.hpp"
#include <algorithm>
#include <cassert>
#include <stdexcept>

Layer::Layer(size_t width, size_t height, uint8_t opacity, std::string path) :
pixels(width*height, Pixel()),
path(std::move(path)),
width(width),
height(height),
opacity(opacity){
    isActive = false;
    isVisible = true;
}

size_t Layer::getWidth() const {
    return width;
}

size_t Layer::getHeight() const {
    return height;
}

uint8_t Layer::getOpacity() const {
    return opacity;
}

void Layer::setOpacity(uint8_t op) {
    if (op < 0 || op > 100)
        throw std::runtime_error("Invalid opacity value.");
    opacity = op;
}

Pixel & Layer::getPixel(size_t x, size_t y) {
    return pixels[y * width + x];
}

const Pixel & Layer::getPixel(size_t x, size_t y) const {
    assert(x < width);
    assert(y < height);

    return pixels[y * width + x];
}

bool Layer::getActive() const {
    return isActive;
}

bool Layer::getVisible() const {
    return isVisible;
}

void Layer::setActive(bool active) {
    isActive = active;
}

void Layer::setVisible(bool visible) {
    isVisible = visible;
}

void Layer::resize(size_t newWidth, size_t newHeight) {
    if (height == newHeight && width == newWidth) return;

    std::vector<Pixel> newPixels(newWidth * newHeight);

    // Support for downsizing layers if needed
    const size_t copyWidth = std::min(width, newWidth);
    const size_t copyHeight = std::min(height, newHeight);

    for (size_t y = 0; y < copyHeight; y++) {
        for (size_t x = 0; x < copyWidth; x++) {
            newPixels[newWidth * y + x] = pixels[width * y + x];
        }
    }

    width = newWidth;
    height = newHeight;
    pixels = std::move(newPixels);
}

Layer Layer::merge(const Layer &bottom, const Layer &top) {
    Layer merged(bottom.getWidth(), bottom.getHeight());

    // Not supposed to happen ever, just in case
    assert(bottom.getWidth() == top.getWidth());
    assert(bottom.getHeight() == top.getHeight());

    for (size_t y = 0; y < merged.getHeight(); y++) {
        for (size_t x = 0 ; x < merged.getWidth(); x++) {
            Pixel bottomPixel = bottom.getPixel(x, y), topPixel = top.getPixel(x, y);
            double effectiveOpacity = top.opacity / 100. * topPixel.alpha / 255.;
            // Opacity is effected both by alpha and opacity of a layer as a whole
            merged.getPixel(x, y) = Pixel::merge(bottomPixel, topPixel, effectiveOpacity);
        }
    }

    return merged;
}

