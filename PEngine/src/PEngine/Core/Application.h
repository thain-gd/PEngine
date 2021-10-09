#pragma once

#include "PEngine/Core/Base.h"

#include "PEngine/Core/Window.h"
#include "PEngine/Core/LayerStack.h"
#include "PEngine/Events/Event.h"
#include "PEngine/Events/ApplicationEvent.h"

#include "PEngine/Core/Timestep.h"

#include "PEngine/ImGui/ImGuiLayer.h"

namespace PEngine {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			PE_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	
	class Application
	{
	public:
		static Application& Instance() { return *s_Instance; }

		Application(const std::string& name = "PEngine App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		Window& GetWindow() const { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() const { return m_ImGuiLayer; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }

	private:
		static Application* s_Instance;

		ApplicationCommandLineArgs m_CommandLineArgs;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	};

	//To be define in client
	Application* CreateApplication(ApplicationCommandLineArgs args);
}


