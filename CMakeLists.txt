cmake_minimum_required(VERSION 3.6)
project(GlutGl)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(GlUtils)
include_directories(GlUtils)

file(GLOB SOURCE_FILES src/*.cpp src/*.h)
add_executable(debug ${SOURCE_FILES})
target_link_libraries(debug GlUtils)