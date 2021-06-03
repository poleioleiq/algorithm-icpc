cmake_minimum_required(VERSION 3.15)
project(TREE_CHAIN_SPLIT)

set(CMAKE_CXX_STANDARD 14)

add_executable(TREE_CHAIN_SPLIT P3384.cpp P3384_2.cpp P3384_3.cpp HAOI2015.cpp ZJOI_2008.cpp test.cpp SEG_N/POJ_2104.cpp P3372.cpp)
# 遍历项目根目录下所有的 .cpp 文件
file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} )
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()