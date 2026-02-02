#pragma once

#include "Nika/Graphics/Transformable.h"
#include "Nika/Managers/InputManager.h"
#include "Nika/Managers/CameraManager.h"

namespace Nika
{
	class Player : public Transformable
	{
	public:
		void initPlayer(Vector3 pos, CameraManager& manager);
		void updatePlayer(float dt);

	private:

		void updateRotation();
		void updateMovement(float dt);
		void updateCamera();

	private:
		float m_Speed = 10.0f;
		CameraManager* m_CamManager = nullptr;
	};
}

