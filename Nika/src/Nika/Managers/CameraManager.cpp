#include "nkpch.h"
#include "Nika/Managers/CameraManager.h"

namespace Nika
{
	CameraManager::CameraManager()
	{
		setWorldCamera();
		setPlayerCamera();
	}

	// --- set camera position at player position ---
	void CameraManager::setPosition(Vector3 pos)
	{
		m_PlayerPosition = pos;
	}

	void CameraManager::updateWorldCamera()
	{
		UpdateCamera(&m_WorldCamera, CAMERA_FREE);
	}

	void CameraManager::updatePlayerCamera()
	{
		UpdateCamera(&m_PlayerCamera, CAMERA_FIRST_PERSON);
	}

	void CameraManager::setWorldCamera()
	{
		m_WorldCamera.position		= { 1.0f, 1.0f, 1.0f };
		m_WorldCamera.target		= { 0.0f, 0.0f, 0.0f };
		m_WorldCamera.up			= { 0.0f, 1.0f, 0.0f };
		m_WorldCamera.fovy			= 69.0f;
		m_WorldCamera.projection	= CAMERA_PERSPECTIVE;
	}

	void CameraManager::setPlayerCamera()
	{
		m_PlayerCamera.position		= m_PlayerPosition;
		m_PlayerCamera.target		= { 0.0f, 1.0f, 0.0f };
		m_PlayerCamera.up			= { 0.0f, 1.0f, 0.0f };
		m_PlayerCamera.fovy			= 69.0f;
		m_PlayerCamera.projection	= CAMERA_PERSPECTIVE;
	}
}

