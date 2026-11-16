cmake_minimum_required(VERSION 3.16)
project(FlappyBird)

add_executable(Game)

target_sources(Game
  PRIVATE
    src/main.cpp
)