#include "../../include/operations/BlackWhiteOperation.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/core/Pixel.hpp"

BlackWhiteOperation::BlackWhiteOperation(const std::string &name) : Operation(name){}

void BlackWhiteOperation::execute(Layer &layer) {
    Pixel black = Pixel(0, 0, 0);
    Pixel white = Pixel(255, 255, 255);

    for (auto& pixel : layer.pixels) {
        uint8_t avg = (pixel.red + pixel.green + pixel.blue) / 3;
        if (avg < 127)
            pixel = black;
        else
            pixel = white;
    }
}

std::unique_ptr<Operation> BlackWhiteOperation::clone() const {
    return std::make_unique<BlackWhiteOperation>(*this);
}
