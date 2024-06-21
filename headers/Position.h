#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position {
    public:
        Position(int line, int column);
        int get_line() const;
        int get_column() const;
        void set_line(int line);
        void set_column(int column);
        std::string to_string() const;
    
    private:
        int line;
        int column;
};

#endif
