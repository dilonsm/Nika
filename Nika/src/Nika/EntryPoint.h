#pragma once

#ifdef NIKA_WIN32

#include "NikaApp.h"

extern Nika::NikaApp* Nika::createApplication();

int main(int argc, char** argv)
{
	auto app = Nika::createApplication();
	app->run();
	delete app;
}

#endif

