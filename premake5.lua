workspace "PEngine"
    architecture "x64" --Platform
    startproject "SandBox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "PEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "PEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "PEngine/vendor/imgui"
IncludeDir["glm"] = "PEngine/vendor/glm"

include "PEngine/vendor/GLFW"
include "PEngine/vendor/Glad"
include "PEngine/vendor/imgui"

project "PEngine"
    location "PEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pepch.h"
    pchsource "PEngine/src/pepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS",
            "PENGINE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/SandBox/\"")
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        runtime "Release"
        optimize "On"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "PEngine/vendor/spdlog/include",
        "PEngine/src",
        "%{IncludeDir.glm}"
    }

    links
    {
        "PEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        runtime "Release"
        optimize "On"