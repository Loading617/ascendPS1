#include "run PS1 bios

int main(int argc, char *argv[]) {
    // Load the PS1 BIOS from the disc image
    load_ps1_bios();

    // Initialize the BIOS
    initialize_bios();

    // Run the BIOS
    run_bios();

    // View Memory Card through the BIOS
    view_memory_card_through_bios();

    // View CD Player through the BIOS
    view_cd_player_through_bios();
    

    return 0;
}