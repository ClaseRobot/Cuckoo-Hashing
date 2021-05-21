#include <iostream>
#include "UniversalHashing.h"
#include "CsvParser.h"
#include "Record.h"

using std::cout;
using std::endl;
using namespace UndavCsvParser;
using namespace UndavRecord;
using namespace UndavUniversalHashing;

void ExecuteHashingDemo();
void ShowHashingDemo(const UniversalHashing* hashFunction, const char** keys, int length, int m);
void ExecuteCsvParserDemo();
void Show(const Record* record);

int main()
{
    ExecuteHashingDemo();
    ExecuteCsvParserDemo();
    return 0;
}

void ExecuteHashingDemo() {
    UniversalHashing* hashFunction = Create();
    const int countOfKeys = 10;
    const char* keys[countOfKeys] = { "Argentina", "Bolivia", "Brasil", " Uruguay", "Paraguay", "Ecuador", "Peru", "Colombia", "Venezuela", "El Salvador" };
    ShowHashingDemo(hashFunction, keys, countOfKeys, countOfKeys);
    Destroy(hashFunction);
}

void ShowHashingDemo(const UniversalHashing* hashFunction, char** keys, int length, int m) {
    cout << "Hashing demo" << endl;
    for (int i = 0; i < length; ++i) {
        cout << "h(" << keys[i] << ") = " << Hash(hashFunction, keys[i], m) << endl;
    }
}

void ExecuteCsvParserDemo() {
    int recordLength = 4;
    const char* csvFileContent = "C++,NivelMedio\nJava,NivelMedioAlto\nPython,AltoNivel\nAssembler Mip32,BajoNivel";
    Record** records = GetRecords(csvFileContent);
    for (int i = 0; i < recordLength; i++) {
        Show(records[i]);
        cout << endl;
        Destroy(records[i]);
    }

    delete[]records;
}

void Show(const Record* record) {
    if (GetFieldCount(record) > 0) {
        cout << GetFieldValue(record, 0);
        for (int recordNumber = 1; recordNumber < GetFieldCount(record); ++recordNumber) {
            cout << "," << GetFieldValue(record, recordNumber);
        }
    }
}
