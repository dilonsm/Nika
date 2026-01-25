#include "nkpch.h"
#include "NikaApp.h"

// --- macro to bind member functions to event dispatcher format ---
#define BIND_EVENT(x) std::bind(&x, this, std::placeholders::_1)

namespace Nika
{
	NikaApp::NikaApp()
		:m_CamManager(), m_Gui(), m_Renderer(m_CamManager, m_Gui)
	{
		m_Window = std::unique_ptr<WindowBase>(WindowBase::createWin());
		m_Window->setEventCallback(BIND_EVENT(NikaApp::onEvent));

		m_Player.initPlayer(m_Player.getPosition(), m_CamManager);

		InputManager::getInstance().setEventCallback(BIND_EVENT(NikaApp::onEvent));
	}

	NikaApp::~NikaApp()
	{
	}

	void NikaApp::run()
	{
		while (m_Running)
		{
			float deltaTime = GetFrameTime(); // returns time in seconds for last frame drawn

			m_Window->winUpdate(); // window update

			InputManager::getInstance().inputUpdate(); // input update

			if (m_CamManager.isPlayerMode()) // checks camera mode
			{
				m_Player.updatePlayer(deltaTime);
			}

			m_Renderer.renderUpdate(m_Player); // render update
		}

		// window close on !m_Running
		CloseWindow();
	}

	void NikaApp::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT(NikaApp::onWindowClose));

		NIKA_DEBUG("{0}", e.toString());
	}

	bool NikaApp::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}

