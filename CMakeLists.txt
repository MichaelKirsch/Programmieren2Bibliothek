cmake_minimum_required(VERSION 3.16)
project(Programmieren2Bibliothek)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.h" "src/*.hpp" "src/*.cpp")

add_executable(Programmieren2Bibliothek ${SOURCES})