#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
// #include "Visitor.h"
// #include "ArrayValue.h"
#include "Visitor.h"
#include "Node.h"
#include "ArrayValue.h"
#include "NullValue.h"
#include "TrueValue.h"
#include "FalseValue.h"
#include "NumberValue.h"
#include "StringValue.h"
#include "ObjectValue.h"

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
        std::cout << "[";

        bool first = true;
        for (auto &child : node.get_value())
        {
            if (!first)
            {
                std::cout << ", ";
            }
            first = false;
            child->accept(*this);
        }

        std::cout << "]";
    }

    void visit(ObjectValue &node) override
    {
        std::cout << "{";

        bool first = true;
        for (const auto &pair : node.get_value())
        {
            if (!first)
            {
                std::cout << ", ";
            }
            first = false;
            std::cout << "\"" << pair.first << "\": ";
            pair.second->accept(*this);
        }

        std::cout << "}";
    }

    void visit(Node &node) override
    {
        if (node.get_value())
        {
            node.get_value()->accept(*this);
        }
    }
};

#endif