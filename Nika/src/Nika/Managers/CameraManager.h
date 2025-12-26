#pragma once

namespace Nika
{
	class CameraManager
	{
	public:
		CameraManager();

		void setPosition(Vector3 pos);

		void updateWorldCamera();
		void updatePlayerCamera();

		void setWorldCamera();
		void setPlayerCamera();

		Camera3D& getWorldCamera()  { return m_WorldCamera; }
		Camera3D& getPlayerCamera() { return m_PlayerCamera; }

	private:
		Camera3D m_WorldCamera;
		Camera3D m_PlayerCamera;

		Vector3 m_PlayerPosition{ 1, 1, 1 };
	};
}

