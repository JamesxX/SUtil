#pragma once
#pragma warning( disable : 4251 ) //Error is not relevant.

#include <string>
#include <unordered_set>

#define DllExport __declspec( dllexport ) 
#define SUtil_Class( x ) class DllExport x : SUtil::baseclass<x>

namespace SUtil {

	DllExport void Interrupt(std::string Msg);
	DllExport void Interrupt();

	template <typename T> class DllExport baseclass {
	public:
		baseclass() {
			objects.insert(static_cast<T*>(this));
		}

		baseclass(const baseclass&) {
			baseclass();
		}

		baseclass(baseclass&&) {
			baseclass();
		}

		~baseclass() {
			objects.erase(static_cast<T*>(this));
		}


	public:
		template<typename function> static void for_each_instance(function fn) {
			for (T* p : objects) {
				fn(p);
			}
		}

	private:
		static std::unordered_set<T*> objects;

	};

	template < typename T > DllExport std::unordered_set<T*> baseclass<T>::objects;

}
