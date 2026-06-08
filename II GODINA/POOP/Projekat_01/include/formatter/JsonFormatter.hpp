#ifndef IMAGEFORGE_MYFORMATTER_HPP
#define IMAGEFORGE_MYFORMATTER_HPP
#include <memory>
#include <string>
#include "../json.hpp"

// Used for saving/loading projects, represented by json file.
// It saves/loads all relevant information about image (class object)

class CompositeOperation;
class Layer;
class Operation;
class Image;

class JsonFormatter {
public:
    static Image load(const std::string& path);
    static void save(const Image &image, const std::string& path);
    static std::unique_ptr<Operation> loadComposite(const std::string& path);
    static void saveComposite(Operation &compositeOperation, const std::string &path);

private:
    // Helper functions for turning layer/operation info to json
    static nlohmann::json serializeLayer(const Layer& layer);
    static nlohmann::json serializeComposite(const CompositeOperation& operation);
};


#endif //IMAGEFORGE_MYFORMATTER_HPP