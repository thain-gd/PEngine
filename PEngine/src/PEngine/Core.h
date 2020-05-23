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

#ifdef PENGINE_ENABLE_ASSERTS
	#define PENGINE_ASSERT(x, ...) { if (!x)) { PENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PENGINE_CORE_ASSERT(x, ...) { if (!x)) { PENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PENGINE_ASSERT(x, ...)
	#define PENGINE_CORE_ASSERT(x, ...)
#endif // PENGINE_ENABLED_ASSERTS


#define BIT(x) (1 << x)

#define PENGINE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)