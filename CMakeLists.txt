cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)

set(SOURCES
    src/Converter.cpp
    src/Lexer.cpp
    src/Token.cpp
    src/main.cpp
)

add_executable(MyProject ${SOURCES})
