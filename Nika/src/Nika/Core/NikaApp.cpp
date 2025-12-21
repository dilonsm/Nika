#include "nkpch.h"
#include "NikaApp.h"

#include <raylib.h>

// --- macro to bind member functions to event dispatcher format ---
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
		// initApp();

		while (m_Running)
		{
			float deltaTime = GetFrameTime(); // returns time in seconds

			m_Window->winUpdate(deltaTime);
		}
	}

	void NikaApp::initApp()
	{
	}

	void NikaApp::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(NikaApp::onWindowClose));

		NIKA_INFO("{0}", e.ToString());
	}

	bool NikaApp::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}

