#include "gui.hpp"
#include <gtkmm/messagedialog.h>

GUI::GUI()
    : m_button_open("Open ROM"), m_button_run("Run Emulator") {
    set_title("ascendPS1");
    set_default_size(400, 200);

    m_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_box.set_spacing(10);
    m_box.set_margin(10);

    m_button_open.signal_clicked().connect(sigc::mem_fun(*this, &GUI::onOpenFile));
    m_button_run.signal_clicked().connect(sigc::mem_fun(*this, &GUI::onRunEmulator));

    m_box.pack_start(m_button_open);
    m_box.pack_start(m_button_run);
    add(m_box);

    show_all_children();
}

GUI::~GUI() {}

void GUI::onOpenFile() {
    Gtk::FileChooserDialog dialog("Select a ROM", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    if (dialog.run() == Gtk::RESPONSE_OK) {
        m_emulator.loadROM(dialog.get_filename());
    }
}

void GUI::onRunEmulator() {
    m_emulator.run();
}
