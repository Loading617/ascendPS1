#include <CtrlLib/CtrlLib.h>
using namespace Upp;

struct MyAppWindow : TopWindow {
    MenuBar menu;

    void FileMenu(Bar& bar) {
        bar.Add("Load ISO / BIN / CUE", [] {});
        bar.Add("Load from CD-ROM", [] {});
        bar.Add("Recently Played", [] {});
        bar.Add("Save State", [] {});
        bar.Add("Load State", [] {});
        bar.Add("Exit", [=] { Exit(); });
    }

    void SystemMenu(Bar& bar) {
        bar.Add("Reset", [] {});
        bar.Add("Pause / Resume", [] {});
        bar.Add("Soft Reset", [] {});
        bar.Add("Hard Reset", [] {});
        bar.Add("Power Off (for realism vibes)", [] {});
    }

    void PreferencesMenu(Bar& bar) {
        bar.Add("BIOS", [] {});
        bar.Add("Region", [] {});
        bar.Add("Language", [] {});
        bar.Add("Save Path Config", [] {});
        bar.Add("Screenshot Folder", [] {});
    }

    void VideoMenu(Bar& bar) {
        bar.Add("Resolution", [] {});
        bar.Add("Aspect Ratio", [] {});
        bar.Add("VSync On/Off", [] {});
        bar.Add("Filters", [] {});
        bar.Add("Renderer", [] {});
    }

    void AudioMenu(Bar& bar) {
        bar.Add("Volume Control", [] {});
        bar.Add("Output Backend", [] {});
        bar.Add("Enable Reverb / Interpolation", [] {});
        bar.Add("Audio Latency", [] {});
    }

    void ControlsMenu(Bar& bar) {
        bar.Add("Input Mapping", [] {});
        bar.Add("Enable Analog Mode", [] {});
        bar.Add("Rumble Support", [] {});
        bar.Add("Auto Fire Settings", [] {});
    }

    void MemoryCardMenu(Bar& bar) {
        bar.Add("Manage Cards", [] {});
        bar.Add("Import/Export Save File", [] {});
        bar.Add("Backup All Saves", [] {});
    }

    void CheatsMenu(Bar& bar) {
        bar.Add("Load Cheat File (.cht/.ini)", [] {});
        bar.Add("Enable/Disable Cheats", [] {});
        bar.Add("Add New Cheat (Manual Entry)", [] {});
        bar.Add("Search Memory (basic GameShark-like)", [] {});
    }

    void ToolsMenu(Bar& bar) {
        bar.Add("Debugger", [] {});
        bar.Add("Disassembler", [] {});
        bar.Add("Frame Advance", [] {});
        bar.Add("Log Viewer", [] {});
        bar.Add("Dump VRAM / SPU / GPU", [] {});
    }

    void HelpMenu(Bar& bar) {
        bar.Add("About ascendPS1", [] {});
        bar.Add("Check for Updates", [] {});
        bar.Add("View Log Files", [] {});
        bar.Add("Documentation / FAQ", [] {});
        bar.Add("Report Bug", [] {});
    }

    void MainMenu(Bar& bar) {
        bar.Sub("File", [=](Bar& bar) { FileMenu(bar); });
        bar.Sub("System", [=](Bar& bar) { SystemMenu(bar); });
        bar.Sub("Settings", [=](Bar& bar) { PreferencesMenu(bar); });
        bar.Sub("Video", [=](Bar& bar) { VideoMenu(bar); });
        bar.Sub("Audio", [=](Bar& bar) { AudioMenu(bar); });
        bar.Sub("Controls", [=](Bar& bar) { ControlsMenu(bar); });
        bar.Sub("Memory Card", [=](Bar& bar) { MemoryCardMenu(bar); });
        bar.Sub("Cheats", [=](Bar& bar) { CheatsMenu(bar); });
        bar.Sub("Tools / Developer", [=](Bar& bar) { ToolsMenu(bar); });
        bar.Sub("Help", [=](Bar& bar) { HelpMenu(bar); });
    }

    MyAppWindow() {
        Title("ascendPS1").Sizeable().MinimizeBox().MaximizeBox();
        AddFrame(menu);
        menu.Set([=](Bar& bar) { MainMenu(bar); });
    }
};

GUI_APP_MAIN
{
    MyAppWindow app;
    app.Run();
}
