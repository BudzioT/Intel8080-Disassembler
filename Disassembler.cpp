#include <iostream>
#include <cstdio>
#include <fstream>
#include "Disassembler8080.h"

int main() {
    std::cout << "File path: ";
    std::string path;
    std::cin >> path;

    FILE* file = fopen(path.c_str(), "rb");
    if (!file) {
        std::cerr << "Error: file not found" << std::endl;
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    unsigned char* buffer = new unsigned char[size];
    fseek(file, 0, SEEK_SET);

    fread(buffer, size, 1, file); // read the entire file into the buffer
    fclose(file);

    int pc = 0;
    while (pc < size)
        pc += disassembler(buffer, pc);


    delete[] buffer;
    return 0;
}
