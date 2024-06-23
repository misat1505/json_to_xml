#ifndef VISITOR_H
#define VISITOR_H

class Node;
class AstValue;
class ArrayValue;
class NullValue;
class TrueValue;
class FalseValue;
class NumberValue;
class StringValue;
class ObjectValue;

class Visitor
{
public:
    virtual ~Visitor() = default;
    virtual void visit(NullValue &value) = 0;
    virtual void visit(TrueValue &value) = 0;
    virtual void visit(FalseValue &value) = 0;
    virtual void visit(NumberValue &value) = 0;
    virtual void visit(StringValue &value) = 0;
    virtual void visit(ArrayValue &value) = 0;
    virtual void visit(ObjectValue &value) = 0;
    virtual void visit(Node &value) = 0;
};

#endif