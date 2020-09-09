#include "pepch.h"
#include "PEngine/Core/Input.h"

#include "PEngine/Core/Application.h"
#include <GLFW/glfw3.h>

namespace PEngine
{
	bool Input::IsKeyPressed(const KeyCode keycode)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(const MouseCode button)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePosition()
	{
		auto* window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}
}