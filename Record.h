#ifndef RECORD_H_
#define RECORD_H_

namespace UndavRecord {
	struct Record;

	/*
	 * Precondicion: @csvRecord es una cadena de caracteres en formato CSV. @keyFieldPosition es un numero de campo valido
	 * Postcondicion: Devuelve una instancia valida de Record que representa el registro csv de @csvRecord donde la clave
	 * corresponde al campo en la posicion @keyFieldPosition
	 */
	Record* Create(char* csvRecord, int keyFieldPosition = 0);

	/*
	* Precondicion: @record es una instancia valida
	* Postcondicion: Devuelve la cantidad de campos que tiene @record
	*/
	int GetFieldCount(const Record* record);

	/*
	 * Precondicion: @record es una instancia valida
	 * Postcondicion: Si @fieldPosition es una posicion valida devuelve el valor del campo correspondiente. Caso contrario devuelve NULL
	 */
	const char* GetFieldValue(const Record* record, int fieldPosition);

	/*
	 * Precondicion: @record es una instancia valida
	 * Postcondicion: Devuelve el valor de la clave de @record
	 */
	const char* GetKey(const Record* record);

	/*
	 * Precondicion: @record es una instancia valida
	 * Postcondicion: Libera todos los recursos asociados de @record
	 */
	void Destroy(Record* record);
}

#endif
#pragma once
