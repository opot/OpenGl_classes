cmake_minimum_required(VERSION 3.6)
project(GlutGl)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MainGame.h MainGame.cpp GlUtils/Shader.cpp GlUtils/Shader.h GlUtils/Model.cpp
        GlUtils/Model.h GlUtils/Camera.cpp GlUtils/Camera.h GlUtils/Texture.cpp GlUtils/Texture.h)
add_executable(debug ${SOURCE_FILES})

target_link_libraries(debug ${GLEW_LIBRARIES} ${OPENGL_gl_LIBRARY}
        ${SDL2_LIBRARIES} -lSOIL)