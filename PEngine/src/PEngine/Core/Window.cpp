#include "pepch.h"
#include "PEngine/Core/Window.h"

#ifdef PENGINE_PLATFORM_WINDOWS
#include "Platforms/Windows/WindowsWindow.h"
#endif

namespace PEngine
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef PENGINE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		PE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}