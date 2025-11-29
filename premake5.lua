workspace "Nika"
	architecture "x86"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Nika/vendor/GLFW/include"

include "Nika/vendor/GLFW"


-- ENGINE SETTINGS --
project "Nika"
	location "Nika"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nkpch.h"
	pchsource "Nika/src/nkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src", -- src
		"%{prj.name}/vendor/spdlog/include", -- spdlog
		"%{IncludeDir.GLFW}" -- GLFW
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NIKA_WIN32",
			"NIKA_BUILD_DLL"
		}

		characterset "Unicode"
		buildoptions { "/utf-8" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NIKA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NIKA_RELEASE"
		optimize "On"


-- SANDBOX SETTINGS --
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nika/src",
		"Nika/vendor/spdlog/include"
	}

	links
	{
		"Nika"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NIKA_WIN32"
		}

		characterset "Unicode"
		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "NIKA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NIKA_RELEASE"
		optimize "On"

