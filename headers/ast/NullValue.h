#ifndef NULL_VALUE_H
#define NULL_VALUE_H

#include "AstValue.h"

class NullValue: public AstValue {
    public:
        NullValue() = default;
};

#endif
