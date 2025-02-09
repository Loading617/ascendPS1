#include <TGUI/TGUI.hpp>
#include "tinyfiledialogs.h"

void selectRomFolder(tgui::EditBox::Ptr romFolderPath)
{
    const char* folder = tinyfd_selectFolderDialog("Select ROM Folder", "");
    if (folder)
    {
        romFolderPath->setText(folder);
    }
}
