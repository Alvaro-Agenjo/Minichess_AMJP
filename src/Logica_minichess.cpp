#include <iostream>
#include "Jugador.h"
#include "Tablero.h"


constexpr int dimx = 8;
constexpr int dimy = 8;

int main()
{
	Tablero tablero({ dimx, dimy });
	Jugador jugador1({ 0,0 }, J1), jugador2({ dimx-1,dimy-1 }, J2);
	//tablero.Refresh(jugador1,jugador2);
	tablero.VerTablero();
	//jugdor1.Mover();
}