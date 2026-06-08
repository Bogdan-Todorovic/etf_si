#include <utility>

#include "../../include/operations/CompositeOperation.hpp"

CompositeOperation::CompositeOperation(const std::string &name, std::string source) : Operation(name), sourceFile(std::move(source)){
}

void CompositeOperation::execute(Layer &layer) {
    for (auto &operation : operations)
        operation->execute(layer);
}

void CompositeOperation::addOperation(std::unique_ptr<Operation> operation) {
    operations.push_back(std::move(operation));
}

std::unique_ptr<Operation> CompositeOperation::clone() const {
    auto copy = std::make_unique<CompositeOperation>(getName(), sourceFile);

    for (const auto& op : operations)
        copy->addOperation(op->clone());

    return copy;
}

