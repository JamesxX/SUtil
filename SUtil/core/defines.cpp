#include "../defines.h"
#include "../console.h"
#include "../dbg.h"

Sutil_Export void SUtil::Interrupt(std::string Msg) { SUtil_DebugPoint()
	Console::Print(Msg);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Sutil_Export void SUtil::Interrupt() { SUtil_DebugPoint()
	Interrupt("Press any key to continue . . . ");
}
