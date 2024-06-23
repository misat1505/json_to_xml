#ifndef TRUE_VALUE_H
#define TRUE_VALUE_H

#include "AstValue.h"
#include "Node.h"

class TrueValue : public AstValue
{
public:
    TrueValue() = default;
    void accept(Visitor &visitor) override;
};

#endif
