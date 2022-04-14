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

double OperationTimeCalc(time_t time1, time_t time2)
{
    return (((double)time2 - time1) / CLOCKS_PER_SEC);
}

uint8_t calculateHamingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2;
    uint8_t setBits = 0;

    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }

    return setBits;
}

void CompareFunction(const char* FirstFile, const char* SecondFile) {
    time_t Starting;
    time_t End;

    ifstream file1, file2;

    int bits = 0;
    int bits2 = 0;

    file1.open(FirstFile, ios::binary);
    file1.read((char*)&bits, sizeof(bits));
    file1.close();

    file2.open(SecondFile, ios::binary);
    file2.read((char*)&bits2, sizeof(bits2));
    file2.close();

    Starting = clock();
    uint8_t ber = calculateHamingDistance(bits, bits2);
    End = clock();
    cout << "Compared bits :" << bits + bits2;"\n";
    cout << "Different bits : " << ber; "\n";
    cout << "Calc time : " << OperationTimeCalc(Starting, End);"\n";

        //Open log file
        ofstream log;
        log.open("log.txt");
        log << "test";

        
}

