#include <iostream>
#include "Tablero.h"
#include "Torre.h"

using namespace std;

int main()
{
	Tablero tab;
	Torre t1(&tab._tablero[0], Color::Blanco);
	Torre t2(&tab._tablero[16], Color::Negro);

	t1.PosiblesMov(tab._tablero);
	return 0;
}