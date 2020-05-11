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