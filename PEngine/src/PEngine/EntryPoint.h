#pragma once

#ifdef PENGINE_PLATFORM_WINDOWS

extern PEngine::Application* PEngine::CreateApplication();

int main(int argc, char** argv)
{
	PEngine::Log::Init();
	PENGINE_CORE_WARN("Initalized Log!");
	int a = 5;
	PENGINE_INFO("Hello! Var={0}", a);

	auto app = PEngine::CreateApplication();
	app->Run();

	delete app;
}

#endif // PENGINE_PLATFORM_WINDOWS
