#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "AttackPS1");
    tgui::Gui gui(window);

    auto theme = tgui::Theme::create("TGUI/themes/Black.txt");

    auto loadButton = theme->load("Button");
    loadButton->setText("Load ROM");
    loadButton->setSize(200, 50);
    loadButton->setPosition(300, 250);
    gui.add(loadButton);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            gui.handleEvent(event);
        }

        window.clear();
        gui.draw();
        window.display();
    }

    return 0;
}
