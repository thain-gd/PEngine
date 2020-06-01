#pragma once

#include "PEngine/Layer.h"
#include "PEngine/Events/MouseEvent.h"
#include "PEngine/Events/KeyEvent.h"
#include "PEngine/Events/ApplicationEvent.h"

namespace PEngine
{
	class ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0;

	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;

		void Begin();
		void End();
	};
}