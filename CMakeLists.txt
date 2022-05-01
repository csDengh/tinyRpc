cmake_minimum_required(VERSION 3.0)
project(zmprpc)

set(CMAKE_BUILD_TYPE "Debug")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)

add_subdirectory(src)
add_subdirectory(example)


