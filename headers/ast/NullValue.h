#ifndef NULL_VALUE_H
#define NULL_VALUE_H

#include "AstValue.h"
#include "Node.h"

class NullValue : public AstValue
{
public:
    NullValue() = default;
    void accept(Visitor &visitor) override;
};

#endif
