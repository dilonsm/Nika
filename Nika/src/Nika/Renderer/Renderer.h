#pragma once

#include "Camera.h"
#include "GUI.h"

namespace Nika
{
	class Renderer
	{
	public:
		Renderer(Camera& cam, GUI& gui);

		void renderUpdate();

	private:
		void drawScene();

		Camera& m_Camera;
		GUI& m_Gui;
	};
}

