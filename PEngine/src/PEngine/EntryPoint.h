#pragma once

#ifdef PENGINE_PLATFORM_WINDOWS

extern PEngine::Application* PEngine::CreateApplication();

int main(int argc, char** argv)
{
	PEngine::Log::Init();
	PE_CORE_WARN("Initalized Log!");

	auto app = PEngine::CreateApplication();
	app->Run();

	delete app;
}

#endif // PENGINE_PLATFORM_WINDOWS
