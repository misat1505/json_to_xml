#include <variant>
#include <string>

#include "Position.h"
#include <iostream>

enum TokenType {
    INT,
    FLOAT,
    STRING,

    COMMA,
    COLON,

    BRACE_OPEN,
    BRACE_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,

    TRUE,
    FALSE,
    NONE,

    END
};

class Token {
    public:
        Token(TokenType token_type, std::variant<std::monostate, int, float, std::string> value, Position position);
        TokenType get_type() const;
        std::variant<std::monostate, int, float, std::string> get_value() const;
        Position get_position() const;

        friend std::ostream& operator<<(std::ostream& os, const Token& token);

    private:
        TokenType token_type;
        std::variant<std::monostate, int, float, std::string> value;
        Position position;
};