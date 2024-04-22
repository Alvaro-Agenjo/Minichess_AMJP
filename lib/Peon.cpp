#include "Peon.h"

Peon::Peon(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1) _tpieza =  01;		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = -1;

	this->almacenarPiezaMemoria();

}
void Peon::reglasMovimiento()
{
	validarCasilla(_posicion.y + 1);
	validarCasilla(_posicion.y + 2);
}
void Peon::ver_opciones(Pieza* a_mover) {
	
}