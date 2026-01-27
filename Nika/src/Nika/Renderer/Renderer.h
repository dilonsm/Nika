#pragma once

#include "Nika/Managers/CameraManager.h"
#include "Nika/GameObjects/Player.h"
#include "GUI.h"

namespace Nika
{
	class Renderer
	{
	public:
		Renderer(CameraManager& cam, GUI& gui);

		void renderUpdate(Player& player);

	private:
		void drawPlayer(Player& player);
		void drawScene(Player& player);

		CameraManager& m_CamManager;
		GUI& m_Gui;
	};
}

