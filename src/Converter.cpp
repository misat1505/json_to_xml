#include "../headers/Converter.h"
#include "../headers/Printer.h"
#include <iostream>
#include <memory>

Converter::Converter(std::ifstream &in) : stream(in), lexer(in), parser(lexer)
{
    auto tree = parser.parse();
    auto printer = std::make_unique<Printer>(std::cout);
    tree.accept(*printer);
}