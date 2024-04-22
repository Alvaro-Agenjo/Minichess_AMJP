#include "Peon.h"
#include "Vector2D.h"

Peon::Peon(Vector2D pos, Player j) :
	Pieza(pos, j)
{
	if (j == J1) _tpieza =  01;		//modifica el indicador usado para imprimir por consola, será eliminado al implementar la interfaz gráfica
	else _tpieza = -1;

	this->almacenarPiezaMemoria();

}
void Peon::reglasMovimiento()
{
	Vector2D vaux;
	vaux.x = _posicion.y;
	vaux.y = _posicion.x;
	vaux.y += 1;
	validarCasilla(vaux);
	vaux.y += 1;
	validarCasilla(vaux);
}
void Peon::ver_opciones(Pieza* a_mover) {
	
}