#include "../headers/ast/ObjectValue.h"

ObjectValue::ObjectValue(std::map<std::string, std::unique_ptr<Node>> value) : value(std::move(value)) {}

const std::map<std::string, std::unique_ptr<Node>> &ObjectValue::get_value() const
{
    return this->value;
}

void ObjectValue::accept(Visitor &visitor)
{
    visitor.visit(*this);
}
