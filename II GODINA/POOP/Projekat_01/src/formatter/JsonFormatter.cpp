#include "../../include/formatter/JsonFormatter.hpp"
#include "../../include/core/Image.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/operations/CompositeOperation.hpp"
#include <fstream>
#include <regex>
#include "../../include/formatter/BMPFormatter.hpp"
#include "../../include/operations/OperationFactory.hpp"


Image JsonFormatter:: load(const std::string &path) {
    std::regex jsonFormat(R"(.*\.json$)");
    if (!std::regex_match(path, jsonFormat))
        throw std::runtime_error("Invalid project file");

    std::ifstream file(path);
    if (!file)
        throw std::runtime_error("Cannot open file.");

    nlohmann::json j;
    file >> j; // Writing context of file to json structure

    size_t w = j["width"], h = j["height"];
    Image image(w, h);
    for (auto& layerJson : j["layers"]) {
        Layer layer(w, h);
        if (layerJson.contains("source"))
            layer = BMPFormatter::load(layerJson["source"]);

        layer.setOpacity(layerJson.value("opacity", 100));
        layer.setActive(layerJson.value("active", false));
        layer.setVisible(layerJson.value("visible", true));
        image.loadLayer(layer);
    }

    for (auto& layerOp : j["compositeOperations"])
        image.addCompositeOperation(loadComposite(layerOp["file"]));

    return image;
}

void JsonFormatter::save(const Image &image, const std::string &path) {
    nlohmann::json j;
    j["width"] = image.getWidth();
    j["height"] = image.getHeight();

    j["layers"] = nlohmann::json::array();
    j["compositeOperations"] = nlohmann::json::array();

    for (auto & layer : image.layers)
        j["layers"].push_back(serializeLayer(layer));

    for (auto &[name, operation] : image.compositeOperations) {
        nlohmann::json compositeJson;
        compositeJson["file"] = dynamic_cast<CompositeOperation*>(operation.get())->sourceFile;
        j["compositeOperations"].push_back(compositeJson);
    }

    // Writing json to file
    std::ofstream file(path);
    file << j.dump(4);
}

std::unique_ptr<Operation> JsonFormatter::loadComposite(const std::string &path) {
    std::regex jsonFormat(R"(.*\.fun$)");
    if (!std::regex_match(path, jsonFormat))
        throw std::runtime_error("Invalid composite operation file.");

    std::ifstream file(path);
    if (!file)
        throw std::runtime_error("Cannot open file.");

    nlohmann::json j;
    file >> j;

    auto compositeOperation = std::make_unique<CompositeOperation>(j["name"], path);
    for (auto &operationJson : j["operations"]) {
        std::unique_ptr<Operation> operation;

        if (operationJson.contains("sourceFile"))
            operation = loadComposite(operationJson["sourceFile"]);
        else {
            operation = OperationFactory::create(
                operationJson.value("type", ""),
                operationJson.value("argument", 0)
            );
        }
        if (!operation)
            throw std::runtime_error("Invalid operation.");

        compositeOperation->addOperation(std::move(operation));
    }

    return compositeOperation;
}

void JsonFormatter::saveComposite(Operation &compositeOperation, const std::string& path) {
    std::regex jsonFormat(R"(.*\.fun$)");
    if (!std::regex_match(path, jsonFormat))
        throw std::runtime_error("Invalid composite operation file.");

    auto* composite = dynamic_cast<CompositeOperation*>(&compositeOperation);
    if (!composite)
        throw std::runtime_error("Operation is not composite.");

    std::ofstream file(path);
    if (!file)
        throw std::runtime_error("Cannot open file.");

    // Writing to file
    composite->sourceFile = path;
    file << serializeComposite(*composite).dump(4);
}

nlohmann::json JsonFormatter::serializeLayer(const Layer &layer) {
    nlohmann::json j;

    if (!layer.path.empty())
        j["source"] = layer.path;

    j["opacity"] = layer.getOpacity();
    j["active"] = layer.getActive();
    j["visible"] = layer.getVisible();

    return j;
}

nlohmann::json JsonFormatter::serializeComposite(const CompositeOperation &operation) {
    nlohmann::json j;
    j["name"] = operation.getName();
    j["operations"] = nlohmann::json::array();

    for (auto &op : operation.operations) {
        nlohmann::json opJson;
        if (auto* composite = dynamic_cast<CompositeOperation*>(op.get()))
            opJson["file"] = composite->sourceFile;
        else {
            opJson["type"] = op->getName();
            if (auto argument = op->getArgument())
                opJson["argument"] = *argument;
        }
        j["operations"].push_back(opJson);
    }

    return j;
}
