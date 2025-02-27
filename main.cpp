#include <gtkmm.h>
#include <gtkmm/glarea.h>
#include <iostream>

class EmulatorWindow : public Gtk::Window {
public:
    EmulatorWindow();

private:
    void on_open_rom();
    void on_quit();
    void on_render(const Glib::RefPtr<Gdk::GLContext>& context);

    Gtk::Box vbox;
    Gtk::MenuBar menu_bar;
    Gtk::MenuItem file_menu_item;
    Gtk::Menu file_menu;
    Gtk::MenuItem open_rom_item;
    Gtk::MenuItem quit_item;
    Gtk::GLArea gl_area;
};

EmulatorWindow::EmulatorWindow() {
    set_title("AscendPS1");
    set_default_size(800, 600);

    file_menu_item.set_label("File");
    open_rom_item.set_label("Open ROM");
    quit_item.set_label("Quit");

    open_rom_item.signal_activate().connect(sigc::mem_fun(*this, &EmulatorWindow::on_open_rom));
    quit_item.signal_activate().connect(sigc::mem_fun(*this, &EmulatorWindow::on_quit));

    file_menu.append(open_rom_item);
    file_menu.append(quit_item);
    file_menu_item.set_submenu(file_menu);
    menu_bar.append(file_menu_item);

    vbox.pack_start(menu_bar, Gtk::PACK_SHRINK);
    vbox.pack_start(gl_area);

    add(vbox);
    show_all_children();

    gl_area.set_auto_render();
    gl_area.signal_render().connect(sigc::mem_fun(*this, &EmulatorWindow::on_render));
}

void EmulatorWindow::on_open_rom() {
    Gtk::FileChooserDialog dialog(*this, "Open PS1 ROM", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("Open", Gtk::RESPONSE_OK);

    auto filter = Gtk::FileFilter::create();
    filter->set_name("PS1 ROMs");
    filter->add_pattern("*.iso");
    filter->add_pattern("*.bin");
    dialog.add_filter(filter);

    if (dialog.run() == Gtk::RESPONSE_OK) {
        std::string filename = dialog.get_filename();
        std::cout << "Loaded ROM: " << filename << std::endl;
    }
}

void EmulatorWindow::on_quit() {
    hide();
}

void EmulatorWindow::on_render(const Glib::RefPtr<Gdk::GLContext>& context) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.example.ascendps1");
    EmulatorWindow window;
    return app->run(window);
}
