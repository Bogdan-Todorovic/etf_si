cmake_minimum_required(VERSION 4.1)
project(ImageForge)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)


file(GLOB_RECURSE HEADERS
        "${CMAKE_SOURCE_DIR}/include/*.hpp"
)

add_executable(ImageForge main.cpp
        ${SOURCES}
        ${HEADERS}
)
