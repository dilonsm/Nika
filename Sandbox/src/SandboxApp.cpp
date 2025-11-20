#include "src/stdafx.h"

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

Nika::NikaApp* Nika::CreateApplication()
{
	return new Sandbox();
}

