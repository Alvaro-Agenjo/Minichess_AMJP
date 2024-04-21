#pragma once

#include "Vector2D.h"
#include "Casilla.h"


class Tablero
{
private:

	Vector2D _dimension{};											// almacena las dimensiones del tablero
	Casilla** _tablero;												// matriz de casillas que forman el tablero

public:
	
	//Constructor - Destructor
	Tablero(Vector2D dim);											//constructor que reserva e inicializa la matriz de casillas
	~Tablero();														//destructor que elimina las casillas y los punteros usados para aceder a ellas

	//Getters
	inline Vector2D getDimension() { return _dimension; }
	inline Casilla** getTablero() { return _tablero; }
	//Setters

	//Otros métodos
	//void Refresh(const Jugador &j1, const Jugador& j2);				//actualizacion del estado de las casillas provocadas por movimientos de piezas

	friend class Interaccion;
	/********************************************
	* Funciones test, visualizacion en consola	*
	********************************************/

	void VerTablero();												//imprime en formato matriz de enteros la situacion del tablero numeros del 1-6 para cada tipo de pieza sinedo positivos las piezas del j1 y negatvos las del j2
	void VerCasillas();
};

