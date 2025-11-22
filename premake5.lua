workspace "Nika"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- ENGINE SETTINGS --
project "Nika"
	location "Nika"
	kind "SharedLib"
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
		"Nika/vendor/spdlog/include"
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

	filter "configurations:Dist"
		defines "NIKA_DIST"
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
		"Nika/vendor/spdlog/include",
		"Nika/src"
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

	filter "configurations:Dist"
		defines "NIKA_DIST"
		optimize "On"

