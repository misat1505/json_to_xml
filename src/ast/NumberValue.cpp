#include "../headers/ast/NumberValue.h"

NumberValue::NumberValue(std::string value) : value(value) {}

void NumberValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}