#include "../headers/ast/ArrayValue.h"

ArrayValue::ArrayValue(std::vector<std::unique_ptr<Node>> value) : value(std::move(value)) {}

const std::vector<std::unique_ptr<Node>> &ArrayValue::get_value() const
{
    return this->value;
}

void ArrayValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}
