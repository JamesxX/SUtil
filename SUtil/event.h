#pragma once
#include <string>
#include <map>
#include "defines.h"

typedef void(*FUNC_TYPE)(void*);

// Start SUtil namespace definition scope
namespace SUtil {

	// Start SUtil::Event namespace definition scope
	namespace Event {

		class DllExport eManager {
		public:

			eManager();
			~eManager();

			void Call(std::string Name, void* InfoStruct);
			void Register(std::string Hook, std::string Name, FUNC_TYPE Function);
			void Remove(std::string Hook, std::string Name);

		private:
			std::map< std::string, FUNC_TYPE>* GetHookMap(std::string Name);

		private:
			std::map< std::string, std::map< std::string, FUNC_TYPE>>* Registered;
		};

		template<typename T>
		DllExport void EasyCall(std::string Name, T* InfoStruct) {
			Manager.Call(Name, (void*)InfoStruct);
		}

		template<typename T>
		DllExport void EasyRegister(std::string Hook, std::string Name, void(*Function)(T*)) {
			Manager.Register(Hook, Name, reinterpret_cast<FUNC_TYPE>(Function) );
		}
		DllExport extern eManager Manager;

	}

}