#ifndef STRING_VALUE_H
#define STRING_VALUE_H

#include <string>
#include "AstValue.h"

class StringValue: public AstValue {
    public:
        StringValue(std::string value);
    
    private:
        std::string value;
};

#endif
