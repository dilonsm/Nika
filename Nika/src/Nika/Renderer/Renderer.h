#pragma once

#include "Camera.h"

namespace Nika
{
	class Renderer
	{
	public:
		static void renderUpdate(Camera& camera);

	private:
		static void beginScene(Camera& camera);
		static void endScene();
		static void drawScene();

	};
}

