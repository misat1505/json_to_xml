cmake_minimum_required(VERSION 3.10)

project(Converter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(headers)

set(SOURCES
    src/Lexer.cpp
    src/Token.cpp
    src/Reader.cpp
    src/Position.cpp
    src/Parser.cpp
    src/ast/Node.cpp
    src/ast/NullValue.cpp
    src/ast/TrueValue.cpp
    src/ast/FalseValue.cpp
    src/ast/NumberValue.cpp
    src/ast/StringValue.cpp
    src/ast/ArrayValue.cpp
    src/ast/ObjectValue.cpp
    src/Converter.cpp
    src/Printer.cpp
    src/main.cpp
)

add_executable(Converter ${SOURCES})

include_directories(headers/ast)
