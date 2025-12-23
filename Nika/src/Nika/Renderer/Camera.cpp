#include "nkpch.h"
#include "Camera.h"

namespace Nika
{
	Camera::Camera()
	{
		m_Camera.position	= { 4.0f, 2.0f, 4.0f };
		m_Camera.target		= { 0.0f, 0.5f, 0.0f };
		m_Camera.up			= { 0.0f, 1.0f, 0.0f };
		m_Camera.fovy		=  69.0f;
		m_Camera.projection = CAMERA_PERSPECTIVE;
	}

	void Camera::camUpdate()
	{
		UpdateCamera(&m_Camera, CAMERA_FREE);
	}
}

