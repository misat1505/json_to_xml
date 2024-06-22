#include "../headers/ast/ArrayValue.h"

ArrayValue::ArrayValue(std::vector<std::unique_ptr<Node>> value): value(std::move(value)) {}
