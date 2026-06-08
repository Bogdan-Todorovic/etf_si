#ifndef IMAGEFORGE_OPERATION_HPP
#define IMAGEFORGE_OPERATION_HPP
#include <optional>
#include <string>
#include <utility>
#include <memory>
class Layer;
class Pixel;

// Base class for all operations

class Operation {
public:
    virtual ~Operation() = default;
    explicit Operation(std::string name, const std::optional<int> value = std::nullopt) : name(std::move(name)), argument(value){}

    virtual void execute (Layer & layer) = 0;

    [[nodiscard]] std::string getName() const {return name;}
    [[nodiscard]] auto getArgument() const {return argument;}

    [[nodiscard]] virtual std::unique_ptr<Operation> clone() const = 0;
protected:
    std::string name;
    // Some operations take argument, while others don't, needed for saving context of project.
    std::optional<int> argument;
};


#endif //IMAGEFORGE_OPERATION_HPP