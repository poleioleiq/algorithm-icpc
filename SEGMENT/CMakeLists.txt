cmake_minimum_required(VERSION 3.15)
project(SEGMENT)

set(CMAKE_CXX_STANDARD 14)

add_executable(SEGMENT
        BZOJ_4695.cpp
        HDU_1255.cpp
        HDU_1540.cpp
        HDU_1542.cpp
        HDU_1698.cpp
        HDU_3462.cpp
        HDU_3974.cpp
        HDU_3974_2.cpp
        HDU_4553.cpp
        HDU_4578.cpp
        HDU_4614.cpp
        P3372.cpp
        POJ_1177.cpp
        POJ_2528.cpp
        ZOJ_1610.cpp

        P1531.cpp P1198.cpp test.cpp)
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} )
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
