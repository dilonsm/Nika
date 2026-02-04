#pragma once

#include "Nika/Managers/CameraManager.h"
#include "Nika/GameObjects/Player.h"
#include "Nika/Graphics/GUI.h"

namespace Nika
{
	class Renderer
	{
	public:
		Renderer(CameraManager& cam, GUI& gui, Player& player);

		void renderUpdate(float dt);

	private:
		void drawPlayer();
		void drawScene();

		CameraManager& m_CamManager;
		GUI&	m_Gui;
		Player& m_Player;
	};
}

