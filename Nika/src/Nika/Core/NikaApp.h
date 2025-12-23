#pragma once

#include "Nika/Window/Window.h"
#include "Nika/Events/ApplicationEvent.h"

#include "Nika/Managers/InputManager.h"

namespace Nika
{
	class NIKA_API NikaApp
	{
	public:
		NikaApp();
		virtual ~NikaApp();

		void run();

		void onEvent(Event& e);

	private:
		bool onWindowClose(WindowCloseEvent& e);
		bool onKeyPressed(KeyPressedEvent& e) { return false; }
		bool onKeyReleased(KeyReleasedEvent& e) { return false; }

		std::unique_ptr<WindowBase> m_Window;
		bool m_Running = true;
	};

	NikaApp* createApplication();
}

