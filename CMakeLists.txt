cmake_minimum_required (VERSION 2.8.9)
project (TCC)

include_directories(include)

set (CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "src/*.cpp")


add_executable(TCC ${SOURCES})


