#include <iostream>
#include "Ajedrez.h"

using namespace std;

int main()
{
	Ajedrez game;
	for (int n = 0; n < 15; n++)
	{
		game.Stateflow();
		game.printTablero() << endl;
		game.printAmenazas() << endl;
	}


	Peon p1{new Casilla, Color::Negro};
	
	
	

	return 0;
	
}