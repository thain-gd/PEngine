#include "pepch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platforms/OpenGL/OpenGLShader.h"

namespace PEngine
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				PE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
				return nullptr;

			case RendererAPI::API::OpenGL:
				return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}