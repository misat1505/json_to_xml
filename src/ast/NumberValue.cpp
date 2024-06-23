#include "../headers/ast/NumberValue.h"

NumberValue::NumberValue(std::string value) : value(value) {}

std::string NumberValue::get_value() const
{
    return this->value;
}

void NumberValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}