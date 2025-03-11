#ifndef GUI_HPP
#define GUI_HPP

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/box.h>
#include "emulator.hpp"

class GUI : public Gtk::Window {
public:
    GUI();
    virtual ~GUI();

private:
    void onOpenFile();
    void onRunEmulator();

    Gtk::Button m_button_open;
    Gtk::Button m_button_run;
    Gtk::Box m_box;
    Emulator m_emulator;
};

#endif
