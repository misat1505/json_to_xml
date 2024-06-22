#ifndef PARSER_H
#define PARSER_H

#include <optional>
#include "Lexer.h"
#include "ast/Node.h"

class Parser {
    public:
        Parser(Lexer& lexer);
        Node parse();
    
    private:
        Lexer lexer;

        std::optional<Node> parse_true();
        std::optional<Node> parse_false();
        std::optional<Node> parse_null();
        std::optional<Node> parse_number();
        std::optional<Node> parse_string();
};

#endif
