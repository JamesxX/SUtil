#pragma once

#include <vector>
#include "defines.h"
#include "console.h"

#ifdef _DEBUG
#define SUtil_DebugPoint() SUtil::Debug::SourcePointMarker sourcepointmarker(__FILE__, __LINE__, __FUNCTION__);
#else
#define SUtil_DebugPoint()
#endif

namespace SUtil {

	namespace Debug {

		class SourcePoint {
		public:
			const char *filename;
			const char *function;
			int line;
		public:
			SourcePoint(const char *filename, int line, const char *function);
			std::string PrintLine();
		};

		class SourcePointMarker
		{
		public:
			SourcePointMarker(const char *filename, int line, const char *function);
			~SourcePointMarker();
		};

		Sutil_Export extern std::vector<SourcePoint> Callstack;
		Sutil_Export void PrintCallstack();

	}

}