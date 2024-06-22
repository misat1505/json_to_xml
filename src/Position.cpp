#include "../headers/Position.h"

Position::Position(int line, int column) : line(line), column(column) {}

int Position::get_line() const
{
    return this->line;
}

int Position::get_column() const
{
    return this->column;
}

void Position::set_line(int line)
{
    this->line = line;
}

void Position::set_column(int column)
{
    this->column = column;
}

std::string Position::to_string() const
{
    return "Line: " + std::to_string(this->line) + ", Column: " + std::to_string(this->column);
}
