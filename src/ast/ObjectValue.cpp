#include "../headers/ast/ObjectValue.h"

ObjectValue::ObjectValue(std::map<std::string, std::unique_ptr<Node>> value) : value(std::move(value)) {}

void ObjectValue::accept(Visitor &visitor)
{
    visitor.visit(*this);

    for (auto &pair : value)
    {
        pair.second->accept(visitor);
    }
}
