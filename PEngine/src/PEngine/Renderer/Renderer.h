#pragma once

namespace PEngine
{
	enum class RendererAPI
	{
		None = 0, OpenGL = 1
	};

	class Renderer
	{
	private:
		static RendererAPI s_RendererAPI;
	
	public:
		static RendererAPI GetAPI() { return s_RendererAPI; }
	};

}