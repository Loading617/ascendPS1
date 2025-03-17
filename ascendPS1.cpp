#include <iostream>
using namespace std;

class ascendPS1 {
public:
    void loadGame(const string& gamePath) {
        cout << "Loading game: " << gamePath << endl;
    }

    void emulate() {
        cout << "Starting PS1 emulation..." << endl;
    }

    void handleInput() {
        cout << "Handling user input..." << endl;
    }
};

int main() {
    ascendPS1 emulator;
    emulator.loadGame("path/to/your/game.iso");
    emulator.emulate();
    emulator.handleInput();
    return 0;
}
