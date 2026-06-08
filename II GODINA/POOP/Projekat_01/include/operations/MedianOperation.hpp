#ifndef IMAGEFORGE_MEDIANOPERATION_HPP
#define IMAGEFORGE_MEDIANOPERATION_HPP
#include <memory>
#include "Operation.hpp"

// Median filter takes neighboring (max) 9 pixels and takes median of each RGB value
// Stores it in new layer with that median value

class MedianOperation : public Operation{
public:
    explicit MedianOperation(const std::string &name);
    void execute(Layer &layer) override;
    [[nodiscard]] std::unique_ptr<Operation> clone() const override;
};


#endif //IMAGEFORGE_MEDIANOPERATION_HPP