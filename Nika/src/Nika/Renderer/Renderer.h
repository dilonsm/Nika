#pragma once

#include "Nika/Managers/CameraManager.h"
#include "GUI.h"

namespace Nika
{
	class Renderer
	{
	public:
		Renderer(CameraManager& cam, GUI& gui);

		void renderUpdate();

	private:
		void drawScene();

		CameraManager& m_CamManager;
		GUI& m_Gui;
	};
}

