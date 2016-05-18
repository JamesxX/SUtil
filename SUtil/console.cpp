#include <string>
#include <iostream>
#include "console.h"
#include "defines.h"

DllExport void SUtil::Console::Print(std::string Output) {

	std::cout << Output << std::endl;

}