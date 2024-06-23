#include "../headers/ast/TrueValue.h"

void TrueValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}