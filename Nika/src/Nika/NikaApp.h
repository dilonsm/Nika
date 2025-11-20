#pragma once

#include "Core.h"

namespace Nika
{
	class NIKA_API NikaApp
	{
	public:
		NikaApp();
		virtual ~NikaApp();

		void Run();

	private:

	};

	NikaApp* CreateApplication();
}

