#pragma once

#include "Nika/Window/Window.h"
#include "Nika/Events/ApplicationEvent.h"
#include "Nika/Graphics/Renderer.h"
#include "Nika/Managers/InputManager.h"
#include "Nika/GameObjects/Player.h"

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
		CameraManager	m_CamManager;
		GUI				m_Gui;
		Renderer		m_Renderer;
	};

	std::unique_ptr<NikaApp>(createApplication());
}

