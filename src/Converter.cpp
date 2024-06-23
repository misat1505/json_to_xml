#include "../headers/Converter.h"

namespace JSON_TO_XML
{
    void convert(std::ifstream &in, std::ofstream &out, std::string indent_sequence)
    {
        auto lexer = Lexer(in);
        auto parser = Parser(lexer);
        auto tree = parser.parse();

        Printer printer(out, indent_sequence);
        tree.accept(printer);
    }
}