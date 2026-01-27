#pragma once

namespace Nika
{
	enum class CamMode
	{
		World,
		Player
	};

	class CameraManager
	{
	public:
		CameraManager();

		void initWorldCamera();
		void initPlayerCamera();

		void updateWorldCamera();

		void	setCameraMode(CamMode mode) { m_Mode = mode; }
		CamMode getCameraMode() const { return m_Mode; }

		Camera3D& getWorldCamera()  { return m_WorldCamera; }
		Camera3D& getPlayerCamera() { return m_PlayerCamera; }

		bool isPlayerMode() const { return m_Mode == CamMode::Player; }

	private:
		Camera3D m_WorldCamera;
		Camera3D m_PlayerCamera;

		// --- choose a camera by replacing comments ---
		//CamMode m_Mode = CamMode::World;
		CamMode m_Mode = CamMode::Player;
	};
}

