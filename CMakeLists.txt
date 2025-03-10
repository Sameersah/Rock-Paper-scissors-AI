cmake_minimum_required(VERSION 3.30)
project(RockPaperScissorsAI)

set(CMAKE_CXX_STANDARD 20)

add_executable(RockPaperScissorsAI src/main.cpp
        src/Game.cpp)
