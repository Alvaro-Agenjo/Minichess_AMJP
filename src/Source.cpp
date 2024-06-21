#include <iostream>
#include "Ajedrez.h"

using namespace std;

int main()
{
	// Test dupicacion de tablero y jugadores
/*
	Tablero t, t2{ t };
	Jugador p(t.getTablero(), Color::Blanco);
	
	Jugador p2(p, t2.getTablero());
	

	t.ClearAmenazas();
	p.PosiblesMov(t.getTableroConst());
	p.ActualizarMovimiento(p.Movimiento(t.getTableroConst()) , t.getTablero());
*/

	// Test ajedrez
	
	Ajedrez game;
	bool continuar;
	
	do
	{
		//Rellenar amenazas
		game.Stateflow();
		game.printTablero() << endl;
		game.printAmenazas() << endl;

		//Seleccionar movimiento
		game.Stateflow();
		
		//Visualizacion movimiento
		game.Stateflow();
		game.printTablero() << endl;
		

		//Jaque?
		game.Stateflow();

		cout << "Desea continuar?" << endl;
		cout << "[0] No\t[1] Si" << endl;
		cin >> continuar;
		cout << endl << endl << endl;
	} while (continuar);
	
	return 0;
	
}