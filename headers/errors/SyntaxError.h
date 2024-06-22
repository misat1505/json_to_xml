#ifndef LEXICAL_ERROR_H
#define LEXICAL_ERROR_H

#include <exception>
#include <string>

class SyntaxError : public std::exception
{
public:
    SyntaxError(const std::string &message) : msg(message) {}

    const char *what() const noexcept override
    {
        return msg.c_str();
    }

private:
    std::string msg;
};

#endif