#include "../headers/ast/StringValue.h"

StringValue::StringValue(std::string value) : value(value) {}

void StringValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}