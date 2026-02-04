#include "nkpch.h"

#include "Nika/Core/NikaApp.h"
#include "Nika/Core/EntryPoint.h"

namespace Nika
{
	class Sandbox : public NikaApp
	{
	public:
		 Sandbox() {}
		~Sandbox() {}
	};

	std::unique_ptr<NikaApp>(createApplication())
	{
		return std::make_unique<Sandbox>();
	}
}

