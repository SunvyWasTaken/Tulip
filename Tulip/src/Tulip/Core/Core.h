#pragma once
// Ici c'est pour les DLL import et export pour que �a soit automatique.
// Du coup �a �vite de devoir tous r��crire lors de l'include et dire qu'il faut aller chercher les DLL.

#ifdef TL_PLATFORM_WINDOWS
	#ifdef TL_BUILD_DLL
		#define TULIP_API _declspec(dllexport)
	#else
		#define TULIP_API _declspec(dllimport)
	#endif // PL_BUILD_DLL
#else
	#error Tulip only support windows!
#endif // TL_PLATFORM_WINDOWS

#ifdef TL_CORE_ASSERTS
	#define TL_ASSERT(x,...) { if(!(x)) { TL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TL_CORE_ASSERT(x, ...) { if(!x)) {TL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TL_ASSERT(x, ...)
	#define TL_CORE_ASSERT(x, ...)
#endif // TL_CORE_ASSERTS


#define BIT(x) (1 << x)


#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
