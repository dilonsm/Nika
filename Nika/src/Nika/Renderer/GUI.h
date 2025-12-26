#pragma once

namespace Nika
{
	class GUI
	{
	public:
		void drawReticle();

	private:
		struct ScreenSize
		{
			uint32_t Width  = 0;
			uint32_t Height = 0;
		};

		ScreenSize m_Size;
	};
}

