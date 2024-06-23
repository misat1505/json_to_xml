#include "../headers/ast/Node.h"

Node::Node(std::unique_ptr<AstValue> value, Position position) : value(std::move(value)), position(position) {}

void Node::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

std::unique_ptr<AstValue> &Node::get_value()
{
    return this->value;
}

Position Node::get_position() const
{
    return this->position;
}
