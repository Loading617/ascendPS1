#ifndef GUI_HPP
#define GUI_HPP

#include <gtkmm.h>

class GUI : public Gtk::Window {
public:
    GUI();
    virtual ~GUI();

private:
    void on_open_rom();
    
    Gtk::Box main_box;
    Gtk::Button open_rom_button;
    Gtk::Label status_label;
};

#endif
