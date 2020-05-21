#pragma once

#include "Core.h"
#include "Window.h"

namespace PEngine {

	class PENGINE_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be define in client
	Application* CreateApplication();
}


