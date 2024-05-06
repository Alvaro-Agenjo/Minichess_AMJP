#include "Jugador.h"

/********************************************************************************************
*		librerias para realizar test, serán eliminadas al incorporar interfaz gráfica		* 
********************************************************************************************/

#include <iostream>

Jugador::Jugador(Vector2D pos, Player j) :
	_posicion(pos),
	_jugador(j)
{
	// creacion de los distintos objetos pieza:subtipo
	// buscar solucion si es posible para evitar la inclusion de las librerias de Pieza:subtipo en jugador
	
	for (int i = 0; i < 8; i++)
	{
		if (j == J1)
		{
			Peon* p_aux = new Peon({ _posicion.x+1,i }, j);
			_misPiezas.push_back(p_aux);
			Interaccion::almacenarEnTablero(*p_aux, _tablero);
		}
		else
		{
			Peon* p_aux = new Peon({ _posicion.x-1,i },j);
			_misPiezas.push_back(p_aux);
			Interaccion::almacenarEnTablero(*p_aux, _tablero);
		} 
	}

	for (int i = 0; i < 2; i++)
	{
		Torre* t_aux = new Torre({ _posicion.x,i*7 }, j);
		_misPiezas.push_back(t_aux);
		Interaccion::almacenarEnTablero(*t_aux, _tablero);
	}
}

Tablero* Jugador::_tablero = 0;

void Jugador::crearTablero(Tablero* tab)
{
	 _tablero = tab; 
}

void Jugador::Mover()
{
	int n=  Seleccionar_pieza();
}

int Jugador::Seleccionar_pieza()		// en esta funcion se movera el cursor que indica la casilla seleccionada por el jugador y se devolvera la posicion en el vector de piezas de la pieza seleccionada
{
	// para realizar los test, se introduciran las coordenadas del cursor J1 por teclado
	std::cin >> _posicion.x >> _posicion.y;

	for(int i= 0; i <= _misPiezas.size();i++)			//reccorre el vector de piezas del jugador buscando una pieza cuyas coordenadas coincidan con las seleccionadas
	{
		if (_misPiezas[i]->getPosicion() == _posicion)
		{
			return i;		// en caso de que coincidan (encuentre una pieza en la casilla) devuelve la posicion que ocupa dicha pieza en el vector
		}
	}
	return -1;		// en caso de no encontrarla devuelve -1 como codigo de error
}


