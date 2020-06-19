#include "pepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platforms/OpenGL/OpenGLVertexArray.h"

namespace PEngine
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			PE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
			return nullptr;

		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}