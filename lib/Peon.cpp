#include "Peon.h"

Peon::Peon(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1)	_tpieza = 1;		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = -1;
}