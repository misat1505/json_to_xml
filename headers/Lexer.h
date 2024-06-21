#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <optional>
#include "Token.h"
#include "Reader.h"

class Lexer {
    public:
        Lexer(std::ifstream& in);
        std::optional<Token> get_current() const;
        Token generate_token();
    
    private:
        Reader reader;
        std::optional<Token> current;

        void skip_whitespaces();
        std::optional<Token> try_build_sign();
        std::optional<Token> try_build_string();
        std::optional<Token> try_build_keyword();
        std::optional<Token> try_build_number();
};

#endif
