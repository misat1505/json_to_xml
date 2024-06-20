#include "../headers/Converter.h"

Converter::Converter(std::ifstream& in) : stream(in), lexer(in) {
    this->lexer.generate_token();
}