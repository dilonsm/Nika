#pragma once

#include "Nika/Managers/CameraManager.h"
#include "Nika/GameObjects/Player.h"
#include "GUI.h"

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

		Player& m_Player;
		CameraManager& m_CamManager;
		GUI& m_Gui;
	};
}

