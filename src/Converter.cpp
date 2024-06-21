#include "../headers/Converter.h"
#include <iostream>

Converter::Converter(std::ifstream& in) : stream(in), lexer(in) {
    Token token = this->lexer.generate_token();

    while (token.get_type() != TokenType::END) {
        TokenType type = token.get_type();
        switch (type) {
            case TokenType::COMMA:
                std::cout << "TokenType::COMMA\t";
                break;
            case TokenType::COLON:
                std::cout << "TokenType::COLON\t";
                break;
            case TokenType::BRACE_OPEN:
                std::cout << "TokenType::BRACE_OPEN\t";
                break;
            case TokenType::BRACE_CLOSE:
                std::cout << "TokenType::BRACE_CLOSE\t";
                break;
            case TokenType::BRACKET_OPEN:
                std::cout << "TokenType::BRACKET_OPEN\t";
                break;
            case TokenType::BRACKET_CLOSE:
                std::cout << "TokenType::BRACKET_CLOSE\t";
                break;
        }
        std::cout << "line: " << token.get_position().row << ", column: " << token.get_position().column << "\n";
        token = this->lexer.generate_token();
    }
}