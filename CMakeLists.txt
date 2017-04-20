cmake_minimum_required(VERSION 3.6)
project(GlutGl)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MainGame.h MainGame.cpp GlUtils/Shader.cpp GlUtils/Shader.h GlUtils/Mesh.cpp
        GlUtils/Mesh.h GlUtils/Camera.cpp GlUtils/Camera.h GlUtils/Texture.cpp GlUtils/Texture.h
        GlUtils/Engine.cpp GlUtils/Engine.h GlUtils/OrthographicCamera.cpp GlUtils/OrthographicCamera.h GlUtils/SpriteBatch.cpp GlUtils/SpriteBatch.h)
add_executable(debug ${SOURCE_FILES})

target_link_libraries(debug ${GLEW_LIBRARIES} ${OPENGL_gl_LIBRARY}
        ${SDL2_LIBRARIES} -lSOIL)