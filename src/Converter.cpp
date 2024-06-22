#include "../headers/Converter.h"
#include <iostream>

Converter::Converter(std::ifstream &in) : stream(in), lexer(in), parser(lexer)
{
    parser.parse();
}