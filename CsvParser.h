#ifndef CSVPARSER_H_
#define CSVPARSER_H_

#include "Record.h"
using UndavRecord::Record;

namespace UndavCsvParser {

	/*
	* Precondicion: @csvFileContent es una cadena de caracteres en formato csv donde el separador de registros es \n y el separador de campos es ,
	* @keyFieldPosition es un numero de campo valido
	* Postcondicion: Devuelve los registros de @csvFileContent esto es una vector de instancias validas del TDA Record
	*/
	UndavRecord::Record** GetRecords(const char* csvFileContent, int keyFieldPosition = 0);
}

#endif
#pragma once
