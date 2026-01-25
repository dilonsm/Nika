#pragma once

#include "Nika/Managers/InputManager.h"
#include "Nika/Managers/CameraManager.h"

namespace Nika
{
	class Player
	{
	public:
		void initPlayer(Vector3 pos, CameraManager& manager);
		void updatePlayer(float dt);

		Vector3 getPosition() const { return m_PlayerData.Position; }
		float   getYaw()      const { return m_PlayerData.Yaw; }
		float   getPitch()    const { return m_PlayerData.Pitch; }

	private:
		struct PlayerData
		{
			Vector3 Position = { 0.0f, 0.0f, 0.0f };
			float Speed	 = 10.0f;
			float Yaw	 =  0.0f;  // left | right
			float Pitch	 =  0.0f;  // up   | down
		};

		void updateRotation();
		void updateMovement(float dt);
		void updateCamera();

	private:
		PlayerData    m_PlayerData;
		CameraManager* m_CamManager = nullptr;
	};
}

