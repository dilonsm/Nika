#include "nkpch.h"

#include "Events/ApplicationEvent.h"
#include "NikaApp.h"
#include "Log.h"

namespace Nika
{
	NikaApp::NikaApp()
	{
	}

	NikaApp::~NikaApp()
	{
	}

	void NikaApp::run()
	{
		WindowResizeEvent event(1280, 720);
		if (event.IsInCategory(EventCategoryApplication))
		{
			NIKA_TRACE("{}", event);
		}
	}
}

