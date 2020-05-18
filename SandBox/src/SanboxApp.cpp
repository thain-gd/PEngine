#include <PEngine.h>

class SandBox : public PEngine::Application
{
public:
	SandBox() {}

	~SandBox() {}
};

PEngine::Application* PEngine::CreateApplication()
{
	return new SandBox();
}