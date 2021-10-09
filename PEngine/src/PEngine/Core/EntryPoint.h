#pragma once

#include "PEngine/Core/Application.h"

#ifdef PENGINE_PLATFORM_WINDOWS

extern PEngine::Application* PEngine::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	PEngine::Log::Init();

	PE_PROFILE_BEGIN_SESSION("Startup", "PEngineProfile-Startup.json");
	auto app = PEngine::CreateApplication({ argc, argv });
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Startup", "PEngineProfile-Runtime.json");
	app->Run();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Startup", "PEngineProfile-Shutdown.json");
	delete app;
	PE_PROFILE_END_SESSION();
}

#endif // PENGINE_PLATFORM_WINDOWS
