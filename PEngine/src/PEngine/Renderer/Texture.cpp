#include "pepch.h"
#include "Texture.h"
#include "Renderer.h"
#include "Platforms/OpenGL/OpenGLTexture.h"

namespace PEngine
{
	Ref<Texture2D> Texture2D::Create(const std::string & path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				PE_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");
				return nullptr;

			case RendererAPI::API::OpenGL:
				return std::make_shared<OpenGLTexture2D>(path);
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}