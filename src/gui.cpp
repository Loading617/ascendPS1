#include "gui.hpp"
#include <iostream>

GUI::GUI() : open_rom_button("Open ROM") {
    set_title("ascendPS1");
    set_default_size(600, 400);

    main_box.set_orientation(Gtk::ORIENTATION::VERTICAL);
    add(main_box);

    open_rom_button.signal_clicked().connect(sigc::mem_fun(*this, &GUI::on_open_rom));
    
    main_box.pack_start(open_rom_button, Gtk::PACK_SHRINK);
    main_box.pack_start(status_label, Gtk::PACK_SHRINK);
}

GUI::~GUI() {}

void GUI::on_open_rom() {
    Gtk::FileChooserDialog dialog(*this, "Open PS1 ROM", Gtk::FileChooser::Action::OPEN);
    dialog.add_button("_Cancel", Gtk::ResponseType::CANCEL);
    dialog.add_button("_Open", Gtk::ResponseType::OK);

    if (dialog.run() == Gtk::ResponseType::OK) {
        std::string filename = dialog.get_file()->get_path();
        status_label.set_text("Loaded: " + filename);
        std::cout << "Opened ROM: " << filename << std::endl;
    }
}
