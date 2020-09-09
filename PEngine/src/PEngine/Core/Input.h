#pragma once

#include <glm/glm.hpp>

#include "PEngine/Core/KeyCodes.h"
#include "PEngine/Core/MouseCodes.h"

namespace PEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode keycode);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}