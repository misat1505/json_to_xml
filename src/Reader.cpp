#include "../headers/Reader.h"
#include <iostream>

Reader::Reader(std::ifstream& in) : stream(in) {
    this->current = (char) STX;
    this->position = Position {0, 0};
}

char Reader::get_current() const {
    return this->current;
}

char Reader::get_next() {
    if (this->stream.eof()) {
        this->current = (char) ETX;
    } else {
        this->stream.get(this->current);
        if (this->stream.eof()) {
            this->current = (char) ETX;
            return this->current;
        }
        if (this->current == '\n') {
            this->position.row++;
            this->position.column = 0;
        } else {
            this->position.column++;
        }
    }
    return this->current;
}

Position Reader::get_position() const {
    return this->position;
}