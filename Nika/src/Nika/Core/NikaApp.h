#pragma once

#include "Nika/Core/Base.h"
#include "Nika/Core/Window.h"
#include "Nika/Events/Event.h"

namespace Nika
{
	class NIKA_API NikaApp
	{
	public:
		NikaApp();
		virtual ~NikaApp();

		void run();

	private:
		std::unique_ptr<WindowBase> m_Window;
		bool m_Running = true;
	};

	NikaApp* createApplication();
}

