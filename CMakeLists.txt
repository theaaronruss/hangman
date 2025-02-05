cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
project(hangman LANGUAGES CXX)
add_executable(hangman
    src/main.cpp
    src/mistakes.cpp
    src/phrases.cpp
)
