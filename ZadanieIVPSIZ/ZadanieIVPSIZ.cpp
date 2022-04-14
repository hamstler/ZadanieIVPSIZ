// TaskIV.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>

using namespace std;

void createFile(const string name, const int count, const char value) {
    int i = 0;
    ofstream MyFile(name);

    for (i = 0; i < count; i++) {
        MyFile << value;

    }

};

void createFileRandom(const string name, const int count, const char value1, const char value2) {
    int i = 0;
    ofstream MyFile(name);

    for (i = 0; i < 90; i++) {
        MyFile << value1;

    }
    for (i = 90; i < count; i++) {
        MyFile << value2;

    }
};

int main()
{
    cout << "Hello World!\n";
    //createFile("100bytes_1.bin", 100, 0x55);
    //createFile("100bytes_2.bin", 100, 0x55);
    //createFileRandom("100bytes_3_changed_by_10_bytes.bin", 100, 0x55, 0x45);
    //createFile("400MB_1.bin", 419430400, 0x55);
    //createFile("400MB_2.bin", 419430400, 0x50);
    cout << "wykonano create file";
}

