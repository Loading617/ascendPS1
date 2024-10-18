#include <system.hpp>

void main(int argc, char *argv[]) {
    // Initialize the system
    init_system();

    // Initialize the save data
    init_save_data();

    // Simulate the PS1 BIOS
    simulate_ps1_bios();

    // Recognize the controller connected to the system
    detect_controller();

    // Recognize the controller type
    recognize_controller_type();

    // Display the welcome message
    display_welcome_message();

    // Run the main game loop
    run_game_loop();

    // Deinitialize the system
    deinit_system();
}