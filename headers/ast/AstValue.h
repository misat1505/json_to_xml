#ifndef AST_VALUE_H
#define AST_VALUE_H

// #include "../Visitor.h"
class Visitor;

class AstValue
{
public:
    virtual void accept(Visitor &visitor) = 0;
};

#endif
