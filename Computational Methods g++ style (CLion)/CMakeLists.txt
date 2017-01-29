cmake_minimum_required(VERSION 3.5)
project(Computational_Methods_Bednarek)

set(CMAKE_CXX_STANDARD 11)

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

add_executable(Computational_Methods_Bednarek ${SOURCE_FILES})