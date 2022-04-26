// TaskIV.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "Functions.h"


int main(int argc, char* argv[])
{

    /* createFile("100bytes_1.bin", 100, 0x55);
    createFile("100bytes_2.bin", 100, 0x55);
    createFileRandom("100bytes_3_changed_by_10_bytes.bin", 100, 0x55, 0x45);
    createFile("400MB_1.bin", 419430400, 0x55);
    createFile("400MB_2.bin", 419430400, 0x50);
    cout << "wykonano create file";
    */
    std::cout << "BER Checker!" << std::endl;
    std::cout << "argc = : " << argc << std::endl;

    int iter = 0;
    for (iter = 0; iter < argc; iter++) {
        std::cout << "argv[" << iter << "] =" << argv[iter]<<std::endl;
    }

    CompareFunction(argv[1], argv[2]);

}

