workspace "Tulip"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFM"] = "Tulip/vendor/GLFM/include"

include "Tulip/vendor/GLFM"

project "Tulip"
	location "Tulip"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tlpch.h"
	pchsource "Tulip/src/tlpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFM}"
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
			"TL_PLATFORM_WINDOWS",
			"TL_BUILD_DLL",
			"TL_DEBUG",
			"TL_RELEASE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TL_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "TL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TL_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

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
		"Tulip/vendor/spdlog/include",
		"Tulip/src"
	}

	links
	{
		"Tulip"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TL_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "TL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TL_DIST"
		optimize "On"
