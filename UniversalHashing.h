#ifndef UNIVERSAL_HASHING_FUNCTION_H_
#define UNIVERSAL_HASHING_FUNCTION_H_

namespace UndavUniversalHashing {
	struct UniversalHashing;

	/*
	* Precondicion: Ninguna
	* Postcondicion: Crea una instancia de UniversalHashing que representa una funcion de la familia de hashing universal.
	* La funcion que se crea debe ser unica
	*/
	UniversalHashing* Create();

	/*
	* Precondicion: @universalHashing es una instancia valida de UniversalHashing
	* Postcondicion: Devuelve el codigo hashing de @key que corresponde a un numero mayor que cero y menor que @maximumHashCode
	* utilizando una funcion de familia de universal hashing
	*/
	int Hash(const UniversalHashing* universalHashing, const char* key, int maximumHashCode);

	/*
	 * Precondicion: @record es una instancia valida
	 * Postcondicion: Libera todos los recursos asociados de @record
	 */
	void Destroy(UniversalHashing* universalHashing);
}

#endif

#pragma once
