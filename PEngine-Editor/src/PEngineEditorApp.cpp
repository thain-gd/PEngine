#include <PEngine.h>
#include <PEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace PEngine
{
	class PEngineEditor : public Application
	{
	public:
		PEngineEditor(ApplicationCommandLineArgs args)
			: Application("PEngine Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~PEngineEditor() {}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new PEngineEditor(args);
	}
}

