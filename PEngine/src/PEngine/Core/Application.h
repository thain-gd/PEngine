#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "PEngine/Events/Event.h"
#include "PEngine/Events/ApplicationEvent.h"

#include "PEngine/Core/Timestep.h"

#include "PEngine/ImGui/ImGuiLayer.h"

namespace PEngine {

	class Application
	{
	private:
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	public:
		static Application& Instance() { return *s_Instance; }

		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		Window& GetWindow() { return *m_Window; }
	};

	//To be define in client
	Application* CreateApplication();
}


