#include "../headers/ast/FalseValue.h"

void FalseValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}