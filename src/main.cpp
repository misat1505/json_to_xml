#include <iostream>
#include <fstream>
#include <exception>
#include "../headers/Converter.h"

int main(int argc, char **argv)
{
    std::ifstream input_file(argv[1]);

    if (!input_file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::ofstream output_file(argv[2]);

    if (!output_file.is_open())
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    try
    {
        JSON_TO_XML::convert(input_file, output_file, "  ");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    input_file.close();
    output_file.close();

    return 0;
}