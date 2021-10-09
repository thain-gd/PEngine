include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "PEngine"
	architecture "x64"
	startproject "PEngine-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "PEngine/vendor/GLFW"
	include "PEngine/vendor/Glad"
	include "PEngine/vendor/imgui"
	include "PEngine/vendor/yaml-cpp"
group ""

include "PEngine"
include "SandBox"
include "PEngine-Editor"
