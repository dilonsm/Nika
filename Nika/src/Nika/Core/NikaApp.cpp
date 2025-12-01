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
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(2, 0, 0, 1);

			// my first triangle :D
			glBegin(GL_TRIANGLES);
			glVertex2f(-.5f, -.5f);
			glVertex2f( .0f,  .5f);
			glVertex2f( .5f, -.5f);
			glEnd();

			m_Window->onUpdate();
		}
	}
}

