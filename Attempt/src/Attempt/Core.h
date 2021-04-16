#pragma once

#ifdef AMT_PLATFORM_WINDOWS
	#ifdef AMT_BUILD_DLL
		#define ATTEMPT_API __declspec(dllexport)
	#else
		#define ATTEMPT_API __declspec(dllimport)
	#endif
#else
	#error Only supports windows!
#endif