#include "nkpch.h"
#include "GUI.h"

namespace Nika
{
	void GUI::drawReticle()
	{
		m_Size.Width  = GetScreenWidth();
		m_Size.Height = GetScreenHeight();

		Vector2 screenCenter = { m_Size.Width / 2, m_Size.Height / 2 };

		float radius = 4.2f;

		DrawCircleV(screenCenter, radius, RED);
	}
}

