#pragma once
#include <string>

#define DllExport __declspec( dllexport ) 

namespace SUtil {

	DllExport void Interrupt(std::string Msg);
	DllExport void Interrupt();

}