#include <iostream>
#include "Jugador.h"


constexpr int dimx = 8;
constexpr int dimy = 8;

int main()
{
	Tablero tablero({ dimx, dimy });
	Jugador::crearTablero(&tablero);
	Jugador jugador1({ 0,0 }, J1), jugador2({ dimx-1,dimy-1 }, J2);
	
	
	tablero.VerTablero();
	//jugdor1.Mover();

/*    Modelo para inputs:
jugador1.Seleccionar_pieza();















*/
}