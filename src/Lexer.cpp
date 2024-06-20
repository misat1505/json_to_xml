#include "../headers/Lexer.h"

Lexer::Lexer(std::ifstream& in) : stream(in) {}

std::optional<Token> Lexer::generate_token() {
    return std::nullopt;
}