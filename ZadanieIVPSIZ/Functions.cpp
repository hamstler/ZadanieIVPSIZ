#include "Functions.h"
using namespace std;

void printSize(const string& address) {
    fstream motd(address.c_str(), ios::binary | ios::in | ios::ate);
    if (motd) {
        fstream::pos_type size = motd.tellg();
        cout << size << "B";
    }
    else {
        perror(address.c_str());
    }
}

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

    ifstream file1 (FirstFile, ios::binary);
    ifstream file2 (SecondFile, ios::binary);
    long long int iloscBitow = 0, ber = 0;
    char a{};
    char b{};

    Starting = clock();

    while (!file1.eof())
    {
        file1 >> a;
        file2 >> b;

        if (file1.eof()) { break; } // dodatkowe zabezpieczenie przed znakiem konca pliku ;]

        iloscBitow = iloscBitow + 8;
        ber = calculateHamingDistance(a, b) + ber;

    }

    End = clock();
    cout << "Time: " << FormattedTimestamp() << endl;
    cout << "Size of file 1 "; printSize(FirstFile);
    cout << "\nSize of file 2 "; printSize(SecondFile);
    cout << "\nDifferent bits : " << ber << endl;
    cout << "Calc time : " << OperationTimeCalc(Starting, End) << endl;

    //Open log file
    ofstream log;
    log.open("log.txt", ios_base::app);


    if (log.good())
    {
        log << "Time: " << FormattedTimestamp() << endl;
        log << "Size of file 1 "; printSize(FirstFile);
        log << "\nSize of file 2 "; printSize(SecondFile);
        log << "\nDifferent bits : " << ber << endl;
        log << "Calc time : " << OperationTimeCalc(Starting, End) << endl;
        log << "End calculation" << endl;
        log.close();


    }
    else
        cout << "There is a problem with file log";"/n";
}
