#include "Jugador.h"

#include <iostream>


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
	
	for (int i = 1; i < 8; i++)
	{
		if (j == J1)
		{
			Peon* p_aux = new Peon({ _posicion.x+1,i }, j);
			_misPiezas.push_back(p_aux);
		}
		else
		{
			Peon* p_aux = new Peon({ _posicion.x-1,i },j);
			_misPiezas.push_back(p_aux);
		} 
	}

	for (int i = 0; i < 2; i++)
	{
		Torre* t_aux = new Torre({ _posicion.x,i*7 }, j);
		_misPiezas.push_back(t_aux);
	}
}






void Jugador::Mover()
{
	int n = 0;
	do
	{
		n =Seleccionar_pieza();
	} while (n == -1);
	_misPiezas[n]->reglasMovimiento();
}




int Jugador::Seleccionar_pieza()		// en esta funcion se movera el cursor que indica la casilla seleccionada por el jugador y se devolvera la posicion en el vector de piezas de la pieza seleccionada
{
	// para realizar los test, se introduciran las coordenadas del cursor J1 por teclado
	std::cout << "Introduzca las coordenadas de la ficha que desea mover" << "\n";
	std::cin >> _posicion.x >> _posicion.y;

	for(int i= 0; i < _misPiezas.size();i++)			//reccorre el vector de piezas del jugador buscando una pieza cuyas coordenadas coincidan con las seleccionadas
	{
		if (_misPiezas[i]->getPosicion() == _posicion)
		{
			std::cout << "existe una pieza movible en esta posicion \n";
			return i;		// en caso de que coincidan (encuentre una pieza en la casilla) devuelve la posicion que ocupa dicha pieza en el vector
		}
	}
	std::cout << "No posees una pieza en esas coordenadas" << "\n";
	return -1;		// en caso de no encontrarla devuelve -1 como codigo de error
}


void Jugador::Comer(Jugador* Jugador_enemigo) {
	int k = Seleccionar_pieza();
	

	// ENCONTRAR LA PIEZA QUE COINCIDE CON LAS COORDS
	//
	//switch (_misPiezas[k]->_tpieza) {
	//case 1: //peon
	//	break;
	//case 2://torre
	//	break;
	//case 3://caballo
	//	break;
	//case 4://alfil
	//	break;
	//case 5://reina
	//	break;
	//case 6://rey
	//	break;
	//}

}

