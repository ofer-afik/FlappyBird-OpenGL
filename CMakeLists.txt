cmake_minimum_required(VERSION 3.16)
project(FlappyBird)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

add_executable(Game)

target_sources(Game
  PRIVATE
    include/include/glad.c
    src/main.cpp
)

target_include_directories(Game
  PRIVATE
    include/include/
    src/
)

target_link_libraries(Game
  PRIVATE
    OpenGL::GL
    glfw
)

target_compile_options(Game
  PRIVATE
    "-fmacro-prefix-map=${CMAKE_SOURCE_DIR}/="
)