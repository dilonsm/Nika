#include "nkpch.h"
#include "NikaApp.h"

#include "Nika/Core/Log.h"
#include "Nika/Events/ApplicationEvent.h"

namespace Nika
{
	NikaApp::NikaApp()
	{
		m_Window = std::unique_ptr<WindowBase>(WindowBase::createWin());
	}

	NikaApp::~NikaApp()
	{
	}

	void NikaApp::run()
	{
		while (m_Running)
		{
			glClearColor(2, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}
}

