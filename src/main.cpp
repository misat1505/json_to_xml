#include <iostream>
#include <fstream>
#include <exception>
#include "../headers/Converter.h"

int main(int argc, char **argv)
{
    std::ifstream file(argv[1]);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    try
    {
        Converter converter(file);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    file.close();

    return 0;
}