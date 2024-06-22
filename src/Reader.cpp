#include "../headers/Reader.h"

Reader::Reader(std::ifstream &in) : stream(in), position(Position(1, 0))
{
    this->current = (char)STX;
}

char Reader::get_current() const
{
    return this->current;
}

char Reader::get_next()
{
    if (this->stream.eof())
    {
        this->current = (char)ETX;
    }
    else
    {
        this->stream.get(this->current);
        if (this->stream.eof())
        {
            this->current = (char)ETX;
            return this->current;
        }
        if (this->current == '\n')
        {
            this->position.set_line(this->position.get_line() + 1);
            this->position.set_column(0);
        }
        else
        {
            this->position.set_column(this->position.get_column() + 1);
        }
    }
    return this->current;
}

Position Reader::get_position() const
{
    return this->position;
}