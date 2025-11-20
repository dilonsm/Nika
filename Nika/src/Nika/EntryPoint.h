#pragma once

#ifdef NIKA_WIN32

#include "NikaApp.h"

extern Nika::NikaApp* Nika::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Nika::CreateApplication();
	app->Run();
	delete app;
}

#endif

