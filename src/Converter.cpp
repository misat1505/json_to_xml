#include "../headers/Converter.h"
#include <iostream>

Converter::Converter(std::ifstream& in) : stream(in), lexer(in) {
    std::optional<Token> token = this->lexer.generate_token();
    if (token) {
        TokenType type = token->get_type();
        switch (type) {
            case TokenType::COMMA:
                std::cout << "TokenType::COMMA\n";
                break;
            case TokenType::COLON:
                std::cout << "TokenType::COLON\n";
                break;
            case TokenType::BRACE_OPEN:
                std::cout << "TokenType::BRACE_OPEN\n";
                break;
            case TokenType::BRACE_CLOSE:
                std::cout << "TokenType::BRACE_CLOSE\n";
                break;
            case TokenType::BRACKET_OPEN:
                std::cout << "TokenType::BRACKET_OPEN\n";
                break;
            case TokenType::BRACKET_CLOSE:
                std::cout << "TokenType::BRACKET_CLOSE\n";
                break;
            // Add other token types as needed
            default:
                std::cout << "Unknown TokenType\n";
                break;
        }
    } else {
        std::cout << "No token generated.\n";
    }
}