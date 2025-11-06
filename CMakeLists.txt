cmake_minimum_required(VERSION 3.15)
project(SimpleRender)

set(CMAKE_CXX_STANDARD 17)

set(SRC_FILES
    src/main.cpp
    src/core/Application.cpp
    src/core/Window.cpp
    src/rendering/Renderer.cpp
    src/rendering/Shader.cpp
    libs/glad/src/glad.c
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/include
)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

add_executable(SimpleRender ${SRC_FILES})

target_link_libraries(SimpleRender ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})

file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
