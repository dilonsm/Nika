#pragma once

#include "Core.h"

namespace Nika
{
	class NIKA_API NikaApp
	{
	public:
		NikaApp();
		virtual ~NikaApp();

		void run();

	private:

	};

	NikaApp* createApplication();
}

