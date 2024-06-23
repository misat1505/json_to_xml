#ifndef JSON_TO_XML_CONVERTER_H
#define JSON_TO_XML_CONVERTER_H

#include <fstream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "Printer.h"

namespace JSON_TO_XML
{
    void convert(std::ifstream &in, std::ofstream &out, std::string indent_sequence = "\t");
}

#endif
