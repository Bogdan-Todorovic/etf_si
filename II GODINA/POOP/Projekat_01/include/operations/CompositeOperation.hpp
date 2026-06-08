#ifndef IMAGEFORGE_COMPOSITEOPERATION_HPP
#define IMAGEFORGE_COMPOSITEOPERATION_HPP
#include <memory>
#include <vector>
#include "Operation.hpp"

// Class that allows for chaining multiple operations together

class CompositeOperation : public Operation {
public:
    explicit CompositeOperation(const std::string & name, std::string source = "");
    void execute(Layer &layer) override;
    void addOperation(std::unique_ptr<Operation> operation);
    [[nodiscard]] std::unique_ptr<Operation> clone() const override;
    // Where is operation stored/loaded from
    std::string sourceFile;
    std::vector<std::unique_ptr<Operation>> operations;
};


#endif //IMAGEFORGE_COMPOSITEOPERATION_HPP