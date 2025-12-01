#include "nkpch.h"
#include "NikaApp.h"

#define BIND_EVENT(x) std::bind(&x, this, std::placeholders::_1)

namespace Nika
{
	NikaApp::NikaApp()
	{
		m_Window = std::unique_ptr<WindowBase>(WindowBase::createWin());
		m_Window->setEventCallback(BIND_EVENT(NikaApp::onEvent));
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

	void NikaApp::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(NikaApp::onWindowClose));

		NIKA_TRACE("{0}", e.ToString());
	}

	bool NikaApp::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}

