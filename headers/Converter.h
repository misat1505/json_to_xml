#ifndef CONVERTER_H
#define CONVERTER_H

#include <fstream>
#include "Lexer.h"

class Converter {
    public:
        Converter(std::ifstream& in);
    
    private:
        std::ifstream& stream;
        Lexer lexer;
};

#endif