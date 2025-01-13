#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void loadROM(const std::string& path);
void startEmulator();
void stopEmulator();
sf::Texture getVideoFrame();

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "PS1 Emulator");
    tgui::Gui gui{window};

    sf::RectangleShape screen(sf::Vector2f(640, 480));
    screen.setPosition(80, 20);
    screen.setFillColor(sf::Color::Black);

    auto loadButton = tgui::Button::create("Load ROM");
    loadButton->setPosition(100, 520);
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

    auto startButton = tgui::Button::create("Start");
    startButton->setPosition(320, 520);
    startButton->setSize(200, 50);
    startButton->onPress([]() {
        startEmulator();
    });
    gui.add(startButton);

    auto stopButton = tgui::Button::create("Stop");
    stopButton->setPosition(540, 520);
    stopButton->setSize(200, 50);
    stopButton->onPress([]() {
        stopEmulator();
    });
    gui.add(stopButton);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }

        window.clear();

        sf::Texture videoTexture = getVideoFrame();
        sf::Sprite videoSprite(videoTexture);
        videoSprite.setPosition(screen.getPosition());
        window.draw(videoSprite);

        gui.draw();
        window.display();
    }

    return 0;
}
