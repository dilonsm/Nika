#pragma once

#include "Camera.h"
#include "GUI.h"

namespace Nika
{
	class Renderer
	{
	public:
		void renderUpdate(Camera& camera);

	private:
		void drawScene();

		GUI m_Gui;
	};
}

