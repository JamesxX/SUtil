#include <string>
#include <iostream>
#include <mutex>
#include <windows.h>
#include "../console.h"
#include "../defines.h"
#include "../dbg.h"

// Color class definition
SUtil::Console::Color::Color(bool _r, bool _g, bool _b, bool _i){ SUtil_DebugPoint()
	r = _r;
	g = _g;
	b = _b;
	i = _i;
};

int SUtil::Console::Color::GetOutput() { SUtil_DebugPoint()
	return (
		i << 3 |
		r << 2 |
		g << 1 |
		b << 0
	);
}

// Functions definition
Sutil_Export void SUtil::Console::Print(std::string Output) {

	Mtx.lock();
	std::cout << Output << std::endl;
	Mtx.unlock();

}

Sutil_Export void SUtil::Console::SetColor(Color Fg, Color Bg) { SUtil_DebugPoint()

#ifdef WIN32
	int Color = (Bg.GetOutput() << 4 | Fg.GetOutput());
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdout, Color);
#endif

}

Sutil_Export inline void SUtil::Console::DebugPrint(std::string Output) {

#ifdef _DEBUG
	Print(Output);
#endif

}

Sutil_Export std::mutex SUtil::Console::Mtx;
Sutil_Export SUtil::Console::DefaultColorsStruct SUtil::Console::DefaultColors;