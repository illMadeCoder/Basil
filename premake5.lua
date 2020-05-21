workspace "Basil"
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	IncludeDir = {}
	IncludeDir["GLFW"] = "Basil/vendor/GLFW/include"
	include "Basil/vendor/GLFW"
	
project "Basil"
	location "Basil"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	pchheader "basilpch.h"
	pchsource "Basil/src/basilpch.cpp"
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
	   "Basil/vendor/spdlog/include",	   
	   "%{prj.name}/src",
	   "%{IncludeDir.GLFW}"
	}

	links {
	   "GLFW",
	   "opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"BASIL_BUILD_DLL",
			"BASIL_PLATFORM_WINDOWS"
		}

		postbuildcommands {
			{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
		}
		
		filter "configurations:Debug"
			defines "BASIL_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "BASIL_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "BASIL_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Basil/vendor/spdlog/include",
		"Basil/src"
	}

	links
	{
		"Basil"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"BASIL_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "BASIL_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "BASIL_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "BASIL_DIST"
			optimize "On"
