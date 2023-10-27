#pragma once

#ifdef TL_PLATFORM_WINDOWS
	#ifdef TL_BUILD_DLL
		#define TULIP_API _declspec(dllexport)
	#else
		#define TULIP_API _declspec(dllimport)
	#endif // PL_BUILD_DLL
#else
	#error Tulip only support windows!
#endif // TL_PLATFORM_WINDOWS
