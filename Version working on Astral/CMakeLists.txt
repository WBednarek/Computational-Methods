cmake_minimum_required(VERSION 3.5)
project(High_Performance_Technical_Computing)

#set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Display.cpp
        Display.h
        ExplicitUpwindScheme.cpp
        ExplicitUpwindScheme.h
        GeneralScheme.cpp
        GeneralScheme.h
        ImplicitUpwindScheme.cpp
        ImplicitUpwindScheme.h
        Lax_Wendroff.cpp
        Lax_Wendroff.h
        main.cpp
        main.h
        MathFunctions.cpp
        MathFunctions.h
        Matrix.cpp
        Matrix.h
        Richtmyer_multi_step.cpp
        Richtmyer_multi_step.h)

add_executable(High_Performance_Technical_Computing ${SOURCE_FILES})