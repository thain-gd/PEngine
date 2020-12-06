#pragma once

#include <memory>

#include "PEngine/Core/PlatformDetection.h"

#ifdef PENGINE_DEBUG
	#define PENGINE_ENABLE_ASSERTS
#endif

#ifdef PENGINE_ENABLE_ASSERTS
	#define PE_ASSERT(x, ...) { if (!(x)) { PE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PE_CORE_ASSERT(x, ...) { if (!(x)) { PE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PE_ASSERT(x, ...)
	#define PE_CORE_ASSERT(x, ...)
#endif // PENGINE_ENABLED_ASSERTS


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
