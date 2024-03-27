#pragma once

#include "Pieza.h"

class TABLERO
{
	int _dimX = 0, _dimY=0;
	Pieza*** _tablero;

public:

	//Contructores
	TABLERO(int DX, int DY);

	//getters
	inline Pieza* getOcupacion(int x, int y) { return _tablero[y][x]; }
	//setters
	void Colocar_Pieza(Pieza* p, int x, int y, bool inicio);

	//Otros métodos
	Pieza*** Crear_Tablero();
	void Liberar_Tablero();
	void Ver_Tablero_test();
};