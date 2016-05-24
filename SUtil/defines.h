#pragma once
#pragma warning( disable : 4251 ) //Error is not relevant.

#include <unordered_set>
#include <string>
#include <iostream>
#include <limits>

#ifdef __SUtil__Definions
#define Sutil_Export __declspec( dllexport ) 
#else
#define Sutil_Export __declspec( dllimport ) 
#endif


#define SUtil_Class_Extend( x, y ) class Sutil_Export x : public SUtil::baseclass<y>
#define SUtil_Class( x ) SUtil_Class_Extend( x, x )
#define SUtil_AllowTypeName( x ) public: std::string GetTypeName() { return #x ; }

namespace SUtil {

	Sutil_Export void Interrupt(std::string Msg);
	Sutil_Export void Interrupt();

	template <typename T> class Sutil_Export baseclass {
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

		std::string GetTypeName() { return "#UNDEFINED#"; }

	private:
		static std::unordered_set<T*> objects;

	};

	template < typename T > Sutil_Export std::unordered_set<T*> baseclass<T>::objects;

}
