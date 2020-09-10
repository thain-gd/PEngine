#include <PEngine.h>
#include <PEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace PEngine
{
	class PEngineEditor : public PEngine::Application
	{
	public:
		PEngineEditor()
			: Application("PEngine Editor")
		{
			PushLayer(new EditorLayer());
		}

		~PEngineEditor() {}
	};

	PEngine::Application* PEngine::CreateApplication()
	{
		return new PEngineEditor();
	}
}

