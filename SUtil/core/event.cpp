#include "../event.h"

SUtil::Event::eManager::eManager() { SUtil_DebugPoint()
	Registered = new std::map< std::string, HookMapType>;
}

SUtil::Event::eManager::~eManager() { SUtil_DebugPoint()
	delete Registered;
}

Sutil_Export HookMapType* SUtil::Event::eManager::GetHookMap(std::string Name) { SUtil_DebugPoint()

	if (Registered->count(Name) == 0) {
		Registered->insert(std::pair<
			std::string,
			std::map<std::string, FUNC_TYPE>
		>(Name, std::map<std::string, FUNC_TYPE>()));
	}

	return &Registered->at(Name);

}

Sutil_Export void SUtil::Event::eManager::Call(std::string Name, void* InfoStruct) { SUtil_DebugPoint()

	auto HookMap = GetHookMap(Name);

	for (auto const &pair : *HookMap){
		pair.second(InfoStruct);
	}

}

Sutil_Export void SUtil::Event::eManager::Register(std::string Hook, std::string Name, FUNC_TYPE Function) { SUtil_DebugPoint()

	auto HookMap = GetHookMap(Hook);
	HookMap->insert(std::pair<std::string, FUNC_TYPE>(Name, Function));

}

Sutil_Export void SUtil::Event::eManager::Remove(std::string Hook, std::string Name) { SUtil_DebugPoint()

	HookMapType* HookMap = GetHookMap(Hook);
	HookMap->erase(Name);

}

// Define Global
Sutil_Export SUtil::Event::eManager SUtil::Event::Manager;