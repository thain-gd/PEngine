#pragma once

#include "PEngine/Core/Base.h"
#include "PEngine/Core/Log.h"
#include "PEngine/Scene/Scene.h"
#include "PEngine/Scene/Entity.h"

namespace PEngine
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);

	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}