#include "gpu.hpp"

GPU::GPU() : framebuffer(WIDTH * HEIGHT, 0x000000) {
    set_size_request(WIDTH, HEIGHT);
}

void GPU::draw_pixel(int x, int y, uint32_t color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        framebuffer[y * WIDTH + x] = color;
    }
}

void GPU::render() {
    for (int y = 50; y < 100; y++) {
        for (int x = 100; x < 220; x++) {
            draw_pixel(x, y, 0xFF0000FF);
        }
    }
    queue_draw();
}

bool GPU::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    auto surface = Cairo::ImageSurface::create(Cairo::FORMAT_RGB24, WIDTH, HEIGHT);
    uint32_t* data = reinterpret_cast<uint32_t*>(surface->get_data());

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        data[i] = framebuffer[i];
    }

    surface->mark_dirty();
    cr->set_source(surface, 0, 0);
    cr->paint();
    
    return true;
}

void GPU::present() {
    render();
}
