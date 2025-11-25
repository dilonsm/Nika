#pragma once

#ifdef NIKA_WIN32
	#ifdef NIKA_BUILD_DLL
		#define NIKA_API __declspec(dllexport)
	#else
		#define NIKA_API __declspec(dllimport)
	#endif
#endif

#define BIT(x) (1 << x)

