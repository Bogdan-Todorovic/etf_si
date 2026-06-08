#ifndef IMAGEFORGE_MENU_HPP
#define IMAGEFORGE_MENU_HPP
#include <memory>
#include <optional>
#include "../core/Image.hpp"
#include "../core/Layer.hpp"
#include "../operations/Operation.hpp"

// CLI menu for interacting with user, nothing interesting just long

class CompositeOperation;
class Operation;

class Menu {
public:
    Menu() = default;
    void run();

private:
    std::optional<Image> image;
    bool isSavedImage = false;
    bool isSavedProject = false;
    bool isSavedComposite = false;

    static void printMenu();
    static void printOperationsMenu();
    [[nodiscard]] size_t selectLayer() const;
    std::unique_ptr<Operation>createOperationFromMenu();
    void loadImage();
    void saveImage();
    void addLayer();
    void deleteLayer();
    void setLayerOpacity();
    void toggleLayerVisibility();
    void toggleLayerActivity();
    void applyOperation();
    void applyCompositeOperation();
    void createCompositeOperation();
    void exportCompositeOperation();
    void importCompositeOperation();
    void resizeImage();
    void saveProject();
    void loadProject();
    void quitProgram();
};


#endif //IMAGEFORGE_MENU_HPP