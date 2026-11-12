project "raylib"
	kind "StaticLib"
	language "C"
	cdialect "C11"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"src/*.h",
		"src/*.c"
	}

	includedirs
	{
		"src",
    	"src/external",
    	"src/external/glfw/include"
	}
	
	filter "system:windows"
		systemversion "latest"
		staticruntime "Off"
		
		defines
		{
			"_CRT_SECURE_NO_WARNINGS",
			"PLATFORM_DESKTOP"
		}
		
		links
		{
			"opengl32",
			"winmm",
			"gdi32"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "on"

