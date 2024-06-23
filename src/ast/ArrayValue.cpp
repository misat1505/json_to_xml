#include "../headers/ast/ArrayValue.h"

ArrayValue::ArrayValue(std::vector<std::unique_ptr<Node>> value) : value(std::move(value)) {}

void ArrayValue::accept(Visitor &visitor)
{
    visitor.visit(*this);

    for (auto &child : this->value)
    {
        child->accept(visitor);
    }
}
