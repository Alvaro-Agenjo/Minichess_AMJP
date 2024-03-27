#include <iostream>
#include <vector>
#include "../lib/Pieza.h"
#include "../lib/Peon.h"
#include "../lib/Tablero.h"

constexpr int filas = 4;
constexpr int columnas = 2;

int main() 
{
	TABLERO tablero(columnas, filas);
	tablero.Ver_Tablero_test();
	
	for (int n = 0; n < 2; n++)
	{
		Peon* aux = new Peon(0, 0, Jugador::Jugador_1);
		tablero.Colocar_Pieza(aux, n, 1, true);
	}
	Peon *p1 = new Peon(0, 0, Jugador::Jugador_1);
	tablero.Colocar_Pieza(p1,2,1,true);

	p1->Comprobar_posibles_casillas()
	
	
	tablero.Ver_Tablero_test();
	tablero.Liberar_Tablero();


	
 }