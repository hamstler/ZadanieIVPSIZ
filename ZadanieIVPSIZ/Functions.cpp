#include "Functions.h"
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

double Timestamp()
{
    chrono::system_clock::time_point now = chrono::system_clock::now();
    return chrono::system_clock::to_time_t(now);
}

string FormattedTimestamp()
{
    time_t timestamp = Timestamp();
    struct tm timeinfo;
    char buffer[80];
    time(&timestamp);
    localtime_s(&timeinfo, &timestamp);
    strftime(buffer, 80, "%H:%M:%S", &timeinfo);
    string str(buffer);
    return str;
}



void CompareFunction(const char* FirstFile, const char* SecondFile) {
    time_t Starting;
    time_t End;

    ifstream file1, file2;
    uint8_t size = 0;
    if (file1.good())
    {
        file1.open(FirstFile, ios::binary);
        file1.read((char*)&size, sizeof(size));
        file1.close();
    }
    else 
    {
        cout << "Error with File 1" << endl;
    }
       

    uint8_t size2 = 0;
    if (file2.good())
    {
        file2.open(SecondFile, ios::binary);
        file2.read((char*)&size2, sizeof(size2));
        file2.close();
    }
    else
    {
        cout << "Error with File 2" << endl;
    }
    cout << endl;
    cout << "Size: " << (int)size << endl;
    cout << "Size2: " << (int)size2 << endl;

    Starting = clock();
    uint8_t ber = calculateHamingDistance(size, size2);
    End = clock();
    cout << "Time: " << FormattedTimestamp() << endl;
    cout << "Compared bits :" << (int)size + size2 << endl;
    cout << "Different bits : " << (int)ber << endl;
    cout << "Calc time : " << OperationTimeCalc(Starting, End) << endl;

    //Open log file
    ofstream log;
    log.open("log.txt", ios_base::app);


    if (log.good())
    {
        log << "Time: " << FormattedTimestamp() << endl;
        log << "Compared bits: " << (int)size + size2 << endl;
        log << "Different bits: " << (int)ber << endl;
        log << "Calculation time: " << OperationTimeCalc(Starting, End) << endl;
        log << "End calculation" << endl;
        log.close();


    }
    else
        cout << "There is a problem with file log";"/n";
}
