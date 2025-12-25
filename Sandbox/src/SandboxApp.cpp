#include "nkpch.h"
#include "Nika.h"

namespace Nika
{
	class Sandbox : public NikaApp
	{
	public:
		Sandbox()
		{
		}

		~Sandbox()
		{
		}
	};

	std::unique_ptr<NikaApp>(createApplication())
	{
		return std::make_unique<Sandbox>();
	}
}

