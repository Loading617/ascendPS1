#include "emulator.h"
#include "gui.h"
ascendPS1::ascendPS1()
{
	CtrlLayout(*this, "ascendPS1");
}

GUI_APP_MAIN
{
	ascendPS1().Run();
}
