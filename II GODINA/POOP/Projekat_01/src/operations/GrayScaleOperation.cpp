#include "../../include/operations/GrayScaleOperation.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/core/Pixel.hpp"

GrayScaleOperation::GrayScaleOperation(const std::string &name) : Operation(name){}

void GrayScaleOperation::execute(Layer &layer) {
    for (auto& pixel : layer.pixels) {
        uint8_t avg = (pixel.red + pixel.green + pixel.blue) / 3;
        pixel.red = pixel.green = pixel.blue = avg;
    }
}

std::unique_ptr<Operation> GrayScaleOperation::clone() const {
    return std::make_unique<GrayScaleOperation>(*this);
}

