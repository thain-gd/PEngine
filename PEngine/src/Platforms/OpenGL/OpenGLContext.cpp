#include "pepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace PEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PE_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		PE_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PE_CORE_ASSERT(status, "Failed to initialized Glad!");

		PE_CORE_INFO("OpenGL Info:");
		PE_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
		PE_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		PE_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));

		PE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		PE_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}