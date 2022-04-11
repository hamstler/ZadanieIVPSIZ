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
int main()
{
    cout << "Hello World!\n";
    //createFile("400MB.bin", 419430400, 0x55);
    cout << "wykonano create file";
}

