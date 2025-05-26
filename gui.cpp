#include "gui.h"

ascendPS1::ascendPS1(){
   Title("ascendPS1").Sizeable().Zoomable();
   
   Add(loadAdd(loadBiosBtn.LeftPosZ(10, 100).TopPosZ(10, 24));
    loadBiosBtn.SetLabel("Load BIOS");
    loadBiosBtn << [=] { LoadBios(); };

    Add(runBtn.LeftPosZ(120, 100).TopPosZ(10, 24));
    runBtn.SetLabel("Run");
    runBtn << [=] { RunEmulator(); };

    Add(statusLbl.LeftPosZ(10, 200).TopPosZ(40, 20));
    statusLbl.SetText("Ready");
}
void ascendPS1::LoadBios() {
	
FileSel fs;
    if (fs.ExecuteOpen("Select PS1 BIOS")) {
        if (emulator.LoadBIOS(fs.Get())) {
            statusLbl.SetText("BIOS loaded.");
        } else {
            statusLbl.SetText("BIOS load failed.");
        }
    }
}
void ascendPS1::RunEmulator() {
	statusLbl.SetText("Running...");
	emulator.Start; 
}