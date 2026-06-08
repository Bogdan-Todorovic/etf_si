#include "../../include/operations/MedianOperation.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/core/Pixel.hpp"

MedianOperation::MedianOperation(const std::string &name) : Operation(name){}

void MedianOperation::execute(Layer &layer) {
    int width = static_cast<int>(layer.getWidth());
    int height = static_cast<int>(layer.getHeight());

    Layer newLayer(layer.getWidth(), layer.getHeight());

    std::vector<uint8_t> surrPixelsRed;
    std::vector<uint8_t> surrPixelsGreen;
    std::vector<uint8_t> surrPixelsBlue;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int i = y - 1; i <= y + 1; i++) {
                for (int j = x - 1; j <= x + 1; j++) {
                    // Corners don't have 9 neighbors
                    if (j < 0 || i < 0 || j >= layer.getWidth() || i >= layer.getHeight()) continue;
                    surrPixelsRed.push_back(layer.getPixel(j, i).red);
                    surrPixelsGreen.push_back(layer.getPixel(j, i).green);
                    surrPixelsBlue.push_back(layer.getPixel(j, i).blue);
                }
            }

            auto medianR = surrPixelsRed.begin() + static_cast<int>(surrPixelsRed.size()) / 2;
            auto medianG = surrPixelsGreen.begin() + static_cast<int>(surrPixelsGreen.size()) / 2;
            auto medianB = surrPixelsBlue.begin() + static_cast<int>(surrPixelsBlue.size()) / 2;

            // std::nth_element has O(n) time complexity
            // Median is element that separates bottom and top half of some array
            std::nth_element(surrPixelsRed.begin(), medianR, surrPixelsRed.end());
            std::nth_element(surrPixelsGreen.begin(), medianG, surrPixelsGreen.end());
            std::nth_element(surrPixelsBlue.begin(), medianB, surrPixelsBlue.end());

            newLayer.getPixel(x, y) = Pixel(*medianR, *medianG, *medianB);

            surrPixelsRed.clear();
            surrPixelsBlue.clear();
            surrPixelsGreen.clear();
        }
    }

    layer = newLayer;
}

std::unique_ptr<Operation> MedianOperation::clone() const {
    return std::make_unique<MedianOperation>(*this);
}
