if(UNIX)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(SOIL REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLEW REQUIRED)

#add_subdirectory(reactphysics3d)

include_directories(. OpenGL glfw3 SOIL ${GLEW_SOURCE})
file(GLOB GLUTILS_SOURCES *.h *.cpp)

add_library(GlUtils ${GLUTILS_SOURCES})

target_link_libraries(GlUtils ${OPENGL_gl_LIBRARY} glfw SOIL glm GLEW::GLEW)
