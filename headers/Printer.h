#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include "Visitor.h"

class Printer : public Visitor
{
public:
    void visit(FalseValue &node) override
    {
        std::cout << "false\n";
    }

    void visit(NullValue &node) override
    {
        std::cout << "null\n";
    }

    void visit(TrueValue &node) override
    {
        std::cout << "true\n";
    }

    void visit(NumberValue &node) override
    {
        std::cout << "1\n";
    }

    void visit(StringValue &node) override
    {
        std::cout << "hello\n";
    }

    void visit(ArrayValue &node) override
    {
        std::cout << "array\n";
    }

    void visit(ObjectValue &node) override
    {
        std::cout << "object\n";
    }

    void visit(Node &node) override
    {
        std::cout << "node\n";
    }
};

#endif