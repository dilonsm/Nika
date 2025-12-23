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

		InputManager::getInstance().setEventCallback(BIND_EVENT(NikaApp::onEvent));
	}

	NikaApp::~NikaApp()
	{
	}

	void NikaApp::run()
	{
		while (m_Running)
		{
			float deltaTime = GetFrameTime(); // returns time in seconds

			InputManager::getInstance().inputUpdate(); // input update

			m_Window->winUpdate(deltaTime); // window update
		}
	}

	void NikaApp::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(NikaApp::onWindowClose));

		dispatcher.Dispatch<KeyPressedEvent>([this](KeyPressedEvent& e) {
			return this->onKeyPressed(e);
			});

		dispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& e) {
			return this->onKeyReleased(e);
			});

		dispatcher.Dispatch<MouseMovedEvent>([this](MouseMovedEvent& e) {
			return false;
			});

		NIKA_INFO("{0}", e.ToString());
	}

	bool NikaApp::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}

