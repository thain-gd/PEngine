include "./vendor/premake/premake_customization/solution_items.lua"

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

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/PEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/PEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/PEngine/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/PEngine/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/PEngine/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/PEngine/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/PEngine/vendor/yaml-cpp/include"

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