#pragma once

#include "Nika/GameObjects/Transformable.h"
#include "Nika/Managers/CollisionManager.h"
#include "Nika/Managers/CameraManager.h"

namespace Nika
{
	class Player : public Transformable
	{
	public:
		void initPlayer(Vector3 pos, CameraManager& manager);
		void updatePlayer(float dt);

		BoundingBox getBoundingBox() const;
		BoundingBox getBoundingBoxAtPosition(Vector3 pos) const;

	private:
		void updateRotation();
		void updateMovement(float dt);
		void updateCamera();

	private:
		float m_Speed = 10.0f;

		CameraManager* m_CamManager = nullptr;
	};
}

