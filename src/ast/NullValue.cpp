#include "../headers/ast/NullValue.h"

void NullValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}