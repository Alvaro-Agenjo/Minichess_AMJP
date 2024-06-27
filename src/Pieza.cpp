#include "Pieza.h"


Pieza::Pieza(Casilla* cas, Color col, t_pieza tp) :
	_myCasilla(cas),
	_color(col),
	_t_pieza(tp)
{
	_myCasilla->setOcupacion(static_cast<Dominio>(col));

	//graficos
	_posicion = (ETSIDI::Vector2D)_myCasilla->getPosicion();
	_pieza.setSize(2, 2);
	_pieza.setCenter(1, 1);
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

int Pieza::ValidarDestino(Vector2D pos, const std::vector<Casilla>& tab)
{
	for (int n = 0; n < _posiblesMov.size(); n++)
	{
		if (_posiblesMov[n].getPosicion() == pos) return IndiceCasilla(pos, tab);
	}
	return -1;
}

bool Pieza::ActualizarPosicion(std::vector<Casilla>& tab, int indice_c)
{
	calcularMovimiento(_myCasilla->getPosicion(), tab[indice_c].getPosicion(), 0);
	_myCasilla->setOcupacion(Dominio::Vacio);
	_myCasilla = &tab[indice_c];
	_myCasilla->setOcupacion(static_cast<Dominio>(_color));
	return false;
}
void Pieza::ActualizarPosicion(Casilla* c)
{
	calcularMovimiento(_myCasilla->getPosicion(), c->getPosicion());
	_myCasilla->setOcupacion(Dominio::Vacio);
	_myCasilla = c;
	_myCasilla->setOcupacion(static_cast<Dominio>(_color));
}
void Pieza::Gravedad(std::vector<Casilla>& tab)
{
	Casilla* destino = new Casilla(), * aux;
	aux = getCasilla_ref(*_myCasilla, SUR, tab);
	do {
		if (aux->getOcupacion() != Dominio::Vacio) { break; }
		destino = aux;
		aux = getCasilla_ref(*aux, SUR, tab);

	} while (!aux->getPosicion().out_of_bounds());

	if (destino->getPosicion() != out_of_bounds)
	{
		ActualizarPosicion(destino);
	}

}

bool Pieza::ComprobarJaque() const
{
	for (const Casilla c : _posiblesMov)
	{
		if (c.getOcupante()) // si tiene rey
		{

		}
	}
	return false;
}

//graficos
void Pieza::mover(double t)
{
	if (distancia())
	{
		_posicion = _posicion + _velocidad * t + _aceleracion * 0.5 * t * t;
		_velocidad = _velocidad + _aceleracion * t;
	}
}
void Pieza::calcularMovimiento(Vector2D inicio, Vector2D destino, bool caida)
{
	if (!caida)
	{

		ETSIDI::Vector2D v = static_cast<ETSIDI::Vector2D>(destino - inicio);
		_velocidad = v.unit();
		_aceleracion = { 0,0 };
	}
	else
	{
		_velocidad = { 0,0 };
		_aceleracion = { 0,-9.8 };
	}
}
bool Pieza::distancia()
{
	ETSIDI::Vector2D aux = _posicion - static_cast<ETSIDI::Vector2D>(_myCasilla->getPosicion());
	if (aux.module() < 0.005)
	{
		_posicion = static_cast<ETSIDI::Vector2D> (_myCasilla->getPosicion());
		_velocidad = {};
		_aceleracion = {};
		return false;
	}
	return true;

}

void Pieza::dibujar()
{
	glPushMatrix();
	glTranslated(_posicion.x, _posicion.y, 1);
	_pieza.draw();
	glPopMatrix();
}


//private
bool Pieza::p1 = false;

Casilla Pieza::getCasilla_copia(Casilla origen, Vector2D direccion, const std::vector<Casilla>& tab)
{
	Vector2D posicion = origen.getPosicion();
	if ((posicion + direccion).out_of_bounds()) return *new Casilla({ -1,-1 });

	int indice = IndiceCasilla(posicion, tab);
	if (indice == -1)  return *new Casilla({ -1,-1 });

	else
	{
		indice += 8 * direccion.y + direccion.x;
		return tab.at(indice);
	}
}
Casilla* Pieza::getCasilla_ref(Casilla origen, Vector2D direccion, std::vector<Casilla>& tab)
{
	Vector2D posicion = origen.getPosicion();
	if ((posicion + direccion).out_of_bounds()) return new Casilla({ -1,-1 });

	int indice = IndiceCasilla(posicion, tab);
	if (indice == -1)  return new Casilla({ -1,-1 });

	else
	{
		indice += 8 * direccion.y + direccion.x;
		return &tab.at(indice);
	}
}
int Pieza::IndiceCasilla(const Vector2D pos, const std::vector<Casilla>& tab)
{
	for (int n = 0; n < tab.size(); n++)
	{
		if (pos == tab[n].getPosicion())
			return n;
	}
	return -1;
}
bool Pieza::validarCasilla(const Casilla destino)
{
	/* pendiente de modificaci�n por jaque o pieza clavada (sin idea)*/

	Vector2D posicion = destino.getPosicion();
	Dominio ocupacion = destino.getOcupacion();

	if (posicion == out_of_bounds) return false;
	else if (ocupacion == this->_color) return false;
	else if (p1) return false;

	Casilla aux = destino;

	if (ocupacion == Dominio::Vacio) aux.setMover(true);
	else
	{
		aux.setMover(true);
		aux.setComer(true);
		p1 = true;
	}
	_posiblesMov.push_back(aux);
	return true;

}


bool operator==(const Dominio& d, const Color& c)
{
	return (d == Dominio::Blanca && c == Color::Blanco || d == Dominio::Negra && c == Color::Negro);
}
bool operator!=(const Dominio& d, const Color& c)
{
	return !operator== (d, c);
}
