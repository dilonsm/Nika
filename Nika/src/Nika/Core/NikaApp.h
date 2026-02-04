#pragma once

#include "Nika/Window/Window.h"
#include "Nika/Graphics/Renderer.h"
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

		bool m_Running = true;

	private:
		std::unique_ptr<WindowBase> m_Window;

		Player			m_Player;
		GUI				m_Gui;
		CameraManager	m_CamManager;
		Renderer		m_Renderer;
	};

	std::unique_ptr<NikaApp>(createApplication());
}

