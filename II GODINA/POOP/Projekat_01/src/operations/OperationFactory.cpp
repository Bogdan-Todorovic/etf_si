#include "../../include/operations/OperationFactory.hpp"
#include "../../include/operations/BlackWhiteOperation.hpp"
#include "../../include/operations/GrayScaleOperation.hpp"
#include "../../include/operations/MedianOperation.hpp"
#include <string>

// Creates BasicOperation using labda functions that are passed to constructor
// stores them in private field, for other uses their constructor directly

std::unique_ptr<Operation> OperationFactory::create(const std::string &name, int value) {
    if (name == "add")
        return makeOperation(name, [value](int x) {
            return x + value;
        }, value);

    if (name == "sub")
        return makeOperation(name, [value](int x) {
            return x - value;
        }, value);

    if (name == "invsub")
        return makeOperation(name, [value](int x) {
            return value - x;
        }, value);

    if (name == "mul")
        return makeOperation(name, [value](int x) {
            return x * value;
        }, value);

    if (name == "div")
        return makeOperation(name, [value](int x) {
            return x / value;
        }, value);

    if (name == "invdiv")
        return makeOperation(name, [value](int x) {
            return value / x;
        }, value);

    if (name == "min")
        return makeOperation(name, [value](int x) {
            return std::min(x, value);
        }, value);

    if (name == "max")
        return makeOperation(name, [value](int x) {
            return std::max(x, value);
        }, value);

    if (name == "inverse")
        return makeOperation(name, [value](int x) {
            return 255 - x;
        });

    if (name == "grayscale")
        return std::make_unique<GrayScaleOperation>(name);

    if (name == "blackwhite")
        return std::make_unique<BlackWhiteOperation>(name);

    if (name == "median")
        return std::make_unique<MedianOperation>(name);

    return nullptr;
}
