workspace "Attempt"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir  = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Attempt/vendor/GLFW/include"

include "Attempt/vendor/GLFW"

project "Attempt"
    location "Attempt"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .. "/%{prj.name}")

    pchheader "amtpch.h"
    pchsource "Attempt/src/amtpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "AMT_PLATFORM_WINDOWS",
            "AMT_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "AMT_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "AMT_DEBUG"
        symbols "On"
    
    filter "configurations:Dist"
        defines "AMT_DEBUG"
        symbols "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "$(SolutionDir)Attempt/vendor/spdlog/include",
        "$(solutionDir)Attempt/src"
    }

    links
    {
        "Attempt"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "AMT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AMT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AMT_DEBUG"
        symbols "On"

    filter "configurations:Dist"
        defines "AMT_DEBUG"
        symbols "On"