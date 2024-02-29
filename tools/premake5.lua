
workspace "Engine"

	configurations { "Debug", "Release", "RelWithDebInfo" }
	architecture "x64"
	location "../build"
	cppdialect "c++20"
	startproject "Window"

	filter "configurations:Debug"
	defines { "DEBUG" }
	symbols "On"
	runtime "Debug"

	filter "configurations:Release"
	defines { "NDEBUG" }
	optimize "On"
	runtime "Release"

	filter "configurations:RelWithDebInfo"
	defines { "NDEBUG" }
	optimize "On"
	runtime "Release"
	symbols "On"

	filter {}


project "Motor"
	kind "StaticLib"
	defines { "GLEW_STATIC", "TINYOBJLOADER_IMPLEMENTATION", }
	targetdir "../build/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	files {
		"premake5.lua",
		"../include/**", "../src/**",
		"../deps/imgui/backends/imgui_impl_opengl3.cpp",
		"../deps/imgui/backends/imgui_impl_glfw.cpp",
		"../deps/imgui/*.cpp",
	}

project"00_Demo"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/demo_example.cpp"

project"01_Window"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/window_example.cpp"

project"02_JobSystem"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/job_system_example.cpp"

project"03_Triangle"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/triangle_example.cpp"

project"04_ECS"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/ecs_example.cpp"

project"05_Input"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/input_example.cpp"

project"06_TriangleMany"
	kind "ConsoleApp"
	language "C++"
	targetdir "../build/%{prj.name}/%{cfg.buildcfg}"
	includedirs { "../include/**", "../deps/**", }
	libdirs { "../deps/glew/lib/x64", "../deps/glfw/lib/x64", }
	links { "Motor", "glfw3", "glew32s", "OpenGL32.lib"}
	debugargs { _MAIN_SCRIPT_DIR .. "../examples/data" }
	files "../examples/triangle_many_example.cpp"