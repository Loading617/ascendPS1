#ifndef GPU_HPP
#define GPU_HPP

#include <gtkmm.h>
#include <vector>
#include <cstdint>

class GPU : public Gtk::DrawingArea {
public:
    GPU();
    void render();
    void draw_pixel(int x, int y, uint32_t color);
    void present();

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

private:
    std::vector<uint32_t> framebuffer;
    static constexpr int WIDTH = 320;
    static constexpr int HEIGHT = 240;
};

#endif

