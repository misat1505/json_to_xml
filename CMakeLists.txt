cmake_minimum_required(VERSION 3.10)

project(Converter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)

set(SOURCES
    src/Converter.cpp
    src/Lexer.cpp
    src/Token.cpp
    src/Reader.cpp
    src/main.cpp
)

add_executable(Converter ${SOURCES})
