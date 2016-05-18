#include <iostream>
#include "event.h"
#include "defines.h"
#include "console.h"

struct TEST_HOOK {
	TEST_HOOK(std::string n) : a(n) { };
	std::string a;
};

int main() {

	SUtil::Console::Print("Starting test...");

	SUtil::Event::EasyRegister<TEST_HOOK>("TestHook", "MyUniqueName", [](TEST_HOOK* InfoStruct) -> void{
		SUtil::Console::Print(InfoStruct->a);
	});

	SUtil::Interrupt();

	for (int a = 0; a < 255; a++) {
		SUtil::Event::EasyCall<TEST_HOOK>("TestHook", &TEST_HOOK("Working"));
	}

	SUtil::Interrupt();

	return 0;

}