#pragma once
#include <string>
#include <map>
#include "defines.h"
#include "dbg.h"

typedef void(*FUNC_TYPE)(void*);
typedef std::map< std::string, FUNC_TYPE> HookMapType;

// Start SUtil namespace definition scope
namespace SUtil {

	// Start SUtil::Event namespace definition scope
	namespace Event {

		class Sutil_Export eManager {
		public:

			eManager();
			~eManager();

			void Call(std::string Name, void* InfoStruct);
			void Register(std::string Hook, std::string Name, FUNC_TYPE Function);
			void Remove(std::string Hook, std::string Name);

		private:
			HookMapType* GetHookMap(std::string Name);

		private:
			std::map< std::string, HookMapType>* Registered;
		};

		template<typename T>
		Sutil_Export void EasyCall(std::string Name, T* InfoStruct) {
			Manager.Call(Name, (void*)InfoStruct);
		}

		template<typename T>
		Sutil_Export void EasyRegister(std::string Hook, std::string Name, void(*Function)(T*)) {
			Manager.Register(Hook, Name, reinterpret_cast<FUNC_TYPE>(Function) );
		}
		Sutil_Export extern eManager Manager;

	}

}