#ifndef OBJECT_VALUE_H
#define OBJECT_VALUE_H

#include <map>
#include <memory>
#include <string>
#include "Node.h"

class ObjectValue : public AstValue
{
public:
    ObjectValue(std::map<std::string, std::unique_ptr<Node>> value);
    void accept(Visitor &visitor) override;

private:
    std::map<std::string, std::unique_ptr<Node>> value;
};

#endif
