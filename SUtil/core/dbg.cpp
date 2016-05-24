#include "../dbg.h"
#include <sstream>

SUtil::Debug::SourcePoint::SourcePoint(const char *filename, int line, const char *function){
	this->filename = filename;
	this->line = line;
	this->function = function;
}

std::string SUtil::Debug::SourcePoint::PrintLine() {
	return std::string(function) + " @ " + filename + ":" + static_cast<std::ostringstream*>(&(std::ostringstream() << line))->str();;
}

Sutil_Export std::vector<SUtil::Debug::SourcePoint> SUtil::Debug::Callstack;

SUtil::Debug::SourcePointMarker::SourcePointMarker(const char *filename, int line, const char *function){
	Callstack.push_back(SourcePoint(filename, line, function));
}

SUtil::Debug::SourcePointMarker::~SourcePointMarker(){
	Callstack.pop_back();
}

Sutil_Export void SUtil::Debug::PrintCallstack() {

#ifdef _DEBUG
	SUtil::Console::Print("--- Callstack ---");

	for (auto element : Callstack) {
		SUtil::Console::Print( element.PrintLine() );
	}

	SUtil::Console::Print("--- End of Callstack ---");
	SUtil::Console::Print("");
#endif

}