#pragma once

#ifdef BASIL_PLATFORM_WINDOWS
	#ifdef BASIL_BUILD_DLL
		#define BASIL_API __declspec(dllexport)
	#else
		#define BASIL_API __declspec(dllimport)
	#endif	
#else
	#error BASIL only supports windows
#endif

#ifdef BASIL_ENABLE_ASSERTS
#define BASIL_ASSERT(x, ...) { if(!(x)) { BASIL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#define BASIL_CORE_ASSERT(x, ...) { if(!(x)) { BASIL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define BASIL_ASSERT(x, ...)
#define BASIL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)