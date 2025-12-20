#pragma once

#include "Nika/Window/Window.h"
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
		void initApp();

		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<WindowBase> m_Window;
		bool m_Running = true;
	};

	NikaApp* createApplication();
}

