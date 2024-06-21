#include "../headers/Lexer.h"

Lexer::Lexer(std::ifstream& in) : reader(in) {}

std::optional<Token> Lexer::generate_token() {
    return std::nullopt;
}