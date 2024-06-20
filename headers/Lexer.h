#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <optional>
#include "Token.h"

class Lexer {
    public:
        Lexer(std::ifstream& in);
        std::optional<Token> generate_token();
    
    private:
        std::ifstream& stream;
};

#endif