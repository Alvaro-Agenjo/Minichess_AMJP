#include "Torre.h"


Torre::Torre(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1)	_tpieza = 02;		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = -2;            //se pone un cero en el 02 para que siempre sean dos bits

	this->almacenarPiezaMemoria();
}

void Torre::reglasMovimiento()
{
	int n = 1;
	bool rep = true;

	do
	{
		rep = validarCasilla({ _posicion.x + n, _posicion.y });
		n++;
	} while (rep);

	n = 1;
	do
	{
		rep = validarCasilla({ _posicion.x, _posicion.y + n });
		n++;
	} while (rep);

	n = 1;
	do
	{
		rep = validarCasilla({ _posicion.x - n, _posicion.y });
		n++;
	} while (rep);
	
	n = 1;
	do
	{
		rep = validarCasilla({ _posicion.x, _posicion.y-n });
		n++;
	} while (rep);
}
