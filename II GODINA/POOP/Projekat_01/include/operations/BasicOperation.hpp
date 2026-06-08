#ifndef IMAGEFORGE_BASICOPERATION_HPP
#define IMAGEFORGE_BASICOPERATION_HPP
#include "Operation.hpp"
#include "../core/Layer.hpp"
#include "../core/Pixel.hpp"
#include <memory>

// Template class that represents all basic arithmetic operations.
// Apart from name and argument only holds function for that operation.

template <typename F>
class BasicOperation : public Operation{
public:
    BasicOperation(const std::string &name, F function, std::optional<int> value = std::nullopt) : Operation(name, value), function(function){}
    void execute(Layer & layer) override;
    [[nodiscard]] std::unique_ptr<Operation> clone() const override;
private:
    F function;
};

template<typename F>
void BasicOperation<F>::execute(Layer &layer) {
    for (auto& pixel : layer.pixels)
        pixel.transform(function);
}

template<typename F>
std::unique_ptr<Operation> BasicOperation<F>::clone() const {
    return std::make_unique<BasicOperation>(*this);
}


#endif //IMAGEFORGE_BASICOPERATION_HPP
