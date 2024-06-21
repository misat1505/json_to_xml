#include "../headers/Converter.h"
#include <iostream>

Converter::Converter(std::ifstream& in) : stream(in), lexer(in) {
    Token token = this->lexer.generate_token();

    while (token.get_type() != TokenType::END) {
        std::cout << token << "\n";
        token = this->lexer.generate_token();
    }
}