#pragma once

#include "Nika/Managers/InputManager.h"
#include "Nika/Managers/CameraManager.h"

namespace Nika
{
	class Player
	{
	public:
		void initPlayer(Vector3 pos);

		void updatePlayer(float deltaTime);

	private:
		CameraManager m_CamManager;
	};
}

