#pragma once

#include "Tablero.h"
#include <vector>

enum class Jugador
{
	Jugador_1 = 1,
	Jugador_2
};

class Pieza
{
	bool seleccionada;
	
	
	
protected:
	int _coordX, _coordY;
	Jugador _jugador;
	std::vector<int[2]>_posibles_movimientos;

public:

	// Constructores
	Pieza(int pos_x, int pos_y, Jugador jugador);

	//Getters
	inline int getCoord_X() { return _coordX; }
	inline int getCoord_Y() { return _coordY; }
	inline Jugador getJugador() { return _jugador; }
	virtual void getPieza() = 0;

	//Setters
	inline void setCoord(int x, int y) { _coordX = x; _coordY = y; }
	//Otros métodos
	virtual void Comprobar_posibles_casillas( TABLERO& tab, int dimx, int dimy) = 0;
};