#include <string>
#include <iostream>
#include <mutex>
#include <windows.h>
#include "../console.h"
#include "../defines.h"

// Color class definition
SUtil::Console::Color::Color(bool _r, bool _g, bool _b, bool _i){
	r = _r;
	g = _g;
	b = _b;
	i = _i;
};

int SUtil::Console::Color::GetOutput() {
	return (
		i << 3 |
		r << 2 |
		g << 1 |
		b << 0
	);
}

// Functions definition
DllExport void SUtil::Console::Print(std::string Output) {

	Mtx.lock();
	std::cout << Output << std::endl;
	Mtx.unlock();

}

DllExport void SUtil::Console::SetColor(Color Fg, Color Bg) {

#ifdef _WIN32
	int Color = (Bg.GetOutput() << 4 | Fg.GetOutput());
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdout, Color);
#endif

}

DllExport std::mutex SUtil::Console::Mtx;
DllExport SUtil::Console::DefaultColorsStruct SUtil::Console::DefaultColors;