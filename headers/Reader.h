#ifndef READER_H
#define READER_H

#include <fstream>
#include "Position.h"

#define STX 2
#define ETX 3

class Reader {
    public:
        Reader(std::ifstream& in);
        char get_current() const;
        char get_next();
        Position get_position() const;

    private:
        char current;
        std::ifstream& stream;
        Position position;
};

#endif