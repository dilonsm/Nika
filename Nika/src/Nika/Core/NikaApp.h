#pragma once

#include "Nika/Core/Window.h"
#include "Nika/Events/Event.h"
#include "Nika/Events/ApplicationEvent.h"

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

		std::unique_ptr<WindowBase> m_Window;
		bool m_Running = true;
	};

	NikaApp* createApplication();
}

