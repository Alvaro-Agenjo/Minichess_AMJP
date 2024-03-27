#include "Pieza.h"

Pieza::Pieza(int pos_x, int pos_y, Jugador jugador) :
	_coordX(pos_x), 
	_coordY(pos_y), 
	_jugador(jugador),
	seleccionada(false)
{}


