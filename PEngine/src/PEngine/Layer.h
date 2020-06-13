#pragma once

#include "PEngine/Core.h"
#include "PEngine/Events/Event.h"
#include "PEngine/Core/Timestep.h"

namespace PEngine
{
	class Layer
	{
	protected:
		std::string m_DebugName;

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() { return m_DebugName; }
	};
}
