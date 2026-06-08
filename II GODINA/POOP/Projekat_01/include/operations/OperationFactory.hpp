#ifndef IMAGEFORGE_BASICOPERATIONFACTORY_HPP
#define IMAGEFORGE_BASICOPERATIONFACTORY_HPP
#include <memory>
#include "BasicOperation.hpp"

// Factory class for creating operations.

class OperationFactory {
public:
    static std::unique_ptr<Operation> create(const std::string& name, int value);

private:
    // Factory template function for making operations
    template <typename F>
    static auto makeOperation(std::string name, F f, std::optional<int> value = std::nullopt) {
        return std::make_unique<BasicOperation<F>>(std::move(name), std::move(f), value);
    }
};

#endif //IMAGEFORGE_BASICOPERATIONFACTORY_HPP