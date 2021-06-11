#include <iostream>
#include "Record.h"

using namespace UndavRecord;

struct Field {
	char* fieldValue;
};

struct UndavRecord::Record {
	Field* fields;
	int fieldsCount;
	int keyFieldPosition;
};

struct InfoField {
	int indexField;
	int endField;
	int fieldSize;
};

/*
* @csvRecord  es una cadena de caracteres en formato CSV, que tiene una cantidad de campos igual a @cantidadCampos
* Postcondicion: Devuelve un vector de tamanio igual a la cantidad de campos @cantidadCampos
*/
InfoField* CreateInfoFields(const char* csvRecord, int fieldsNumber);

int CountFields(const char* arrayRecord);

char* CreateFieldValue(const char* arrayRecord, InfoField* infoField);

UndavRecord::Record* UndavRecord::Create(char* csvRecord, int keyFieldPosition = 0) {
	Record* newRecord = new Record;
	newRecord->fieldsCount = CountFields(csvRecord);
	newRecord->fields = new Field[newRecord->fieldsCount];
	newRecord->keyFieldPosition = keyFieldPosition;
	InfoField* infoFields = CreateInfoFields(csvRecord, newRecord->fieldsCount);
	for(int i=0; i<newRecord->fieldsCount; i++){
		newRecord->fields[i].fieldValue = CreateFieldValue(csvRecord,i);
	}	
	return newRecord;
}

InfoField* CreateInfoFields(const char* csvRecord, int fieldNumber) {
	InfoField* infoField = new InfoField[fieldNumber];
	int startingIndex = 0;
	int endIndex = 0;
	for (int i = 0; i < fieldNumber; ++i)
	{
		infoField[i].indexField = startingIndex;
		for(endIndex = startingIndex; )
		//TODO
	}
	
}

int CountFields(const char* arrayRecord) {
	int numberOfSpacers = 0;
	int numberOfFields = 0;
	while(*arrayRecord != '\n' && *arrayRecord++ != '\0'){
		if(*arrayRecord == ','){
			numberOfSpacers++;
		}
		numberOfFields = numberOfSpacers + 1;
		return numberOfFields;
	}
}

char* CreateFieldValue(const char* arrayRecord, int fieldNumber) {
	InfoField* infoField = CreateInfoFields(arrayRecord,fieldNumber);
	char* fieldValue = new char[infoField->fieldSize + 1];
	for(int i = 0; i < infoField->fieldSize; ++i){
		fieldValue[i] = arrayRecord[infoField->indexField + i];
	}
	fieldValue[infoField->fieldSize] = '\0';
	delete infoField;

	return fieldValue;
}

int UndavRecord::GetFieldCount(const UndavRecord::Record* record) {
	return record->fieldsCount;
}

const char* UndavRecord::GetFieldValue(const UndavRecord::Record* record, int fieldPosition) {
	return (fieldPosition <= record->fieldsCount)? record->fields[fieldPosition].fieldValue: NULL;
}

const char* UndavRecord::GetKey(const UndavRecord::Record* record) {
	return record->fields[record->keyFieldPosition].fieldValue;
}

void UndavRecord::Destroy(UndavRecord::Record* record) {
	int size = record->fieldsCount;
	for (int i = 0; i < size; ++i)
	{
		delete[] record->fields[i].fieldValue;
	}
	
}