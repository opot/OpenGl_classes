find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(SOIL CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory(reactphysics3d)

include_directories(. OpenGL glfw3 SOIL ${GLEW_SOURCE} reactphysics3d/src)
file(GLOB GLUTILS_SOURCES *.h *.cpp)
file(GLOB ECS_SOURCES ecs/ECS.cpp ecs/systems/*.cpp)

add_library(GlUtils ${GLUTILS_SOURCES} ${ECS_SOURCES})

target_link_libraries(GlUtils ${OPENGL_gl_LIBRARY} glfw SOIL glm GLEW::GLEW reactphysics3d)
