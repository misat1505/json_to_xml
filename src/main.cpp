#include <iostream>
#include <fstream>
#include "../headers/Converter.h"

int main(int argc, char** argv) {
    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    Converter converter(file);

    file.close();

    return 0;
}