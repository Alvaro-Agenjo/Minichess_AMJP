#include "Pieza.h"

Pieza::Pieza(Vector2D pos, Player j) :     //Constructor común a todas las piezas, inicializa posicion y pertenencia a jugador
	_posicion(pos),
	_jugador(j)
{}

Tablero* Pieza::_tab;

void Pieza::crearTablero(Tablero* t)
{
	_tab = t;
}

void Pieza::almacenarPiezaMemoria()
{
	_tab->getTablero()[_posicion.y][_posicion.x].setOcupacion(_tpieza); //se ha movido la clase interaccion y sus funciones las adopta pieza, que tiene una referencia al tablero
	_tab->getTablero()[_posicion.y][_posicion.x].setPuedeMover(0);
}

bool Pieza::validarCasilla(Vector2D coord)
{
	Casilla& c = _tab->getTablero()[coord.y][coord.x];		//enlace a direccion de casilla a comprobar
	Vector2D negativo{ -1,-1 };
	Vector2D dim = _tab->getDimension();
	static bool primerapieza = 1, segundapieza = 0;			//detector de piezas clavadas, se puede mover hasta la primera pieza,a esta se la puede comer, y amenaza todo hasta encontrarse una segunda pieza
	if (negativo < coord && coord < dim)		//comprobar que la posicion se encuentra dentro de los límites del tablero
	{

		if (c.getOcupacion() == 0)                       //comprueba si hay alguien en la casilla, en este caso lo está
		{
			c.setAtacada(!primerapieza && !segundapieza); //si no ha detectado ninguna pieza no esta atacada 
			c.setPuedeMover(primerapieza); //se puede mover a esa dado que no se ha encontrado la primera pieza todavía
			return true;
		}
		else if ((c.getOcupacion() < 0 && _jugador == J1) || (c.getOcupacion() > 0 && _jugador == J2))       //si lo hay comprueba que jugador está ahí situado
		{                                           //si la pieza en dichas coords es enemiga se habilita la posibilidad de comer (true), ocupacion + J1 y ocupacion - J2
			if (!primerapieza) { segundapieza = 1; }
			c.setAtacada(primerapieza || segundapieza);
			c.setPuedeMover(primerapieza);
			primerapieza = 0;
			return true;
		}
		else                   // si en la casilla hay una ficha aliada se prohibe el movimiento y el retorno es (false)
		{
			primerapieza = 1;
			segundapieza = 0;
			return false;
		}
	}
	else
	{
		primerapieza = 1;
		segundapieza = 0;
		return false;
	}

}
