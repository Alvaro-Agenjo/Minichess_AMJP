#include "Peon.h"

Peon::Peon(Casilla* coord, Color col) :
	Pieza(coord, col)
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
	aux = getCasilla_copia(*_myCasilla, Vector2D{(int)_color, -1}, tab);
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
	if (destino.getPosicion() == out_of_bounds)
		return;

	else if (destino.getOcupacion() == this->_color)
		return;

	if (!com) aux.setMover(true);
	else
	{
		aux.setMover(true);
		aux.setComer(true);
	}
	_posiblesMov.push_back(aux);	

}

