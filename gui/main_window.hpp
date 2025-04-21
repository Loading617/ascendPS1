#pragma once
#include <gtkmm.h>

class ascendPS1Window : public Gtk::Window {
public:
    ascendPS1Window();
    virtual ~ascendPS1Window() = default;

private:
    Gtk::Box vbox;
    Gtk::MenuBar menu_bar;
    Gtk::DrawingArea output_area;

    void on_menu_open_iso();
    void on_menu_exit();
};
