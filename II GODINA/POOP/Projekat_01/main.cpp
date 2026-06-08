#include "include/formatter/BMPFormatter.hpp"
#include "include/formatter/JsonFormatter.hpp"
#include "include/ui/Menu.hpp"

int main(int argc, char* argv[]) {
    if (argc == 3) {
        Image image(0, 0);
        Layer layer = BMPFormatter::load(argv[1]);
        image.loadLayer(std::move(layer));

        auto operation = JsonFormatter::loadComposite(argv[2]);

        image.applyOperation(operation);
        image.save(argv[1]);

        return 0;
    }

    Menu menu;
    menu.run();

    return 0;
}
