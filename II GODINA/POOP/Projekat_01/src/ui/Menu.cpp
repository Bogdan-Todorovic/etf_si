#include "../../include/ui/Menu.hpp"
#include "../../include/core/Layer.hpp"
#include "../../include/core/Image.hpp"
#include "../../include/operations/OperationFactory.hpp"
#include "../../include/operations/GrayScaleOperation.hpp"
#include "../../include/operations/BlackWhiteOperation.hpp"
#include "../../include/operations/MedianOperation.hpp"
#include "../../include/formatter/BMPFormatter.hpp"
#include "../../include/formatter/JsonFormatter.hpp"
#include "../../include/operations/CompositeOperation.hpp"
#include <iostream>

// Implementation off all the boring CLI functions...

void Menu::printMenu() {
    std::cout << "\n=====================================\n";
    std::cout << "            IMAGE FORGE\n";
    std::cout << "=====================================\n\n";
    std::cout << " Images & Layers\n";
    std::cout << "-------------------------------------\n";
    std::cout << " 1. Load image\n";
    std::cout << " 2. Save image\n";
    std::cout << " 3. Resize image\n";
    std::cout << " 4. Add layer\n";
    std::cout << " 5. Delete layer\n";
    std::cout << " 6. Set layer opacity\n";
    std::cout << " 7. Toggle layer visibility\n";
    std::cout << " 8. Toggle layer activity\n\n";
    std::cout << " Operations\n";
    std::cout << "-------------------------------------\n";
    std::cout << " 9. Apply operation\n";
    std::cout << "10. Apply composite operation\n";
    std::cout << "11. Create composite operation\n";
    std::cout << "12. Export composite operation\n";
    std::cout << "13. Import composite operation\n\n";
    std::cout << " Project\n";
    std::cout << "-------------------------------------\n";
    std::cout << "14. Save project\n";
    std::cout << "15. Load project\n\n";
    std::cout << " 0. Exit\n\n";
    std::cout << "Choice: ";
}

void Menu::printOperationsMenu() {
    std::cout << "\n=====================================\n";
    std::cout << "         AVAILABLE OPERATIONS\n";
    std::cout << "=====================================\n\n";

    std::cout << " 1. Add\n";
    std::cout << " 2. Subtract\n";
    std::cout << " 3. Inverse Subtract\n";
    std::cout << " 4. Multiply\n";
    std::cout << " 5. Divide\n";
    std::cout << " 6. Inverse Divide\n";
    std::cout << " 7. Min\n";
    std::cout << " 8. Max\n";
    std::cout << " 9. Inverse\n";
    std::cout << "10. Gray Scale\n";
    std::cout << "11. Black & White\n";
    std::cout << "12. Median Filter\n\n";
    std::cout << "13. Composite Operation\n\n";

    std::cout << " 0. Back\n\n";
}

size_t Menu::selectLayer() const {
    if (image->layers.empty())
        throw std::runtime_error("No layers available");

    std::cout << "\nAvailable layers:\n";

    for (size_t i = 0; i < image->layers.size(); i++) {
        const auto& layer = image->layers[i];
        std::cout << i << ". Layer " << i << " ["
            << (layer.getVisible() ? "Visible" : "Hidden") << ", "
            << (layer.getActive() ? "Active" : "Inactive") << "]\n";
    }

    size_t index;
    std::cout << "\nSelect layer: ";
    std::cin >> index;

    if (index >= image->layers.size())
        throw std::runtime_error("Invalid layer index");

    return index;
}

std::unique_ptr<Operation> Menu::createOperationFromMenu() {
    printOperationsMenu();
    int choice;
    std::cout << "Choice: ";
    std::cin >> choice;

    int value;
    switch (choice) {
        case 1:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("add", value);

        case 2:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("sub", value);

        case 3:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("invsub", value);

        case 4:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("mul", value);

        case 5:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("div", value);

        case 6:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("invdiv", value);

        case 7:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("min", value);

        case 8:
            std::cout << "Value: ";
            std::cin >> value;
            return OperationFactory::create("max", value);

        case 9:
            return OperationFactory::create("inverse", 0);

        case 10:
            return std::make_unique<GrayScaleOperation>("grayScale");

        case 11:
            return std::make_unique<BlackWhiteOperation>("blackWhite");

        case 12:
            return std::make_unique<MedianOperation>("median");

        case 13: {
            std::cout << "\nAvailable composite operations:\n";
            for (const auto& [name, operation] : image->compositeOperations)
                std::cout << " - " << name << '\n';

            std::string name;
            std::cout << "\nComposite operation name: ";
            std::getline(std::cin >> std::ws, name);
            auto it = image->compositeOperations.find(name);

            if (it == image->compositeOperations.end())
                throw std::runtime_error("Composite operation not found.");

            return it->second->clone();
        }
        default:
            throw std::runtime_error("Invalid operation selected");
    }
}

void Menu::loadImage() {
    isSavedProject = false;
    isSavedImage = false;
    Image newImage(0, 0);

    if (!image.has_value()) {
        int choice;
        std::cout << "1. Load image from BMP\n";
        std::cout << "2. Create empty image\n";
        std::cout << "Choice: ";

        std::cin >> choice;
        if (choice == 1) {
            std::string path;
            std::cout << "Image path: ";
            std::getline(std::cin >> std::ws, path);
            Layer layer = BMPFormatter::load(path);
            newImage.loadLayer(std::move(layer));

        } else if (choice == 2) {
            size_t width, height;
            std::cout << "Width: ";
            std::cin >> width;

            std::cout << "Height: ";
            std::cin >> height;
            Layer layer(width, height);
            newImage.loadLayer(std::move(layer));

        } else {
            std::cout << "Invalid option.\n";
            return;
        }
        image = std::move(newImage);
    } else {
        std::string path;
        std::cout << "Image path: ";
        std::getline(std::cin >> std::ws, path);

        Layer layer = BMPFormatter::load(path);
        image->loadLayer(std::move(layer));
    }
    std::cout << "Image loaded successfully.\n";
}

void Menu::saveImage() {
    if (!image)
        throw std::runtime_error("No image loaded");

    std::string path;
    std::cout << "Save path: ";
    std::getline(std::cin >> std::ws, path);

    std::cout << image->getLayer(0).getVisible();
    image->save(path);
    isSavedImage = true;
}

void Menu::addLayer() {
    isSavedProject = false;
    isSavedImage = false;

    int choice;
    std::cout << "1. Empty layer\n";
    std::cout << "2. Load layer from BMP\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    if (choice == 1)
        image->createLayer();
    else if (choice == 2) {
        std::string path;
        std::cout << "BMP path: ";
        std::getline(std::cin >> std::ws, path);
        Layer layer = BMPFormatter::load(path);
        image->loadLayer(layer);
    } else
        throw std::runtime_error("Invalid choice");
}

void Menu::deleteLayer() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");

    size_t index = selectLayer();
    image->removeLayer(index);
}

void Menu::setLayerOpacity() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");

    size_t index = selectLayer();
    int opacity;
    std::cout << "Opacity (0-100): ";
    std::cin >> opacity;

    image->getLayer(index).setOpacity(opacity);
}

void Menu::toggleLayerVisibility() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");

    size_t index = selectLayer();
    auto& layer = image->getLayer(index);
    layer.setVisible(!layer.getVisible());
}

void Menu::toggleLayerActivity() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");

    size_t index = selectLayer();
    auto& layer = image->getLayer(index);
    layer.setActive(!layer.getActive());
}

void Menu::applyOperation() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");

    auto operation = createOperationFromMenu();
    image->applyOperation(operation);
}

void Menu::applyCompositeOperation() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");
    std::string name;
    std::cout << "Composite operation name: ";
    std::getline(std::cin >> std::ws, name);

    auto it = image->compositeOperations.find(name);
    if (it == image->compositeOperations.end())
        throw std::runtime_error("Composite operation not found");

    image->applyOperation(it->second);
}

void Menu::createCompositeOperation() {
    std::string name;
    std::cout << "Composite operation name: ";
    std::getline(std::cin >> std::ws, name);

    std::unique_ptr<CompositeOperation> composite = std::make_unique<CompositeOperation>(name);
    while (true) {
        std::cout << "\nAdd operation?\n";
        std::cout << "1. Yes\n";
        std::cout << "0. Finish\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        if (choice == 0)
            break;

        auto operation = createOperationFromMenu();
        composite->addOperation(std::move(operation));
    }

    image->addCompositeOperation(std::move(composite));
    std::cout << "Composite operation created.\n";
}

void Menu::exportCompositeOperation() {
    std::string name;
    std::cout << "Composite operation name: ";
    std::getline(std::cin >> std::ws, name);
    auto it = image->compositeOperations.find(name);

    if (it == image->compositeOperations.end())
        throw std::runtime_error("Composite operation not found");

    std::string path;
    std::cout << "Export path: ";
    std::getline(std::cin >> std::ws, path);

    JsonFormatter::saveComposite(*it->second, path);
    std::cout << "Composite operation exported.\n";
}

void Menu::importCompositeOperation() {
    isSavedProject = false;
    isSavedImage = false;

    std::string path;
    std::cout << "Import path: ";
    std::getline(std::cin >> std::ws, path);

    auto composite = JsonFormatter::loadComposite(path);
    image->compositeOperations[composite->getName()] = std::move(composite);

    std::cout << "Composite operation imported.\n";
}

void Menu::resizeImage() {
    isSavedProject = false;
    isSavedImage = false;

    if (!image)
        throw std::runtime_error("No image loaded");

    size_t width;
    size_t height;
    std::cout << "Width: ";
    std::cin >> width;
    std::cout << "Height: ";
    std::cin >> height;

    image->resize(width, height);
}

void Menu::saveProject() {
    if (!image)
        throw std::runtime_error("No image loaded");

    std::string path;
    std::cout << "Project path: ";
    std::getline(std::cin >> std::ws, path);

    for (auto& [name, operation] : image->compositeOperations) {
        auto* composite = dynamic_cast<CompositeOperation*>(operation.get());
        if (!composite)
            continue;

        if (composite->sourceFile.empty())
            composite->sourceFile = name + ".fun";

        JsonFormatter::saveComposite(*composite, composite->sourceFile);
    }

    JsonFormatter::save(*image, path);
    std::cout << "Project saved successfully.\n";
    isSavedProject = true;
}

void Menu::loadProject() {
    isSavedProject = false;
    isSavedImage = false;

    std::string path;
    std::cout << "Project path: ";
    std::getline(std::cin >> std::ws, path);

    image = JsonFormatter::load(path);
    std::cout << "Project loaded successfully.\n";
}

void Menu::quitProgram() {
    char choice;
    if (!isSavedImage) {
        std::cout << "Image is not saved. Save before exit? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y')
            saveImage();
    }

    if (!isSavedProject) {
        std::cout << "Project is not saved. Save before exit? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y')
            saveProject();
    }
}

void Menu::run() {
    int choice;
    while (true) {
        printMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                loadImage();
                break;
            case 2:
                saveImage();
                break;
            case 3:
                resizeImage();
                break;
            case 4:
                addLayer();
                break;
            case 5:
                deleteLayer();
                break;
            case 6:
                setLayerOpacity();
                break;
            case 7:
                toggleLayerVisibility();
                break;
            case 8:
                toggleLayerActivity();
                break;
            case 9:
                applyOperation();
                break;
            case 10:
                applyCompositeOperation();
                break;
            case 11:
                createCompositeOperation();
                break;
            case 12:
                exportCompositeOperation();
                break;
            case 13:
                importCompositeOperation();
                break;
            case 14:
                saveProject();
                break;
            case 15:
                loadProject();
                break;
            case 0:
                quitProgram();
                return;
            default:
                std::cout << "Invalid option!\n";
                break;
        }
    }
}
