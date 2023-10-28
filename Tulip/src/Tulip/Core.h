#pragma once
// Ici c'est pour les DLL import et export pour que ça soit automatique.
// Du coup ça évite de devoir tous réécrire lors de l'include et dire qu'il faut aller chercher les DLL.

#ifdef TL_PLATFORM_WINDOWS
	#ifdef TL_BUILD_DLL
		#define TULIP_API _declspec(dllexport)
	#else
		#define TULIP_API _declspec(dllimport)
	#endif // PL_BUILD_DLL
#else
	#error Tulip only support windows!
#endif // TL_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
