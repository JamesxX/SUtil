#include <map>
#include "../event.h"
#include "../defines.h"


SUtil::Event::eManager::eManager() {
	Registered = new std::map< std::string, std::map< std::string, FUNC_TYPE>>;
}

SUtil::Event::eManager::~eManager() {
	delete Registered;
}

DllExport std::map< std::string, FUNC_TYPE>* SUtil::Event::eManager::GetHookMap(std::string Name) {

	if (Registered->count(Name) == 0) {
		Registered->insert(std::pair<
			std::string,
			std::map<std::string, FUNC_TYPE>
		>(Name, std::map<std::string, FUNC_TYPE>()));
	}

	return &Registered->at(Name);

}

DllExport void SUtil::Event::eManager::Call(std::string Name, void* InfoStruct) {

	auto HookMap = GetHookMap(Name);

	for (auto const &pair : *HookMap){
		pair.second(InfoStruct);
	}

}

DllExport void SUtil::Event::eManager::Register(std::string Hook, std::string Name, FUNC_TYPE Function) {

	auto HookMap = GetHookMap(Hook);
	HookMap->insert(std::pair<std::string, FUNC_TYPE>(Name, Function));

}

DllExport void SUtil::Event::eManager::Remove(std::string Hook, std::string Name) {

	auto HookMap = GetHookMap(Hook);
	HookMap->erase(Name);

}

// Define Global
DllExport SUtil::Event::eManager SUtil::Event::Manager;