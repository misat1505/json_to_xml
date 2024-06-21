#include "../headers/errors/LexicalError.h"
#include "../headers/Lexer.h"
#include <iostream>

Lexer::Lexer(std::ifstream& in) : reader(in) {
    this->current = std::nullopt;
    this->reader.get_next();
}

std::optional<Token> Lexer::get_current() const {
    return this->current;
}

Token Lexer::generate_token() {
    this->skip_whitespaces();
    // std::cout << "start: " << this->reader.get_current() << "\n";
    std::optional<Token> token;

    if (
        (token = this->try_build_sign()) ||
        (token = this->try_build_string())
    ) return token.value();

    return Token(TokenType::END, std::monostate{}, this->reader.get_position());
}

void Lexer::skip_whitespaces() {
    while(isspace(this->reader.get_current())) {
        this->reader.get_next();
    }
}

std::optional<Token> Lexer::try_build_sign() {
    char current = this->reader.get_current();
    Position position = this->reader.get_position();

    switch (current) {
        case ',':
            this->reader.get_next();
            return Token(TokenType::COMMA, std::monostate{}, position);
        case ':':
            this->reader.get_next();
            return Token(TokenType::COLON, std::monostate{}, position);
        case '{':
            this->reader.get_next();
            return Token(TokenType::BRACE_OPEN, std::monostate{}, position);
        case '}':
            this->reader.get_next();
            return Token(TokenType::BRACE_CLOSE, std::monostate{}, position);
        case '[':
            this->reader.get_next();
            return Token(TokenType::BRACKET_OPEN, std::monostate{}, position);
        case ']':
            this->reader.get_next();
            return Token(TokenType::BRACKET_CLOSE, std::monostate{}, position);
        default:
            return std::nullopt;
    }
}

std::optional<Token> Lexer::try_build_string() {
    if (this->reader.get_current() != '\"') return std::nullopt;

    Position position = this->reader.get_position();
    this->reader.get_next();
    std::string buffer;

    while (this->reader.get_current() != '\"') {
        if (this->reader.get_current() == ETX) {
            position = this->reader.get_position();
            std::string message = "String not closed.\nAt line " + std::to_string(position.row) + " column: " + std::to_string(position.column);
            throw LexicalError(message);
        }
        buffer.push_back(this->reader.get_current());
        this->reader.get_next();
    }

    this->reader.get_next();
    return Token(TokenType::STRING, buffer, position);
}