cmake_minimum_required(VERSION 3.16)
project(FlappyBird)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

if (DEFINED ENV{GITHUB_ACTIONS})
  include(FetchContent)

  set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

  FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
  )

  FetchContent_MakeAvailable(glfw)
endif()

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(Game)

target_sources(Game
  PRIVATE
    include/include/glad.c
    src/main.cpp
    src/code/core/game_setup.cpp
    src/code/core/state_machine.cpp
    src/code/core/draw_quad.cpp
    src/code/core/shader.cpp
    src/code/game/globals.cpp
    src/code/game/player.cpp
)

target_include_directories(Game
  PRIVATE
    include/include/
    src/code/
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