#pragma once

#ifdef NIKA_WIN32

// ---  i don't want to include this here   ---
#include "Log.h"
#include "NikaApp.h"
// --- but Sandbox won't compile without it --- 

extern Nika::NikaApp* Nika::createApplication();

int main(int argc, char** argv)
{
	Nika::Log::init();

	NIKA_INFO("selam aleikum!");

	auto app = Nika::createApplication();
	app->run();
	delete app;
}

#endif

