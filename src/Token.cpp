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

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "Token: ";
    
    // Print TokenType
    switch (token.token_type) {
        case TokenType::INT:
            os << "INT";
            break;
        case TokenType::FLOAT:
            os << "FLOAT";
            break;
        case TokenType::STRING:
            os << "STRING";
            break;
        case TokenType::COMMA:
            os << "COMMA";
            break;
        case TokenType::COLON:
            os << "COLON";
            break;
        case TokenType::BRACE_OPEN:
            os << "BRACE_OPEN";
            break;
        case TokenType::BRACE_CLOSE:
            os << "BRACE_CLOSE";
            break;
        case TokenType::BRACKET_OPEN:
            os << "BRACKET_OPEN";
            break;
        case TokenType::BRACKET_CLOSE:
            os << "BRACKET_CLOSE";
            break;
        case TokenType::END:
            os << "END";
            break;
        default:
            os << "Unknown";
            break;
    }
    
    // Print value if it's not std::monostate
    os << ", Value: ";
    std::visit([&os](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            os << "[No value]";
        } else {
            os << arg;
        }
    }, token.get_value());
    
    // Print position
    os << ", Position: (" << token.position.row << ", " << token.position.column << ")";
    
    return os;
}