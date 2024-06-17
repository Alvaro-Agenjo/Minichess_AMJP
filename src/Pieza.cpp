#include "Pieza.h"

Pieza::Pieza(Casilla* cas, Color col) :
	_myCasilla(cas),
	_color(col)
{
	_myCasilla->setOcupacion(static_cast<Dominio>(col));
}

void Pieza::ActualizarTablero(std::vector<Casilla>& tab)
{
	Vector2D posicion{};
	for (Casilla c : _posiblesMov)
	{
		posicion = c.getPosicion();
		if (c.getMover())
		{
			tab[posicion.x + 8 * posicion.y].setAmenaza(true);
		}
	}
}



Casilla Pieza::getCasilla(Casilla origen, Vector2D direccion, const std::vector<Casilla> &tab)
{
	int indice = IndiceCasilla(origen, tab);
	if (indice != -1)
	{
		indice += 8 * direccion.y + direccion.x;
		if (indice >= 64)
		{
			return *new Casilla({ -1,-1 });
		}
		return tab.at(indice);
	}
	return *new Casilla({ -1,-1 });;
}

int Pieza::IndiceCasilla(const Casilla c, const std::vector<Casilla>& tab)
{
	for (int n = 0; n < tab.size(); n++)
	{
		if (c.getPosicion() == tab[n].getPosicion())
			return n;
	}
	return -1;
}

bool Pieza::validarCasilla(const Casilla destino)
{
	const Vector2D out_of_bounds = { -1,-1 };

	if (destino.getPosicion() != out_of_bounds && destino.getOcupacion() != this->_color)
	{
		Casilla aux = destino;
		if (destino.getOcupacion() == Dominio::Vacio) aux.setMover(true);
		else {
			aux.setComer(true);
			aux.setMover(true);
		}
		_posiblesMov.push_back(aux);
		return true;
	}

	return false;
}

bool operator==(const Dominio& d, const Color& c)
{
	return (d == Dominio::Blanca && c == Color::Blanco || d == Dominio::Negra && c == Color::Negro);
}

bool operator!=(const Dominio& d, const Color& c)
{
	return !operator== (d, c);
}
