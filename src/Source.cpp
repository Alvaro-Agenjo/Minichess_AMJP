#include <iostream>
#include "Ajedrez.h"

using namespace std;

int main()
{
	Ajedrez game;
	cout << game << endl;
	game.printTablero() << endl;
	game.printAmenazas() << endl;
	
	
	game.Stateflow();
	cout << game << endl;
	game.printTablero() << endl;
	game.printAmenazas() << endl;
	
	game.Stateflow();

	return 0;
	
}