#include "Nika.h"

class Sandbox : public Nika::NikaApp
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

private:

};

Nika::NikaApp* Nika::createApplication()
{
	return new Sandbox();
}

