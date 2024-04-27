#include "Caballo.h"

Caballo::Caballo(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1)	_tpieza = 04;		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = -4;

	this->almacenarPiezaMemoria();
}

void Caballo::reglasMovimiento()
{
	validarCasilla({ _posicion.x + 2, _posicion.y + 3 });
	validarCasilla({ _posicion.x + 2, _posicion.y - 3 });
	validarCasilla({ _posicion.x + 3, _posicion.y + 2 });
	validarCasilla({ _posicion.x + 3, _posicion.y - 2 });
	validarCasilla({ _posicion.x - 2, _posicion.y + 3 });
	validarCasilla({ _posicion.x - 2, _posicion.y - 3 });
	validarCasilla({ _posicion.x - 3, _posicion.y + 2 });
	validarCasilla({ _posicion.x - 3, _posicion.y - 2 });
}