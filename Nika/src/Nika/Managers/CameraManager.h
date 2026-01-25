#pragma once

namespace Nika
{
	class CameraManager
	{
	public:
		CameraManager();

		void updateWorldCamera();
		void updatePlayerCamera();

		void setWorldCamera();
		void setPlayerCamera();

		Camera3D& getWorldCamera()  { return m_WorldCamera; }
		Camera3D& getPlayerCamera() { return m_PlayerCamera; }

	private:
		Camera3D m_WorldCamera;
		Camera3D m_PlayerCamera;
	};
}

