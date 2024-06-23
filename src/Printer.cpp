#include "../headers/Printer.h"

Printer::Printer(std::ostream &out, std::string indent_sequence) : out(out), indent_sequence(indent_sequence) {}

void Printer::visit(FalseValue &node)
{
    out << this->get_indent() << "false\n";
}

void Printer::visit(NullValue &node)
{
    out << this->get_indent() << "null\n";
}

void Printer::visit(TrueValue &node)
{
    out << this->get_indent() << "true\n";
}

void Printer::visit(NumberValue &node)
{
    out << this->get_indent() << node.get_value() << "\n";
}

void Printer::visit(StringValue &node)
{
    out << this->get_indent() << node.get_value() << "\n";
}

void Printer::visit(ArrayValue &node)
{
    int idx = 0;

    for (auto &child : node.get_value())
    {
        out << this->get_indent() << "<" << std::to_string(idx) << ">\n";
        this->indent++;
        child->accept(*this);
        this->indent--;
        out << this->get_indent() << "</" << std::to_string(idx) << ">\n";
        idx++;
    }
}

void Printer::visit(ObjectValue &node)
{
    for (const auto &pair : node.get_value())
    {
        out << this->get_indent() << "<" << pair.first << ">\n";
        this->indent++;
        pair.second->accept(*this);
        this->indent--;
        out << this->get_indent() << "</" << pair.first << ">\n";
    }
}

void Printer::visit(Node &node)
{
    if (node.get_value())
    {
        node.get_value()->accept(*this);
    }
}

std::string Printer::get_indent() const
{
    std::string result;

    for (int i = 0; i < this->indent; ++i)
    {
        result += indent_sequence;
    }

    return result;
}
