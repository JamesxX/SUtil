#include <iostream>
#include "event.h"
#include "defines.h"
#include "console.h"
#include "dbg.h"

SUtil_Class(TEST_HOOK){
	SUtil_AllowTypeName(TEST_HOOK)
public:
	TEST_HOOK(std::string n) : a(n) { };
	std::string a;
};

int main() { SUtil_DebugPoint() // Entrance

	SUtil::Console::Print("Starting test...");

	SUtil::Event::EasyRegister<TEST_HOOK>("TestHook", "MyUniqueName", [](TEST_HOOK* InfoStruct) -> void{
		SUtil_DebugPoint()
		SUtil::Debug::PrintCallstack();
	});

	SUtil::Interrupt();
	SUtil::Event::EasyCall("TestHook", &TEST_HOOK("Working"));

	TEST_HOOK::for_each_instance([](TEST_HOOK* instance) {

		SUtil::Console::Print("awh yeh!");

	});

	SUtil::Interrupt();

	return 0;

}