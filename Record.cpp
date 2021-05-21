#include <iostream>
#include "Record.h"

using namespace UndavRecord;

struct UndavRecord::Record {

};

UndavRecord::Record* UndavRecord::Create(char* csvRecord, int keyFieldPosition) {
	return 0;
}

int UndavRecord::GetFieldCount(const UndavRecord::Record* record) {
	return 0;
}

const char* UndavRecord::GetFieldValue(const UndavRecord::Record* record, int fieldPosition) {
	return 0;
}

const char* UndavRecord::GetKey(const UndavRecord::Record* record) {
	return 0;
}

void UndavRecord::Destroy(UndavRecord::Record* record) {

}