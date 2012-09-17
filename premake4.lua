local QT_LIBRARIES = "-lQtCore -lQtGui"

solution "MansionEscape"
    configurations { "Debug", "Release" }
    flags { "ExtraWarnings", "FloatFast" }
    includedirs { "src/Headers", "/usr/include/qt4" }

    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize" }

    project "MansionEscape"
        kind "ConsoleApp"
        language "C++"
        targetdir "build"
        files { "src/MansionEscape/**.cpp" }
        buildoptions { "-std=c++11" }
        linkoptions { QT_LIBRARIES }
