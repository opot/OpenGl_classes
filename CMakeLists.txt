cmake_minimum_required(VERSION 3.6)
project(GlutGl)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MainGame.h MainGame.cpp Shader.cpp Shader.h Model.cpp Model.h)
add_executable(debug ${SOURCE_FILES})

target_link_libraries(debug ${GLEW_LIBRARIES} ${OPENGL_gl_LIBRARY}
        ${GLUT_LIBRARIES})