#include "Pieza.h"


Pieza::Pieza(Casilla* cas, Color col, t_pieza tp) :
	_myCasilla(cas),
	_color(col),
	_t_pieza(tp),
	_pieza({ "imagenes/Peon_B.png",5 })
{
	_myCasilla->setOcupacion(static_cast<Dominio>(col));

	SelectApariencia();
	_posicion = (ETSIDI::Vector2D)(_myCasilla->getPosicion() - offset_izda) * correccion_tam;
	_pieza.setSize(2, 2);
	_pieza.setCenter(1, 1);
	if (col == Color::Blanco)
		_pieza.flip(1, 0);
}



int Pieza::getIndiceTab(int posMov, const std::vector<Casilla>& tab)
{
	return IndiceCasilla(_posiblesMov[posMov].getPosicion(), tab);
}


void Pieza::BorrarMovimiento(int movimiento)
{
	std::vector<Casilla>::iterator it = _posiblesMov.begin() + movimiento;
	_posiblesMov.erase(it);
}


void Pieza::ActualizarTablero(std::vector<Casilla>& tab)
{
	for (const Casilla& c : _posiblesMov)
	{
		Vector2D posicion = c.getPosicion();
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
		if (_posiblesMov[n].getPosicion() == pos)
			return IndiceCasilla(pos, tab);
	}
	return -1;
}
bool Pieza::ActualizarPosicion(std::vector<Casilla>& tab, int indice_c, bool sound)
{
	calcularMovimiento(_myCasilla->getPosicion(), tab[indice_c].getPosicion(), 0, sound);

	_myCasilla->setOcupacion(Dominio::Vacio);
	_myCasilla = &tab[indice_c];
	_myCasilla->setOcupacion(static_cast<Dominio>(_color));

	return false;	// devuelve falso si no es un peon que pueda coronar
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


void Pieza::mover(double t)
{
	if (distancia())
	{
		_posicion = _posicion + _velocidad * t + _aceleracion * 0.5 * t * t;
		_velocidad = _velocidad + _aceleracion * t;
	}
}
void Pieza::dibujar()
{
	_pieza.setPos(_posicion.x, _posicion.y);
	_pieza.draw();

	if (selected)
	{
		for (const Casilla& c : _posiblesMov)
		{
			c.HighlightCasilla();
		}
	}
}


Casilla Pieza::getCasilla_copia(Casilla origen, Vector2D direccion, const std::vector<Casilla>& tab)
{
	Vector2D posicion = origen.getPosicion();
	if ((posicion + direccion).out_of_bounds()) return *new Casilla({ -1,-1 });	//la casilla en la direccion indicada esta fuera del tablero

	int indice = IndiceCasilla(posicion, tab);
	if (indice == -1)  return *new Casilla({ -1,-1 });		//no existe casilla en esa posicion	
	else
	{
		indice += 8 * direccion.y + direccion.x;
		return tab.at(indice);
	}
}
Casilla* Pieza::getCasilla_ref(Casilla origen, Vector2D direccion, std::vector<Casilla>& tab)
{
	Vector2D posicion = origen.getPosicion();
	if ((posicion + direccion).out_of_bounds()) return new Casilla({ -1,-1 }); 	//la casilla en la direccion indicada esta fuera del tablero

	int indice = IndiceCasilla(posicion, tab);
	if (indice == -1)  return new Casilla({ -1,-1 });		//no existe casilla en esa posicion

	else
	{
		indice += 8 * direccion.y + direccion.x;
		return &tab.at(indice);
	}
}
bool Pieza::validarCasilla(const Casilla destino)
{
	Vector2D posicion = destino.getPosicion();
	Dominio ocupacion = destino.getOcupacion();

	if (posicion == out_of_bounds) return false;		//la posición esta fuera del tablero
	else if (ocupacion == this->_color) return false;	//la casilla en esa posición esta ocupada por una pieza aliada
	else if (p1) return false;		//ya hemos encontrado la primera pieza enemiga (no podemos atravesarla)

	Casilla aux = destino;

	if (ocupacion == Dominio::Vacio) aux.setMover(true);	//movimiento
	else //captura
	{
		aux.setMover(true);
		aux.setComer(true);
		p1 = true;
	}
	_posiblesMov.push_back(aux);
	return true;

}
int Pieza::IndiceCasilla(const Vector2D pos, const std::vector<Casilla>& tab)
{
	for (int n = 0; n < tab.size(); n++)
	{
		if (pos == tab[n].getPosicion())	return n;
	}
	return -1;
}

bool Pieza::p1 = false;


void Pieza::calcularMovimiento(Vector2D inicio, Vector2D destino, bool caida, bool sound)
{
	if (!caida)
	{
		if(sound) 		
			ETSIDI::play("sonidos/arrastrar.wav");
		
		_velocidad = static_cast<ETSIDI::Vector2D>(destino - inicio);
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
	ETSIDI::Vector2D aux = _posicion - static_cast<ETSIDI::Vector2D>(correccion_tam * (_myCasilla->getPosicion() - offset_izda));
	if (aux.module() < 0.2)
	{

		if (en_mov)
			ETSIDI::play("sonidos/poner_pieza.wav");

		_posicion = static_cast<ETSIDI::Vector2D> (correccion_tam * (_myCasilla->getPosicion() - offset_izda));
		_velocidad = { 0,0 };
		_aceleracion = { 0,0 };
		en_mov = false;
	}
	else
		en_mov = true;

	return en_mov;

}
void Pieza::SelectApariencia()
{
	std::string img;
	img.append("imagenes/");
	switch (_t_pieza)
	{
	case t_pieza::PEON:
	{
		img.append("Peon_");
		break;
	}
	case t_pieza::TORRE:
	{
		img.append("Torre_");
		break;
	}
	case t_pieza::CABALLO:
	{
		img.append("Caballo_");
		break;
	}
	case t_pieza::ALFIL:
	{
		img.append("Alfil_");
		break;
	}
	case t_pieza::REINA:
	{
		img.append("Reina_");
		break;
	}
	case t_pieza::REY:
	{
		img.append("Rey_");
		break;
	}
	default:
		break;
	}
	if (_color == Color::Blanco) img.append("B.png");
	else img.append("N.png");


	_pieza = { img.c_str(), 5 };
}


bool operator==(const Dominio& d, const Color& c)
{
	return (d == Dominio::Blanca && c == Color::Blanco || d == Dominio::Negra && c == Color::Negro);
}
bool operator!=(const Dominio& d, const Color& c)
{
	return !operator== (d, c);
}
