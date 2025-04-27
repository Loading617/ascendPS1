#include "main_window.hpp"
#include <iostream>

PS1EmulatorWindow::PS1EmulatorWindow() : vbox(Gtk::ORIENTATION_VERTICAL) {
    set_title("ascendPS1");
    set_default_size(960, 720);

    auto file_menu = Gtk::make_managed<Gtk::MenuItem>("File");
    auto file_submenu = Gtk::make_managed<Gtk::Menu>();
    
    auto open_iso = Gtk::make_managed<Gtk::MenuItem>("Open ISO");
    open_iso->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_open_iso));
    file_submenu->append(*open_iso);

    auto exit_item = Gtk::make_managed<Gtk::MenuItem>("Exit");
    exit_item->signal_activate().connect(sigc::mem_fun(*this, &ascendPS1Window::on_menu_exit));
    file_submenu->append(*exit_item);

    file_menu->set_submenu(*file_submenu);
    menu_bar.append(*file_menu);

    vbox.pack_start(menu_bar, Gtk::PACK_SHRINK);
    vbox.pack_start(output_area);
    add(vbox);

    show_all_children();
}

void PS1EmulatorWindow::on_menu_open_iso() {
    Gtk::FileChooserDialog dialog("Open ISO", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    auto filter = Gtk::FileFilter::create();
    filter->set_name("PlayStation ISOs");
    filter->add_pattern("*.bin");
    filter->add_pattern("*.iso");
    dialog.add_filter(filter);

    if (dialog.run() == Gtk::RESPONSE_OK) {
        std::cout << "Selected ISO: " << dialog.get_filename() << std::endl;
    }
}

void PS1EmulatorWindow::on_menu_exit() {
    hide();
}
