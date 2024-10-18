#include <graphics.hpp>

int main() {
    // Initialize the graphics system
    initwindow(800, 600, "ThunPS1 Emulator");

    // Set the background color
    setbkcolor(LIGHTGRAY);

    // Draw a rectangle
    rectangle(100, 100, 600, 500);

    // Update the screen
    updatewindow();

    // Wait for a key press
    getch();

    // Close the graphics window
    closegraph();

    return 0;
}