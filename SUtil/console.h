#pragma once
#include <string>
#include <mutex>
#include "defines.h"

namespace SUtil {

	namespace Console {

		class DllExport Color {
		private:
			int r, g, b, i;

		public:
			Color(bool _r, bool _g, bool _b, bool _i);
			int GetOutput();
		};

		struct DllExport DefaultColorsStruct {
			Color White		= Color(1, 1, 1, 1);
			Color Red		= Color(1, 0, 0, 1);
			Color Green		= Color(0, 1, 0, 1);
			Color Blue		= Color(0, 0, 1, 1);
			Color Brown		= Color(1, 1, 0, 1);
			Color Grey		= Color(0, 0, 0, 1);
			Color Black		= Color(0, 0, 0, 0);
		};

		DllExport void Print(std::string Output);
		DllExport void SetColor(Color Fg, Color Bg);

		DllExport extern std::mutex Mtx;
		DllExport extern DefaultColorsStruct DefaultColors;
	}

}