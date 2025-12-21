#pragma once
#include <raylib.h>

namespace Nika
{
	class Camera
	{
	public:
		Camera();

		void camUpdate(float dt);

		Camera3D& getRaylibCamera() { return m_Camera; }

	private:
		Camera3D m_Camera;

	};
}

