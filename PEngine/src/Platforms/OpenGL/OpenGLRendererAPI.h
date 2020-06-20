#pragma once

#include "PEngine/Renderer/RendererAPI.h"

namespace PEngine
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		void Init() override;
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;

		void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}