#pragma once
#include <raylib.h>

namespace Nika
{
	class Camera
	{
	public:
		Camera();

		void camUpdate();

		Camera3D& getRaylibCamera() { return m_Camera; }

	private:
		Camera3D m_Camera;

	};
}

