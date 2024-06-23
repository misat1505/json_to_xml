#ifndef ARRAY_VALUE_H
#define ARRAY_VALUE_H

#include <vector>
#include <memory>
#include <string>
#include "Node.h"
class Node;

class ArrayValue : public AstValue
{
public:
    ArrayValue(std::vector<std::unique_ptr<Node>> value);
    void accept(Visitor &visitor) override;

private:
    std::vector<std::unique_ptr<Node>> value;
};

#endif
