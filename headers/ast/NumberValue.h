#ifndef NUMBER_VALUE_H
#define NUMBER_VALUE_H

#include <string>
#include "AstValue.h"

class NumberValue: public AstValue {
    public:
        NumberValue(std::string value);
    
    private:
        std::string value;
};

#endif
