#ifndef IMAGEFORGE_BLACKWHITEOPERATION_HPP
#define IMAGEFORGE_BLACKWHITEOPERATION_HPP
#include "Operation.hpp"
#include <memory>
// Operation that turns photo in black and white

class BlackWhiteOperation : public Operation{
public:
    explicit BlackWhiteOperation(const std::string &name);
    void execute(Layer &layer) override;
    [[nodiscard]] std::unique_ptr<Operation> clone() const override;
};


#endif //IMAGEFORGE_BLACKWHITEOPERATION_HPP