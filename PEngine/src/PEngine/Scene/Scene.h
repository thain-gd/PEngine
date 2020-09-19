#pragma once

#include "entt.hpp"

#include "PEngine/Core/Timestep.h"

namespace PEngine
{
	class Scene
	{
	private:
		entt::registry m_Registry;

		friend class Entity;

	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(Timestep ts);
	};
}
