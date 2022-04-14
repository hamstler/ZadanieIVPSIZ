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