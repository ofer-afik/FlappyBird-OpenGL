cmake_minimum_required(VERSION 3.16)
project(FlappyBird)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

add_executable(Game)

target_sources(Game
  PRIVATE
    src/main.cpp
)