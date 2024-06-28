#include "Peon.h"

Peon::Peon(Casilla* coord, Color col) :
	Pieza(coord, col, t_pieza::PEON),
	_primermov(true)
{}


void Peon::PosiblesMov(const std::vector<Casilla>& tab)
{
	//Peon movimiento hacia arriba
	bool continuar = false;
	Casilla aux = *_myCasilla;

	aux = getCasilla_copia(aux, Vector2D{ (int)_color, 0 }, tab);
	validarCasilla(aux, false);

	if (_primermov)
	{
		aux = getCasilla_copia(aux, Vector2D{ (int)_color, 0 }, tab);
		validarCasilla(aux, false);
	}
	aux = getCasilla_copia(*_myCasilla, Vector2D{ (int)_color, -1 }, tab);
	validarCasilla(aux, true);

	aux = getCasilla_copia(*_myCasilla, Vector2D{ (int)_color, 1 }, tab);
	validarCasilla(aux, true);

}

void Peon::ActualizarTablero(std::vector<Casilla>& tab)
{
	Vector2D posicion{};
	for (Casilla c : _posiblesMov)
	{
		posicion = c.getPosicion();
		if (c.getComer())
		{
			tab[posicion.x + 8 * posicion.y].setAmenaza(true);
		}
	}
}

bool Peon::ActualizarPosicion(std::vector<Casilla>& tab, int indice_c)
{
	_primermov = false;
	calcularMovimiento(_myCasilla->getPosicion(), tab[indice_c].getPosicion(), 0);
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

void Peon::validarCasilla(Casilla destino, bool com)
{
	Casilla aux = destino;
	Dominio ocupacion = destino.getOcupacion();

	if (destino.getPosicion() == out_of_bounds)	return;
	else if (ocupacion == this->_color) return;
	else if (!com && ocupacion != Dominio::Vacio) return;
	else if (com && ocupacion == Dominio::Vacio) return;
	if (!com) aux.setMover(true);

	else 
	{
		aux.setMover(true);
		aux.setComer(true);
	}
	_posiblesMov.push_back(aux);

}

