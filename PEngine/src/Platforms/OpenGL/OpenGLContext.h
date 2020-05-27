#pragma once

#include "PEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace PEngine
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow* m_WindowHandle;

	public:
		OpenGLContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffers() override;
	};
}