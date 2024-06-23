#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <memory>
#include <string>
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
    Printer(std::ostream &out, std::string indent_sequence = "\t");

    void visit(FalseValue &node) override;
    void visit(NullValue &node) override;
    void visit(TrueValue &node) override;
    void visit(NumberValue &node) override;
    void visit(StringValue &node) override;
    void visit(ArrayValue &node) override;
    void visit(ObjectValue &node) override;
    void visit(Node &node) override;

private:
    int indent = 0;
    std::ostream &out;

    std::string indent_sequence;
    std::string get_indent() const;
};

#endif
