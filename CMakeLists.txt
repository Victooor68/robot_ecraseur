cmake_minimum_required(VERSION 3.15)
project(robot_ecraseur)

set(CMAKE_CXX_STANDARD 17)

include_directories(header)

add_executable(robot_ecraseur
        header/entite.h
        src/entite.cpp
        src/debris.cpp
        header/debris.h
        header/entiteFixe.h
        src/entiteFixe.cpp
        header/entiteMouvante.h
        src/entiteMouvante.cpp
        header/joueur.h
        src/joueur.cpp
        header/joueurExpert.h
        src/joueurExpert.cpp
        header/joueurNormal.h
        src/joueurNormal.cpp
        header/robot.h
        src/robot.cpp
        header/robot_1gen.h
        src/robot_1gen.cpp
        header/robot_2gen.h
        src/robot_2gen.cpp
        header/doctest.h
        header/terrain.h
        header/position.hpp
        src/terrain.cpp
        src/position.cpp
        src/game.cpp
        header/game.h
        header/persistance.h
        src/persistance.cpp
        testpackage/entiteTest.cpp
        testpackage/testmain.cpp
        testpackage/positionTest.cpp
        src/persistance.cpp
        testpackage/entiteTest.cpp
        testpackage/testmain.cpp
        testpackage/terrainTest.cpp
        testpackage/entiteMouvanteTest.cpp
        testpackage/joueurTest.cpp
        src/winbgi.cpp
        header/graphics.h
        testpackage/robot_1genTest.cpp
        testpackage/gameTest.cpp)