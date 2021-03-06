#pragma once

#include "PEngine.h"

class Sandbox2D : public PEngine::Layer
{
public:
	Sandbox2D();
	~Sandbox2D() = default;

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(PEngine::Timestep ts) override;
	void OnImGuiRender() override;
	void OnEvent(PEngine::Event& e) override;

private:
	PEngine::OrthographicCameraController m_CameraController;

	// TEMP
	PEngine::Ref<PEngine::VertexArray> m_SquareVA;
	PEngine::Ref<PEngine::Shader> m_FlatColorShader;

	PEngine::Ref<PEngine::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};