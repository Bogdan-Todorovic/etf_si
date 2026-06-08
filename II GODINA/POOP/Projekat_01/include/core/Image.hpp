#ifndef IMAGEFORGE_IMAGE_HPP
#define IMAGEFORGE_IMAGE_HPP
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// Core class of the project, connects pixels, layers, and operations together

class Operation;
class Layer;

class Image {
public:
    Image(size_t width, size_t height);
    void createLayer();
    void loadLayer(Layer layer);
    void removeLayer(size_t index);
    Layer & getLayer(size_t index);

    void applyOperation(const std::unique_ptr<Operation> &operation);
    void addCompositeOperation(std::unique_ptr<Operation> operation);

    // Merges all layers in one layer. Does not affect other layers.
    Layer render();
    // Changes dimensions of all layers to match new ones
    void resize(size_t newWidth, size_t newHeight);
    void save(const std::string& path);

    [[nodiscard]] size_t getWidth() const;
    [[nodiscard]] size_t getHeight() const;
    std::vector<Layer> layers;
    std::unordered_map<std::string, std::unique_ptr<Operation>> compositeOperations;

private:
    size_t width, height;
};


#endif //IMAGEFORGE_IMAGE_HPP