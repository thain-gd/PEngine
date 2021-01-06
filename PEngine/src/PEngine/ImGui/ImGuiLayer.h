#pragma once

#include "PEngine/Core/Layer.h"
#include "PEngine/Events/MouseEvent.h"
#include "PEngine/Events/KeyEvent.h"
#include "PEngine/Events/ApplicationEvent.h"

namespace PEngine
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}
