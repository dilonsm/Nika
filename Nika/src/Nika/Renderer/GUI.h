#pragma once

#include <raylib.h>

namespace Nika
{
	class GUI
	{
	public:
		void drawReticle();

	private:
		struct ScreenSize
		{
			uint32_t Width;
			uint32_t Height;
		};

		ScreenSize m_Size;
	};
}

