#pragma once

#include "PEngine/Renderer/Camera.h"
#include "PEngine/Core/Timestep.h"

#include "PEngine/Events/ApplicationEvent.h"
#include "PEngine/Events/MouseEvent.h"

namespace PEngine
{
	class OrthographicCameraController
	{
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;
		bool m_Rotation;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f;
		float m_CameraRotationSpeed = 45.0f;

		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);

	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }
	};
}
