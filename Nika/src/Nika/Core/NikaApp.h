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
		bool onWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<WindowBase> m_Window;

		bool m_Running = true;
		bool m_Minimized = true;
	};

	std::unique_ptr<NikaApp>(createApplication());
}

