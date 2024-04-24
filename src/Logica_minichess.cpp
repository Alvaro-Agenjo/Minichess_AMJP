#include <iostream>
#include "Jugador.h"


constexpr int dimx = 8;
constexpr int dimy = 8;

int main()
{/*
	Tablero tablero({ dimx, dimy });
	Pieza::crearTablero(&tablero);
	Jugador jugador1({ 0,0 }, J1), jugador2({ dimx-1,dimy-1 }, J2);
	
	
	tablero.VerTablero();
	jugador1.Mover(); 
	tablero.VerCasillas();*/
	Tablero test({ 10,1 });
	Pieza::crearTablero(&test);
	Torre tor({ 0,0 }, J1);
	Peon({ 3,0 }, J2);
	Torre torr({ 5,0 }, J2);
	test.VerTablero();
	tor.reglasMovimiento();
	test.VerCasillas();
/*    Modelo para inputs:
jugador1.Seleccionar_pieza();















*/
}