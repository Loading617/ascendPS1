#include <CtrlLib/CtrlLib.h>
using namespace Upp;

struct ascendPS1 : TopWindow {
    MenuBar menu;

    void FileMenu(Bar& bar) {
        bar.Add("Load ISO / BIN / CUE", [=] { PromptOK(""); });
        bar.Add("Load from CD-ROM", [=] { PromptOK(""); });
        bar.Add("Recently Played", [=] { PromptOK(""); });
        bar.Add("Save State", [=] { PromptOK(""); });
        bar.Add("Load State", [=] { PromptOK(""); });
        bar.Add("Exit", [=] { Exit(); });
    }

    void SystemMenu(Bar& bar) {
        bar.Add("Reset", [=] { PromptOK(""); });
        bar.Add("Pause / Resume", [=] { PromptOK(""); });
        bar.Add("Soft Reset", [=] { PromptOK(""); });
        bar.Add("Hard Reset", [=] { PromptOK(""); });
        bar.Add("Power Off (for realism vibes)", [=] { PromptOK(""); });
    }

    void PreferencesMenu(Bar& bar) {
        bar.Add("BIOS", [=] { PromptOK(""); });
        bar.Add("Region", [=] { PromptOK(""); });
        bar.Add("Language", [=] { PromptOK(""); });
        bar.Add("Save Path Config", [=] { PromptOK(""); });
        bar.Add("Screenshot Folder", [=] { PromptOK(""); });
    }

    void VideoMenu(Bar& bar) {
        bar.Add("Resolution", [=] { PromptOK(""); });
        bar.Add("Aspect Ratio", [=] { PromptOK(""); });
        bar.Add("VSync On/Off", [=] { PromptOK(""); });
        bar.Add("Filters", [=] { PromptOK(""); });
        bar.Add("Renderer", [=] { PromptOK(""); });
    }

    void AudioMenu(Bar& bar) {
        bar.Add("Volume Control", [=] {  PromptOK(""); });
        bar.Add("Output Backend", [=] { PromptOK(""); });
        bar.Add("Enable Reverb / Interpolation", [=] { PromptOK(""); });
        bar.Add("Audio Latency", [=] { PromptOK(""); });
    }

    void ControlsMenu(Bar& bar) {
        bar.Add("Input Mapping", [=] { PromptOK(""); });
        bar.Add("Enable Analog Mode", [=] { PromptOK(""); });
        bar.Add("Rumble Support", [=] { PromptOK(""); });
        bar.Add("Auto Fire Settings", [=] { PromptOK(""); });
    }

    void MemoryCardMenu(Bar& bar) {
        bar.Add("Manage Cards", [=] { PromptOK(""); });
        bar.Add("Import/Export Save File", [=] { PromptOK(""); });
        bar.Add("Backup All Saves", [=] { PromptOK(""); });
    }

    void CheatsMenu(Bar& bar) {
        bar.Add("Load Cheat File (.cht/.ini)", [=] { PromptOK(""); });
        bar.Add("Enable/Disable Cheats", [=] { PromptOK(""); });
        bar.Add("Add New Cheat (Manual Entry)", [=] { PromptOK(""); });
        bar.Add("Search Memory (basic GameShark-like)", [=] { PromptOK(""); });
    }

    void ToolsMenu(Bar& bar) {
        bar.Add("Debugger", [=] { PromptOK(""); });
        bar.Add("Disassembler", [=] { PromptOK(""); });
        bar.Add("Frame Advance", [=] { PromptOK(""); });
        bar.Add("Log Viewer", [=] { PromptOK(""); });
        bar.Add("Dump VRAM / SPU / GPU", [=] { PromptOK(""); });
    }

    void HelpMenu(Bar& bar) {
        bar.Add("About ascendPS1", [=] { PromptOK(""); });
        bar.Add("Check for Updates", [=] { PromptOK(""); });
        bar.Add("View Log Files", [=] { PromptOK(""); });
        bar.Add("Documentation / FAQ", [=] { PromptOK(""); });
        bar.Add("Report Bug", [=] { PromptOK(""); });
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

    ascendPS1() {
        Title("ascendPS1").Sizeable().MinimizeBox().MaximizeBox();
        AddFrame(menu);
        menu.Set([=](Bar& bar) { MainMenu(bar); });
    }
};

GUI_APP_MAIN
{
    ascendPS1 app;
    app.Run();
}
