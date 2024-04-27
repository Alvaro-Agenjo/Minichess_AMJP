#include "Alfil.h"


Alfil::Alfil(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1)	_tpieza = 03;		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = -3;

	this->almacenarPiezaMemoria();
}

void Alfil::reglasMovimiento()
{
	int n = 1;
	bool rep = true;

	do
	{
		rep = validarCasilla({ _posicion.x + n, _posicion.y+n });
		n++;
	} while (rep);

	n = 1;
	do
	{
		rep = validarCasilla({ _posicion.x-n, _posicion.y + n });
		n++;
	} while (rep);

	n = 1;
	do
	{
		rep = validarCasilla({ _posicion.x - n, _posicion.y -n});
		n++;
	} while (rep);

	n = 1;
	do
	{
		rep = validarCasilla({ _posicion.x+n, _posicion.y - n });
		n++;
	} while (rep);
}
