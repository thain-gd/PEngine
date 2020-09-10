workspace "PEngine"
    architecture "x64"
    startproject "PEngine-Editor"

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
IncludeDir["stb_image"] = "PEngine/vendor/stb_image"

group "Dependencies"
    include "PEngine/vendor/GLFW"
    include "PEngine/vendor/Glad"
    include "PEngine/vendor/imgui"
group ""

project "PEngine"
    location "PEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pepch.h"
    pchsource "PEngine/src/pepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        runtime "Release"
        optimize "on"

project "PEngine-Editor"
    location "PEngine-Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
        "PEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "PEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        runtime "Release"
        optimize "on"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
        "PEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "PEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        runtime "Release"
        optimize "on"

project "PEngine-Editor"
    location "PEngine-Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
        "PEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "PEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        runtime "Release"
        optimize "on"