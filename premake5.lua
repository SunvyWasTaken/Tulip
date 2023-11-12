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
ModuleDir = "%{prj.name}/vendor/"
IncludeDir = {}
IncludeDir["GLFW"] = "%{ModuleDir}GLFW/include"
IncludeDir["spdlog"] = "%{ModuleDir}spdlog/include"
IncludeDir["Glad"] = "%{ModuleDir}Glad/include"
IncludeDir["ImGui"] = "%{ModuleDir}imgui"

include "Tulip/vendor/GLFW"
include "Tulip/vendor/Glad"
include "Tulip/vendor/imgui"


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
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		cdialect "C17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TL_PLATFORM_WINDOWS",
			"TL_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"TL_DEBUG",
			"TL_CORE_ASSETS",
			"TL_RELEASE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TL_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "TL_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TL_DIST"
		buildoptions "/MD"
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
		cdialect "C17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TL_DEBUG"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Release"
		defines "TL_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "TL_DIST"
		buildoptions "/MD"
		optimize "On"

