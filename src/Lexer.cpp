#include "../headers/errors/LexicalError.h"
#include "../headers/Lexer.h"
#include "../headers/Position.h"
#include <map>

Lexer::Lexer(std::ifstream& in) : reader(in) {
    this->current = std::nullopt;
    this->reader.get_next();
}

std::optional<Token> Lexer::get_current() const {
    return this->current;
}

Token Lexer::generate_token() {
    this->skip_whitespaces();
    std::optional<Token> token;

    if (
        (token = this->try_build_sign()) ||
        (token = this->try_build_string()) ||
        (token = this->try_build_keyword()) ||
        (token = this->try_build_number())
    ) {
        this->current = token.value();
        return token.value();
    }

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
            std::string message = "String not closed.\nAt " + position.to_string();
            throw LexicalError(message);
        }
        buffer.push_back(this->reader.get_current());
        this->reader.get_next();
    }

    this->reader.get_next();
    return Token(TokenType::STRING, buffer, position);
}

std::optional<Token> Lexer::try_build_keyword() {
    char current = this->reader.get_current();
    Position position = this->reader.get_position();
    if (!isalpha(current))
        return std::nullopt;

    std::string buffer;
    while(isalpha(current)) {
        buffer.push_back(current);
        current = this->reader.get_next();
    }

    std::map<std::string, TokenType> map = {
        {"true", TokenType::TRUE},
        {"false", TokenType::FALSE},
        {"null", TokenType::NONE},
    };

    if (map.find(buffer) == map.end()) {
        throw LexicalError("Invalid keyword: '" + buffer + "'.\nAt " + position.to_string());
    }

    TokenType t_type = map[buffer];
    return Token(t_type, std::monostate{}, position);
}

std::optional<Token> Lexer::try_build_number() {
    char current = this->reader.get_current();
    Position position = this->reader.get_position();

    if (!isdigit(current) && current != '-') {
        return std::nullopt;
    }

    std::string buffer;
    if (current == '-') {
        buffer.push_back(current);
        current = this->reader.get_next();
        if (!isdigit(current)) {
            throw LexicalError("Cannot create number.\nAt " + position.to_string());
        }
    }

    while (isdigit(current)) {
        buffer.push_back(current);
        current = this->reader.get_next();
    }

    if (current != '.')
        return Token(TokenType::INT, buffer, position);
    
    buffer.push_back(current);
    current = this->reader.get_next();
    while (isdigit(current)) {
        buffer.push_back(current);
        current = this->reader.get_next();
    }

    return Token(TokenType::FLOAT, buffer, position);
}