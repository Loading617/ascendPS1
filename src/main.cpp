#include "gui.hpp"
#include <gtkmm/application.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.ps1.emulator");
    GUI gui;
    return app->run(gui);
}
