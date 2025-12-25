#pragma once

#include "Nika/Window/Window.h"
#include "Nika/Events/ApplicationEvent.h"
#include "Nika/Renderer/Renderer.h"
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

		bool m_Running   = true;

	private:
		std::unique_ptr<WindowBase> m_Window;

		Camera   m_Camera;
		GUI		 m_Gui;
		Renderer m_Renderer;
	};

	std::unique_ptr<NikaApp>(createApplication());
}

