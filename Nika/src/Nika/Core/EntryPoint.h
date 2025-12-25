#pragma once

#ifdef NIKA_WIN32

extern std::unique_ptr<Nika::NikaApp>(Nika::createApplication());

// ---- Entry Point ---------------------------------
int main(int argc, char** argv)
{
	Nika::Log::initLog();

	NIKA_TRACE("This is exhausting..");

	auto app = Nika::createApplication();
	app->run();

	return 0;
}
// --------------------------------------------------

#endif // NIKA_WIN32

