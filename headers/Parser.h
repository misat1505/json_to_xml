#ifndef PARSER_H
#define PARSER_H

#include <optional>
#include <vector>
#include <memory>
#include "Lexer.h"
#include "ast/Node.h"

class Parser {
    public:
        Parser(Lexer& lexer);
        Node parse();
    
    private:
        Lexer lexer;

        void must_be(TokenType token_type);
        std::optional<Node> parse_value();

        std::optional<Node> parse_true();
        std::optional<Node> parse_false();
        std::optional<Node> parse_null();
        std::optional<Node> parse_number();
        std::optional<Node> parse_string();
        std::optional<Node> parse_array();
        std::vector<std::unique_ptr<Node>> parse_array_inner();
};

#endif
