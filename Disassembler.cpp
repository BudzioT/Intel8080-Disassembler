#include <iostream>
#include <cstdio>
#include <fstream>
#include "Disassembler8080.h"

int main() {
    std::cout << "File path: ";
    std::string path;
    std::cin >> path;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return 1;
    }

    file.seekg(0, std::ios::end);
    int size = static_cast<int>(file.tellg());
    unsigned char* buffer = new unsigned char[size];
    file.seekg(0, std::ios::beg);

    file.read(reinterpret_cast<char*>(buffer), size);
    file.close();

    int pc = 0;
    while (pc < size)
        pc += disassembler(buffer, pc);


    delete[] buffer;
    return 0;
}
