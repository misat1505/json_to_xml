#include "../headers/Token.h"

Token::Token(TokenType token_type, std::variant<std::monostate, int, float, std::string> value, Position position) : token_type(token_type), value(value), position(position) {}

TokenType Token::get_type() const {
    return this->token_type;
}

std::variant<std::monostate, int, float, std::string> Token::get_value() const {
    return this->value;
}

Position Token::get_position() const {
    return this->position;
}