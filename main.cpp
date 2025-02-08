#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

void loadROM(const std::string& path) {
    
    std::cout << "Loaded ROM: " << path << std::endl;
}

void runEmulator() {
    
    std::cout << "Running emulator..." << std::endl;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "AttackPS1");
    tgui::Gui gui{window};

    tgui::Theme theme{"Black.txt"};

    auto loadButton = tgui::Button::create("Load ROM");
    loadButton->setPosition(100, 100);
    loadButton->setSize(200, 50);
    loadButton->onPress([&gui]() {
        auto fileDialog = tgui::FileDialog::create();
        fileDialog->setTitle("Open ROM");
        fileDialog->onFileSelect([](const std::string& path) {
            loadROM(path);
        });
        gui.add(fileDialog);
    });
    gui.add(loadButton);

    auto runButton = tgui::Button::create("Run");
    runButton->setPosition(100, 200);
    runButton->setSize(200, 50);
    runButton->onPress([]() {
        runEmulator();
    });
    gui.add(runButton);

    sf::RectangleShape screen(sf::Vector2f(640, 480));
    screen.setPosition(300, 100);
    screen.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }

        window.clear();
        window.draw(screen);
        gui.draw();
        window.display();
    }

    return 0;
}
