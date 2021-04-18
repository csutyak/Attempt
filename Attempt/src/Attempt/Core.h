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

#ifdef AMT_ENABLE_ASSERTS
	#define AMT_ASSERT(x, ...) { if(!(x)) {AMT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AMT_CORE_ASSERT(x, ...) { if(!(x)) {AMT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AMT_ASSERT(x, ...) 
	#define AMT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)