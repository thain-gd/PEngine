#pragma once

#include "PEngine.h"
#include "Panels/SceneHierarchyPanel.h"

#include "PEngine/Renderer/EditorCamera.h"

namespace PEngine
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		~EditorLayer() = default;

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Event& e) override;

	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool CanMousePick() const;

		void DrawMenuBar();
		void DrawRendererStats();
		void DrawViewport();
		void DrawGizmos();

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
		void SaveScene();

	private:
		OrthographicCameraController m_CameraController;

		// TEMP
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;

		Entity m_HoveredEntity;

		bool m_PrimaryCamera = true;

		Ref<Texture2D> m_CheckerboardTexture;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 m_ViewportBounds[2];

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		int m_GizmoType = -1;

		std::string m_CurrentFilepath;

		EditorCamera m_EditorCamera;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
	};
}
