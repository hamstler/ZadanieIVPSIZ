// TaskIV.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include "FileAdd.h"

using namespace std;



int main()
{
    cout << "Hello World!\n";
    //createFile("100bytes_1.bin", 100, 0x55);
    createFile("100bytes_2.bin", 100, 0x55);
    //createFileRandom("100bytes_3_changed_by_10_bytes.bin", 100, 0x55, 0x45);
    //createFile("400MB_1.bin", 419430400, 0x55);
    //createFile("400MB_2.bin", 419430400, 0x50);
    cout << "wykonano create file";
}

