#ifndef NODE_H
#define NODE_H

#include <memory>
#include "AstValue.h"
#include "../Position.h"

class Node {
    public:
        Node(std::unique_ptr<AstValue> value, Position position);
        std::unique_ptr<AstValue>& get_value();
        Position get_position() const;
    
    private:
        std::unique_ptr<AstValue> value;
        Position position;
};

#endif
