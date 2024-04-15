#include <iostream>
#include "Jugador.h"
#include "Tablero.h"


constexpr int dimx = 8;
constexpr int dimy = 8;

int main()
{
	Tablero tablero(Vector2D{ dimx, dimy });
	tablero.VerTablero();
	Jugador jugdor1(Vector2D{ 0,0 }, J1);
	tablero.Refresh(jugdor1,jugdor1);
	tablero.VerTablero();
	//jugdor1.Mover();
}