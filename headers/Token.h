#include <variant>
#include <string>

enum TokenType {
    INT,
    FLOAT,
    STRING,

    COMMA,

    BRACE_OPEN,
    BRACE_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE
};

class Token {
    public:
        Token(TokenType token_type, std::variant<int, float, std::string> value);
        TokenType get_type() const;
        std::variant<int, float, std::string> get_value() const;

    private:
        TokenType token_type;
        std::variant<int, float, std::string> value;
};