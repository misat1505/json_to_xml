#ifndef FALSE_VALUE_H
#define FALSE_VALUE_H

#include "AstValue.h"
#include "Node.h"

class FalseValue : public AstValue
{
public:
    FalseValue() = default;
    void accept(Visitor &visitor) override;
};

#endif
