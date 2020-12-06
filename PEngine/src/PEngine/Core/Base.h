#pragma once

#include <memory>

#include "PEngine/Core/PlatformDetection.h"

#ifdef PENGINE_DEBUG
	#if defined(PENGINE_PLATFORM_WINDOWS)
		#define PE_DEBUGBREAK() __debugbreak()
	#elif defined(PENGINE_PLATFORM_LINUX)
		#include <signal.h>
		#define PE_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
		#define PE_ENABLE_ASSERTS
	#else
		#define PE_DEBUGBREAK()
#endif

#define PE_EXPAND_MACRO(x) x
#define PE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define PE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace PEngine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "PEngine/Core/Log.h"
#include "PEngine/Core/Assert.h"
