#include "Peon.h"

Peon::Peon(Casilla* coord, Color col) :
	Pieza(coord, col, t_pieza::PEON),
	_primermov(true)
{}


void Peon::PosiblesMov(const std::vector<Casilla>& tab)
{
	//indica si el peon puede o no avanzar una casilla
	bool continuar = false;

	//Peon movimiento hacia delante
	Casilla aux = *_myCasilla;
	aux = getCasilla_copia(aux, Vector2D{ (int)_color, 0 }, tab);
	continuar = validarCasilla(aux, false);

	if (continuar && _primermov)	//comprueba si es el primer movimiento y se puede mover una casilla (evita que atraviese peones)
	{
		aux = getCasilla_copia(aux, Vector2D{ (int)_color, 0 }, tab);
		validarCasilla(aux, false);
	}
	//Peon captura delante-abajo
	aux = getCasilla_copia(*_myCasilla, Vector2D{ (int)_color, -1 }, tab);
	validarCasilla(aux, true);

	//Peon captura delante-arriba
	aux = getCasilla_copia(*_myCasilla, Vector2D{ (int)_color, 1 }, tab);
	validarCasilla(aux, true);
}

void Peon::ActualizarTablero(std::vector<Casilla>& tab)
{
	Vector2D posicion{};
	for (const Casilla &c : _posiblesMov)
	{
		posicion = c.getPosicion();
		if (c.getComer())
		{
			tab[posicion.x + 8 * posicion.y].setAmenaza(true);
		}
	}
}

bool Peon::ActualizarPosicion(std::vector<Casilla>& tab, int indice_c, bool sound)
{
	_primermov = false;
	calcularMovimiento(_myCasilla->getPosicion(), tab[indice_c].getPosicion(), 0, sound);
	_myCasilla->setOcupacion(Dominio::Vacio);
	_myCasilla = &tab[indice_c];
	_myCasilla->setOcupacion(static_cast<Dominio>(_color));

	return ComprobarCoronacion(tab[indice_c].getPosicion().x);
}
bool Peon::ComprobarCoronacion(int coordx)
{
	if (_color == Color::Blanco && coordx == 7) return true;
	else if (_color == Color::Negro && coordx == 0) return true;
	return false;
}


std::ostream& Peon::operator<< (std::ostream& o) const
{
	if (_color == Color::Blanco)
		o << "P ";
	else
		o << "p ";
	return o;
}

bool Peon::validarCasilla(Casilla destino, bool com)
{
	// devuelve true si la casilla es valida
	Casilla aux = destino;
	Dominio ocupacion = destino.getOcupacion();

	if (destino.getPosicion() == out_of_bounds)	return false;	//si el destino no se encuentra en el tablero
	else if (ocupacion == this->_color) return false;	//si el destino lo ocupa una pieza aliada
	else if (!com && ocupacion != Dominio::Vacio) return false;	//si el destino está ocupado y no es un movimiento de captura
	else if (com && ocupacion == Dominio::Vacio) return false;	//si el destino está vacio y es un movimiento de captura
	
	if (!com)	//movimiento 
		aux.setMover(true);
	
	else	//captura
	{
		aux.setMover(true);
		aux.setComer(true);
	}
	_posiblesMov.push_back(aux);
	return true;
}