cmake_minimum_required(VERSION 3.10)
set(CMAKE_GENERATOR "Unix Makefiles")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(tbc VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(tbc ${SRC_FILES})
target_include_directories(tbc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
