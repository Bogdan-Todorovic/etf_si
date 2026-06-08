#ifndef IMAGEFORGE_GRAYSCALEOPERATION_HPP
#define IMAGEFORGE_GRAYSCALEOPERATION_HPP
#include <memory>

#include "Operation.hpp"

// Add Gray Scale effect to image

class GrayScaleOperation : public Operation{
public:
    explicit GrayScaleOperation(const std::string &name);
    void execute(Layer &layer) override;
    [[nodiscard]] std::unique_ptr<Operation> clone() const override;
};


#endif //IMAGEFORGE_GRAYSCALEOPERATION_HPP