#pragma once

#ifdef PENGINE_PLATFORM_WINDOWS
	#ifdef PENGINE_BUILD_DLL
		#define PENGINE_API __declspec(dllexport)
	#else
		#define PENGINE_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif // PENGINE_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
