#include <PEngine.h>

class ExampleLayer : public PEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		PENGINE_INFO("ExampleLayer::Update");
	}

	void OnEvent(PEngine::Event& e) override
	{
		PENGINE_TRACE("{0}", e);
	}
};

class SandBox : public PEngine::Application
{
public:
	SandBox() 
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox() {}
};

PEngine::Application* PEngine::CreateApplication()
{
	return new SandBox();
}