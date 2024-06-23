#ifndef NUMBER_VALUE_H
#define NUMBER_VALUE_H

#include <string>
#include "AstValue.h"
#include "Node.h"

class NumberValue : public AstValue
{
public:
    NumberValue(std::string value);
    std::string get_value() const;
    void accept(Visitor &visitor) override;

private:
    std::string value;
};

#endif
