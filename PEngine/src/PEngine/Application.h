#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "PEngine/Events/ApplicationEvent.h"
#include "Window.h"

namespace PEngine {

	class PENGINE_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		bool OnWindowClosed(WindowCloseEvent& e);

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	};

	//To be define in client
	Application* CreateApplication();
}


