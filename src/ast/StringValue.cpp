#include "../headers/ast/StringValue.h"

StringValue::StringValue(std::string value) : value(value) {}

std::string StringValue::get_value() const
{
    return this->value;
}

void StringValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}