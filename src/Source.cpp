#include <iostream>
#include "Ajedrez.h"

using namespace std;

int main()
{
	Ajedrez game;
	game.printTablero() << endl;

	cout << game << endl;	
	
	return 0;
}