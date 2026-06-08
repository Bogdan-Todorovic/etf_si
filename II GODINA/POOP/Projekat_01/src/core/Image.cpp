#include "../../include/core/Image.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/core/Pixel.hpp"
#include "../../include/formatter/BMPFormatter.hpp"
#include "../../include/operations/Operation.hpp"

#include <algorithm>
#include <stdexcept>

Image::Image(size_t width, size_t height) : width(width), height(height){}

void Image::createLayer() {
    // emplace constructs object directly inside container's memory
    layers.emplace_back(width, height);
}

void Image::loadLayer(Layer layer) {
    size_t layerHeight = layer.getHeight(), layerWidth = layer.getWidth();
    if (layerHeight != height || layerWidth != width) {
        layer.resize(std::max(width, layerWidth), std::max(height, layerHeight));
        this->resize(std::max(width, layerWidth), std::max(height, layerHeight));
    }

    layers.push_back(layer);
}

void Image::removeLayer(size_t index) {
    if (index >= layers.size())
        throw std::runtime_error("Illegal layer for removal.");

    layers.erase(layers.begin() + static_cast<long long>(index));
}

Layer & Image::getLayer(size_t index) {
    return layers[index];
}

void Image::applyOperation(const std::unique_ptr<Operation> &operation) {
    for (auto &layer : layers)
        if (layer.getActive())
            operation->execute(layer);
}

void Image::addCompositeOperation(std::unique_ptr<Operation> operation) {
    compositeOperations[operation->getName()] = std::move(operation);
}

Layer Image::render() {
    size_t firstVisible = 0;
    // Finding first visible layer
    while ( firstVisible != layers.size() && !layers[firstVisible].getVisible())
        firstVisible++;

    if (firstVisible == layers.size())
        throw std::runtime_error("No visible layers to render");

    Layer result = layers[firstVisible];
    // Iterator is expressed by long long, hence cast in long long
    for (auto layer = layers.begin() + static_cast<long long>(firstVisible) + 1; layer != layers.end(); ++layer) {
        if (layer->getVisible())
            result = Layer::merge(result, *layer);
    }

    return result;
}

void Image::resize(size_t newWidth, size_t newHeight) {
    if (width == newWidth && height == newHeight) return;

    for (auto& layer : layers)
        layer.resize(newWidth, newHeight);

    width = newWidth;
    height = newHeight;
}

void Image::save(const std::string& path) {
    Layer layer = render();
    BMPFormatter::save(layer, path);
}

size_t Image::getWidth() const {
    return width;
}

size_t Image::getHeight() const {
    return height;
}
