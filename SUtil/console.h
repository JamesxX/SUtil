#pragma once
#include <string>
#include <mutex>
#include "defines.h"

namespace SUtil {

	namespace Console {

		class Sutil_Export Color {
		private:
			int r, g, b, i;

		public:
			Color(bool _r, bool _g, bool _b, bool _i);
			int GetOutput();
		};

		struct Sutil_Export DefaultColorsStruct {
			Color White		= Color(1, 1, 1, 1);
			Color Red		= Color(1, 0, 0, 1);
			Color Green		= Color(0, 1, 0, 1);
			Color Blue		= Color(0, 0, 1, 1);
			Color Brown		= Color(1, 1, 0, 1);
			Color Grey		= Color(0, 0, 0, 1);
			Color Black		= Color(0, 0, 0, 0);
		};

		Sutil_Export void Print(std::string Output);
		Sutil_Export void SetColor(Color Fg, Color Bg);
		Sutil_Export inline void DebugPrint(std::string Msg);

		Sutil_Export extern std::mutex Mtx;
		Sutil_Export extern DefaultColorsStruct DefaultColors;
	}

}