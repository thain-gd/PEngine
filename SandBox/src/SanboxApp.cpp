#include <PEngine.h>

class ExampleLayer : public PEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		
	}
	}

	void OnEvent(PEngine::Event& e) override
	{

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