#ifndef _ascendPS1_gui_h_
#define _ascendPS1_gui_h_

#include "emulator.h"

using namespace Upp;

class ascendPS1 : TopWindow{
public: ascendPS1();

private:
    Emulator emulator;
    Button loadBiosBtn, runBtn;
    Label statusLbl;
    
    void LoadBios();
    void RunEmulator; 
};

#endif
