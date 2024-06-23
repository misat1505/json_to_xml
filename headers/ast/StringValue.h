#ifndef STRING_VALUE_H
#define STRING_VALUE_H

#include <string>
#include "AstValue.h"
#include "Node.h"

class StringValue : public AstValue
{
public:
    StringValue(std::string value);
    std::string get_value() const;
    void accept(Visitor &visitor) override;

private:
    std::string value;
};

#endif
