#include "Torre.h"


Torre::Torre(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1)	_tpieza = " 2";		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = "-2";
}
