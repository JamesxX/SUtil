#include <string>
#include <iostream>
#include <limits>
#include "../defines.h"
#include "../console.h"

DllExport void SUtil::Interrupt(std::string Msg) {
	Console::Print(Msg);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

DllExport void SUtil::Interrupt() {
	SUtil::Interrupt("Press any key to continue . . . ");
}