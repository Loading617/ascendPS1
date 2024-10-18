#include <window.hpp>

int main() {
    using namespace window;

    // Create a window with the specified title and dimensions
    Window window("ThunPS1 Emu", 1280, 720);

    // Set the window's background color
    window.set_background_color(Color::Black);

    // Start the main loop
    while (window.is_open()) {
        // Process events (e.g., input, window resizing)
        window.poll_events();

        // Clear the window
        window.clear();

        // Draw graphics (e.g., sprites, text)
        // ...

        // Display the window
        window.display();
    }

    return 0;
}