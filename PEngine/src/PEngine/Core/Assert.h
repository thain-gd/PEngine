#pragma once

#include "PEngine/Core/Base.h"
#include "PEngine/Core/Log.h"

#ifdef PE_ENABLE_ASSERTS

	namespace PEngine::Assert
	{
		// Returns the simple file name rather than full path
		constexpr const char* CurrentFileName(const char* path) {
			const char* file = path;
			while (*path)
			{
				if (*path == '/' || *path == '\\')
					file = ++path;
				else
					path++;
			}
			return file;
		}
	}

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define PE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { PE##type##ERROR(msg, __VA_ARGS__); PE_DEBUGBREAK(); } }
	#define PE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) PE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define PE_INTERNAL_ASSERT_NO_MSG(type, check) PE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", PE_STRINGIFY_MACRO(check), ::PEngine::Assert::CurrentFileName(__FILE__), __LINE__)

	#define PE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define PE_INTERNAL_ASSERT_GET_MACRO(...) PE_EXPAND_MACRO( PE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, PE_INTERNAL_ASSERT_WITH_MSG, PE_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define PE_ASSERT(...) PE_EXPAND_MACRO( PE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define PE_CORE_ASSERT(...) PE_EXPAND_MACRO( PE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define PE_ASSERT(...)
	#define PE_CORE_ASSERT(...)
#endif
