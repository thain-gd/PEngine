workspace "PEngine"
    architecture "x64" --Platform

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PEngine"
    location "PEngine"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS",
            "PENGINE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        optimize "On"

project "SandBox"
    location "SandBox"
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
        "PEngine/vendor/spdlog/include",
        "PEngine/src"
    }

    links
    {
        "PEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines
        {
            "PENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PENGINE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PENGINE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PENGINE_DIST"
        optimize "On"