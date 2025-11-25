#pragma once

#ifdef NIKA_WIN32

extern Nika::NikaApp* Nika::createApplication();

// ==================================================
// ==== Entry Point ================
int main(int argc, char** argv)
{
	Nika::Log::init();

	NIKA_INFO("selam aleikum!");

	auto app = Nika::createApplication();
	app->run();
	delete app;
}
// =================================
// ==================================================

#endif

