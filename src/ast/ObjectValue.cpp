#include "../headers/ast/ObjectValue.h"

ObjectValue::ObjectValue(std::map<std::string, std::unique_ptr<Node>> value) : value(std::move(value)) {}
