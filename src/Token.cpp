#include "../headers/Token.h"

Token::Token(TokenType token_type, std::variant<int, float, std::string> value) : token_type(token_type), value(value) {}

TokenType Token::get_type() const {
    return this->token_type;
}

std::variant<int, float, std::string> Token::get_value() const {
    return this->value;
}